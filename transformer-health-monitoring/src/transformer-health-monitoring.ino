#include <Wire.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <OneWire.h>
#include <DallasTemperature.h>

// ---------------- Wi-Fi / ThingSpeak ----------------
const char* WIFI_SSID = "YOUR_WIFI_NAME";
const char* WIFI_PASSWORD = "YOUR_WIFI_PASSWORD";
const char* THINGSPEAK_API_KEY = "YOUR_WRITE_API_KEY";
const char* THINGSPEAK_URL = "http://api.thingspeak.com/update";

// ---------------- Pins ----------------
#define TEMP_PIN 4
#define CURRENT_PIN 34
#define VOLTAGE_PIN 35
#define OIL_PIN 32
#define BUZZER_PIN 25
#define WARNING_LED 26
#define FAULT_LED 27
#define RELAY_PIN 33
#define OLED_SDA 21
#define OLED_SCL 22

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

OneWire oneWire(TEMP_PIN);
DallasTemperature tempSensor(&oneWire);
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

// ---------------- Prototype thresholds ----------------
const float TEMP_WARNING = 60.0;
const float TEMP_CRITICAL = 75.0;
const float CURRENT_WARNING = 4.0;
const float CURRENT_CRITICAL = 5.0;
const float VOLTAGE_LOW = 200.0;
const float VOLTAGE_HIGH = 250.0;
const float OIL_LOW = 30.0;

unsigned long lastUpload = 0;
const unsigned long UPLOAD_INTERVAL = 20000;

float readCurrent() {
  // Prototype conversion. Calibrate for the exact ACS712 module.
  int raw = analogRead(CURRENT_PIN);
  float voltage = (raw / 4095.0) * 3.3;
  return abs((voltage - 1.65) / 0.100);
}

float readVoltage() {
  // Prototype conversion. Calibrate for the exact ZMPT101B module.
  int raw = analogRead(VOLTAGE_PIN);
  float sensorVoltage = (raw / 4095.0) * 3.3;
  return sensorVoltage * 100.0;
}

float readOilLevel() {
  int raw = analogRead(OIL_PIN);
  return (raw / 4095.0) * 100.0;
}

int analyzeFault(float temperature, float current, float voltage, float oil) {
  if (temperature >= TEMP_CRITICAL) return 1;
  if (temperature >= TEMP_WARNING) return 2;
  if (current >= CURRENT_CRITICAL) return 3;
  if (current >= CURRENT_WARNING) return 4;
  if (voltage < VOLTAGE_LOW || voltage > VOLTAGE_HIGH) return 5;
  if (oil < OIL_LOW) return 6;
  return 0;
}

String faultText(int code) {
  switch (code) {
    case 1: return "HIGH TEMP";
    case 2: return "TEMP WARN";
    case 3: return "OVERLOAD";
    case 4: return "HIGH CURRENT";
    case 5: return "BAD VOLTAGE";
    case 6: return "LOW OIL";
    default: return "HEALTHY";
  }
}

void updateOutputs(int fault) {
  bool critical = (fault == 1 || fault == 3 || fault == 4 || fault == 5 || fault == 6);
  bool warning = (fault == 2);

  digitalWrite(FAULT_LED, critical ? HIGH : LOW);
  digitalWrite(WARNING_LED, warning ? HIGH : LOW);
  digitalWrite(RELAY_PIN, critical ? LOW : HIGH); // Assumes active-low relay protection.

  if (critical || warning) {
    digitalWrite(BUZZER_PIN, HIGH);
  } else {
    digitalWrite(BUZZER_PIN, LOW);
  }
}

void showOLED(float temperature, float current, float voltage, float oil, int fault) {
  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0, 0);
  display.print("Transformer Monitor");
  display.setCursor(0, 12);
  display.printf("T: %.1f C  I: %.2f A", temperature, current);
  display.setCursor(0, 24);
  display.printf("V: %.1f V  Oil: %.0f%%", voltage, oil);
  display.setCursor(0, 38);
  display.print("Status: ");
  display.print(faultText(fault));
  display.setCursor(0, 52);
  display.print(fault == 0 ? "Protection: NORMAL" : "Protection: ACTIVE");
  display.display();
}

void connectWiFi() {
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Connecting to Wi-Fi");
  unsigned long start = millis();
  while (WiFi.status() != WL_CONNECTED && millis() - start < 15000) {
    delay(500);
    Serial.print(".");
  }
  Serial.println();
  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("Wi-Fi connected.");
  } else {
    Serial.println("Wi-Fi connection failed.");
  }
}

void uploadThingSpeak(float temperature, float current, float voltage, float oil, int fault) {
  if (WiFi.status() != WL_CONNECTED) return;

  HTTPClient http;
  String url = String(THINGSPEAK_URL) +
               "?api_key=" + THINGSPEAK_API_KEY +
               "&field1=" + String(temperature, 2) +
               "&field2=" + String(current, 2) +
               "&field3=" + String(voltage, 2) +
               "&field4=" + String(oil, 2) +
               "&field5=" + String(fault == 0 ? 1 : 0) +
               "&field6=" + String(fault);

  http.begin(url);
  int response = http.GET();
  Serial.print("ThingSpeak response: ");
  Serial.println(response);
  http.end();
}

void setup() {
  Serial.begin(115200);
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(WARNING_LED, OUTPUT);
  pinMode(FAULT_LED, OUTPUT);
  pinMode(RELAY_PIN, OUTPUT);

  Wire.begin(OLED_SDA, OLED_SCL);
  tempSensor.begin();

  if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println("OLED initialization failed!");
  }

  digitalWrite(RELAY_PIN, HIGH);
  connectWiFi();
}

void loop() {
  tempSensor.requestTemperatures();
  float temperature = tempSensor.getTempCByIndex(0);
  if (temperature == DEVICE_DISCONNECTED_C) temperature = 0;

  float current = readCurrent();
  float voltage = readVoltage();
  float oil = readOilLevel();
  int fault = analyzeFault(temperature, current, voltage, oil);

  updateOutputs(fault);
  showOLED(temperature, current, voltage, oil, fault);

  Serial.printf("T=%.2f C, I=%.2f A, V=%.2f V, Oil=%.1f%%, Fault=%d (%s)\n",
                temperature, current, voltage, oil, fault, faultText(fault).c_str());

  if (millis() - lastUpload >= UPLOAD_INTERVAL) {
    lastUpload = millis();
    uploadThingSpeak(temperature, current, voltage, oil, fault);
  }

  delay(1000);
}
