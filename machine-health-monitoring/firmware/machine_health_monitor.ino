#include <WiFi.h>
#include <HTTPClient.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_ILI9341.h>
#include <Adafruit_MPU6050.h>
#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <math.h>

// Set credentials locally. Never publish a real ThingSpeak key.
const char* WIFI_SSID = "Wokwi-GUEST";
const char* WIFI_PASSWORD = "";
const char* TS_API_KEY = "YOUR_THINGSPEAK_WRITE_API_KEY";
const unsigned long TS_UPDATE_MS = 20000UL;

#define TFT_CS 5
#define TFT_DC 2
#define TFT_RST 4
#define PIN_DHT22 15
#define PIN_ENC_CLK 32
#define PIN_ENC_DT 33
#define PIN_ENC_SW 25
#define PIN_LED 27
#define PIN_BUZZER 14
#define DHTTYPE DHT22
#define PULSES_PER_REV 20 // Calibrate to your encoder

// Demonstration thresholds only; calibrate on the real machine.
float BASELINE_VIBRATION_G = 0.05f;
const float WARN_PCT = 0.15f;
const float CRIT_PCT = 0.30f;
const float ABS_MAX_VIB = 2.0f;
const float TEMP_WARN_C = 35.0f;
const float TEMP_CRIT_C = 45.0f;

Adafruit_ILI9341 tft(TFT_CS, TFT_DC, TFT_RST);
Adafruit_MPU6050 mpu;
DHT dht(PIN_DHT22, DHTTYPE);

float vibrationG = 0.0f, ambientTempC = 0.0f, humidityPct = 0.0f, rpm = 0.0f;
int healthStatus = 0; // 0 normal, 1 warning, 2 critical
bool buzzerAcked = false, mpuReady = false;
bool dhtTempValid = false, dhtHumidityValid = false;
volatile long encoderPulses = 0;
unsigned long lastRpmCalc = 0, lastRead = 0, lastUpload = 0;

void IRAM_ATTR onEncoderClk() {
  encoderPulses++;
}

void setup() {
  Serial.begin(115200);
  pinMode(PIN_LED, OUTPUT);
  pinMode(PIN_BUZZER, OUTPUT);
  pinMode(PIN_ENC_CLK, INPUT_PULLUP);
  pinMode(PIN_ENC_DT, INPUT_PULLUP);
  pinMode(PIN_ENC_SW, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(PIN_ENC_CLK), onEncoderClk, FALLING);

  Wire.begin(21, 22);
  mpuReady = mpu.begin();
  if (!mpuReady) {
    Serial.println("MPU6050 not found - check wiring");
  } else {
    mpu.setAccelerometerRange(MPU6050_RANGE_4_G);
    mpu.setFilterBandwidth(MPU6050_BAND_21_HZ);
  }
  dht.begin();

  tft.begin();
  tft.setRotation(1);
  tft.fillScreen(ILI9341_BLACK);
  tft.setTextColor(ILI9341_CYAN, ILI9341_BLACK);
  tft.setTextSize(2);
  tft.setCursor(15, 85);
  tft.println("MACHINE HEALTH");
  tft.setCursor(65, 110);
  tft.println("MONITOR");
  tft.setTextSize(1);
  tft.setCursor(10, 200);
  tft.println("Connecting WiFi...");

  WiFi.mode(WIFI_STA);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  unsigned long start = millis();
  while (WiFi.status() != WL_CONNECTED && millis() - start < 10000UL) {
    delay(300);
  }
  Serial.println(WiFi.status() == WL_CONNECTED ? "WiFi connected" :
                 "WiFi offline - local mode only");
  delay(600);
  tft.fillScreen(ILI9341_BLACK);
  lastRpmCalc = millis();
}

void loop() {
  unsigned long now = millis();
  if (now - lastRead >= 1000UL) {
    lastRead = now;
    readSensors();
    evaluateHealth();
    updateDisplay();
    driveOutputs();
  }
  if (now - lastUpload >= TS_UPDATE_MS) {
    lastUpload = now;
    uploadToThingSpeak();
  }
  handleAckButton();
}

