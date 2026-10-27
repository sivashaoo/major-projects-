# Project 7 — Sensor-Based Failure Detection and Maintenance Scheduling

**Source:** Sensor Interfacing Technique Report, Project 7 (PDF starter template).  
**Category:** Condition-based maintenance / industrial monitoring.

## Purpose
Monitor a sensor channel, compare the reading with a configured warning limit, switch an LED when the limit is exceeded, and count new alert events. The report intentionally leaves the exact sensor choice to the target asset.

## Components
- Arduino Uno
- One analog-output sensor relevant to the selected asset (temperature, vibration, pressure, current, or flow)
- LED and current-limiting resistor
- Optional buzzer, RTC, SD card or dashboard

## Files
- [Firmware](firmware/failure_detection_report_template.ino)
- [Connections](hardware/connections.md)

## Test procedure
1. Select a sensor and verify its output voltage is compatible with the Arduino Uno ADC.
2. Connect sensor output to A0 and LED to D8 through a resistor.
3. Open Serial Monitor at 9600 baud and capture normal readings.
4. Set `WARN_LIMIT` from calibrated readings and appropriate engineering/vendor limits.
5. Apply a safe, controlled input change and confirm the alert and event counter.

## Limitations
This template counts threshold-crossing events in volatile RAM; the count resets after power-off. It does not predict remaining useful life or automatically calculate a maintenance schedule. Thresholds must be specific to the asset and validated against real observations.