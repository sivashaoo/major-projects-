# Project 3 — Connections from the PDF Starter Template

| Component | ESP32 connection | Notes |
|---|---|---|
| Analog vibration sensor OUT | GPIO34 (ADC input) | The report uses an analog vibration/accelerometer output |
| DS18B20 data | GPIO4 | Add a 4.7 kΩ pull-up between data and the sensor logic supply |
| DS18B20 VCC/GND | Compatible supply/GND | Verify the exact probe/module wiring |
| LED anode | GPIO2 through a current-limiting resistor | LED cathode to GND |

## Firmware notes
The template includes `OneWire.h` and `DallasTemperature.h`; install the corresponding Arduino libraries. Establish a normal-operation baseline before setting `VIB_LIMIT`. The 65 °C threshold is a starter value from the report, not a universal machine limit.

Mount the sensor firmly to a safe, non-rotating surface. Do not touch or wire sensors to exposed moving machinery. This threshold demo is not a safety-rated shutdown system.

This is an additional file preserving the report's starter code. The existing `machine_health_monitor.ino` in this repository remains unchanged.