// Project 7 — Sensor-Based Failure Detection and Maintenance Scheduling
// Source: Sensor Interfacing Technique Report, Project 7.
// Arduino Uno generic analog condition monitor.

const int SENSOR = A0;
const int LED = 8;
const int WARN_LIMIT = 700; // set after calibration
unsigned long alertCount = 0;
bool wasAlert = false;

void setup() {
  Serial.begin(9600);
  pinMode(LED, OUTPUT);
}

void loop() {
  int value = analogRead(SENSOR);
  bool alert = value > WARN_LIMIT;

  if (alert && !wasAlert) alertCount++;
  wasAlert = alert;

  digitalWrite(LED, alert ? HIGH : LOW);
  Serial.print("value=");
  Serial.print(value);
  Serial.print(", alert=");
  Serial.print(alert);
  Serial.print(", alert_count=");
  Serial.println(alertCount);
  delay(500);
}