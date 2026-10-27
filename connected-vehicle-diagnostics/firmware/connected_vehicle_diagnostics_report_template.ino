// Project 10 — Connected Vehicle Performance and Remote Diagnostics
// Source: Sensor Interfacing Technique Report, Project 10.
// Arduino Uno: DS18B20 temperature monitor with fault LED.
// Bench demonstration only; not automotive-grade diagnostics.

#include <OneWire.h>
#include <DallasTemperature.h>

OneWire oneWire(2);
DallasTemperature sensors(&oneWire);

const int ALERT_LED = 8;
const float MAX_TEMP = 80.0; // bench demonstration limit only

void setup() {
  Serial.begin(9600);
  sensors.begin();
  pinMode(ALERT_LED, OUTPUT);
}

void loop() {
  sensors.requestTemperatures();
  float t = sensors.getTempCByIndex(0);

  bool valid = (t > -100.0 && t < 125.0);
  bool fault = (!valid || t > MAX_TEMP);

  digitalWrite(ALERT_LED, fault ? HIGH : LOW);

  if (valid) {
    Serial.print("temperature_C=");
    Serial.println(t);
  } else {
    Serial.println("SENSOR_FAULT");
  }

  delay(1000);
}