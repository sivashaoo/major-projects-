// Project 4 — Wearable Vital-Sign and Sleep-Quality Monitoring
// Source: Sensor Interfacing Technique Report, Project 4.
// ESP32 I2C bring-up template for MAX30102 + MPU6050.
// Install the sensor libraries when adding acquisition code.
// This template checks the I2C bus only; it does not read pulse or motion data.

#include <Wire.h>

const int SDA_PIN = 21;
const int SCL_PIN = 22;

void setup() {
  Serial.begin(115200);
  Wire.begin(SDA_PIN, SCL_PIN);
  Serial.println("I2C scan starting");

  for (byte a = 1; a < 127; a++) {
    Wire.beginTransmission(a);
    if (Wire.endTransmission() == 0) {
      Serial.print("I2C device at 0x");
      Serial.println(a, HEX);
    }
  }
}

void loop() {
  delay(1000);
}