void readSensors() {
  if (mpuReady) {
    sensors_event_t a, g, temp;
    mpu.getEvent(&a, &g, &temp);
    // Rough acceleration magnitude deviation from 1 g; not vibration RMS.
    float mag = sqrtf(a.acceleration.x * a.acceleration.x +
                      a.acceleration.y * a.acceleration.y +
                      a.acceleration.z * a.acceleration.z) / 9.80665f;
    vibrationG = fabsf(mag - 1.0f);
  }

  float h = dht.readHumidity();
  float t = dht.readTemperature();
  dhtHumidityValid = !isnan(h);
  dhtTempValid = !isnan(t);
  if (dhtHumidityValid) humidityPct = h;
  if (dhtTempValid) ambientTempC = t;

  unsigned long now = millis();
  unsigned long elapsed = now - lastRpmCalc;
  if (elapsed > 0) {
    noInterrupts();
    long pulses = encoderPulses;
    encoderPulses = 0;
    interrupts();
    rpm = (pulses * 60000.0f) / (PULSES_PER_REV * (float)elapsed);
    lastRpmCalc = now;
  }
}

void evaluateHealth() {
  float vibDevPct = 0.0f;
  if (BASELINE_VIBRATION_G > 0.0f) {
    vibDevPct = (vibrationG - BASELINE_VIBRATION_G) / BASELINE_VIBRATION_G;
  }
  int previousStatus = healthStatus;
  if (vibrationG >= ABS_MAX_VIB ||
      (dhtTempValid && ambientTempC >= TEMP_CRIT_C) ||
      vibDevPct >= CRIT_PCT) {
    healthStatus = 2;
  } else if ((dhtTempValid && ambientTempC >= TEMP_WARN_C) ||
             vibDevPct >= WARN_PCT) {
    healthStatus = 1;
  } else {
    healthStatus = 0;
  }
  if (healthStatus != previousStatus && healthStatus > 0) {
    buzzerAcked = false;
  }
}

void driveOutputs() {
  digitalWrite(PIN_LED, healthStatus == 2 ? HIGH : LOW);
  digitalWrite(PIN_BUZZER, (healthStatus == 2 && !buzzerAcked) ? HIGH : LOW);
}

void handleAckButton() {
  static unsigned long lastPress = 0;
  static bool previousPressed = false;
  bool pressed = digitalRead(PIN_ENC_SW) == LOW;
  if (pressed && !previousPressed && millis() - lastPress > 300UL) {
    buzzerAcked = true;
    lastPress = millis();
  }
  previousPressed = pressed;
}

uint16_t statusColor() {
  if (healthStatus == 2) return ILI9341_RED;
  if (healthStatus == 1) return ILI9341_ORANGE;
  return ILI9341_GREEN;
}

void updateDisplay() {
  tft.fillRect(0, 0, 320, 240, ILI9341_BLACK);
  tft.setTextColor(ILI9341_WHITE, ILI9341_BLACK);
  tft.setTextSize(1);
  int y = 16;

  tft.setCursor(15, y); tft.print("Vibration est.:");
  tft.setCursor(170, y); tft.println(String(vibrationG, 3) + " g"); y += 22;
  tft.setCursor(15, y); tft.print("Ambient temp:");
  tft.setCursor(170, y);
  if (dhtTempValid) tft.println(String(ambientTempC, 1) + " C");
  else tft.println("Sensor error");
  y += 22;
  tft.setCursor(15, y); tft.print("Humidity:");
  tft.setCursor(170, y);
  if (dhtHumidityValid) tft.println(String(humidityPct, 0) + " %");
  else tft.println("Sensor error");
  y += 22;
  tft.setCursor(15, y); tft.print("RPM:");
  tft.setCursor(170, y); tft.println(String(rpm, 0)); y += 34;

  uint16_t c = statusColor();
  tft.fillRoundRect(20, y, 280, 40, 8, c);
  tft.setTextColor(ILI9341_BLACK, c);
  tft.setTextSize(2);
  const char* label = healthStatus == 2 ? "CRITICAL" :
                      healthStatus == 1 ? "WARNING" : "NORMAL";
  tft.setCursor(90, y + 10);
  tft.println(label);
  tft.setTextSize(1);
}

void uploadToThingSpeak() {
  if (WiFi.status() != WL_CONNECTED) return;
  if (String(TS_API_KEY) == "YOUR_THINGSPEAK_WRITE_API_KEY") {
    Serial.println("Set your ThingSpeak Write API Key before uploading.");
    return;
  }
  HTTPClient http;
  String url = String("http://api.thingspeak.com/update?api_key=") + TS_API_KEY +
               "&field1=" + String(vibrationG, 3) +
               "&field2=" + String(ambientTempC, 1) +
               "&field3=" + String(humidityPct, 1) +
               "&field4=" + String(rpm, 0) +
               "&field5=" + String(healthStatus);
  http.begin(url);
  int code = http.GET();
  Serial.println("ThingSpeak upload HTTP code: " + String(code));
  if (code > 0) Serial.println("ThingSpeak response: " + http.getString());
  http.end();
}
