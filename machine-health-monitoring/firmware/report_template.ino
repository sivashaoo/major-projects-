// Project 3 — Industrial Machine Health Monitoring and Predictive Maintenance
// Source: Sensor Interfacing Technique Report, Project 3.
// This is the report's ESP32 starter template. Existing project firmware is kept separately.

#include <OneWire.h>
#include <DallasTemperature.h>

const int VIB_PIN = 34;
const int LED_PIN = 2;
OneWire oneWire(4);
DallasTemperature tempBus(&oneWire);
const int VIB_LIMIT = 2200; // determine from baseline

void setup() {
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
  tempBus.begin();
}

void loop() {
  int vib = analogRead(VIB_PIN);
  tempBus.requestTemperatures();
  float t = tempBus.getTempCByIndex(0);
  bool alert = (vib > VIB_LIMIT || t > 65.0);
  digitalWrite(LED_PIN, alert ? HIGH : LOW);
  Serial.printf("vibration=%d temperature=%.2f C alert=%s\n",
                vib, t, alert ? "YES" : "no");
  delay(500);
}