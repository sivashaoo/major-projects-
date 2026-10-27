// Project 8 — Smart Retail Inventory and Customer-Experience Monitoring
// Source: Sensor Interfacing Technique Report, Project 8.
// ESP32: HX711 load-cell threshold. Install an HX711 library.

#include "HX711.h"

HX711 scale;
const int DT_PIN = 19;
const int SCK_PIN = 18;
const int LED = 2;
float EMPTY_LIMIT = 20.0; // grams; calibrate scale first

void setup() {
  Serial.begin(115200);
  scale.begin(DT_PIN, SCK_PIN);
  scale.set_scale(1.0); // replace with calibration factor
  scale.tare();
  pinMode(LED, OUTPUT);
}

void loop() {
  if (scale.is_ready()) {
    float grams = scale.get_units(5);
    bool occupied = grams > EMPTY_LIMIT;
    digitalWrite(LED, occupied ? HIGH : LOW);
    Serial.printf("weight=%.1fg occupied=%s\n",
                  grams, occupied ? "YES" : "NO");
  } else {
    Serial.println("HX711 not ready");
  }
  delay(1000);
}