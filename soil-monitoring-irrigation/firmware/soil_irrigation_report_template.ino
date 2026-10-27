// Project 1 — Real-Time Soil Monitoring and Automated Irrigation Control
// Source: Sensor Interfacing Technique Report, Project 1.
// Arduino Uno example: capacitive sensor + relay module.
// Starting template: calibrate thresholds and verify relay polarity.

const int MOISTURE_PIN = A0;
const int RELAY_PIN = 7;
const int DRY_THRESHOLD = 650; // calibrate for your sensor
const int WET_THRESHOLD = 580; // hysteresis; calibrate
bool watering = false;

void setup() {
  Serial.begin(9600);
  pinMode(RELAY_PIN, OUTPUT);
  digitalWrite(RELAY_PIN, HIGH); // assumes active-LOW relay; verify module
}

void loop() {
  int raw = analogRead(MOISTURE_PIN);
  Serial.print("Moisture raw: ");
  Serial.println(raw);

  if (!watering && raw >= DRY_THRESHOLD) watering = true;
  if (watering && raw <= WET_THRESHOLD) watering = false;

  digitalWrite(RELAY_PIN, watering ? LOW : HIGH);
  Serial.println(watering ? "IRRIGATION REQUESTED" : "SOIL OK");
  delay(1000);
}