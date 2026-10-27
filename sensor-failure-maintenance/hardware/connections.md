# Project 7 — Hardware Connections

| Component | Arduino Uno connection | Notes |
|---|---|---|
| Analog sensor OUT | A0 | Sensor type is selected for the target asset |
| Sensor VCC | Sensor-supported supply | Check sensor datasheet and output range |
| Sensor GND | GND | Common reference for non-isolated low-voltage sensors |
| LED anode | D8 through current-limiting resistor | LED cathode to GND |

## Sensor selection and safety
The PDF deliberately describes a generic analog condition monitor. Select a sensor suitable for the parameter being monitored and ensure its output never exceeds the Uno ADC input range. Industrial current, pressure, and mains-related signals may require proper signal conditioning and galvanic isolation; do not connect raw industrial or mains signals directly to the board.

## Test
Open Serial Monitor at 9600 baud. Record normal readings first, then choose `WARN_LIMIT` based on calibration and applicable vendor/engineering limits. The sample value 700 is only a placeholder. The event counter increments when the signal changes from not-alert to alert; it is not stored across power cycles.