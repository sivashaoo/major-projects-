# Project 4 — Wearable Vital-Sign and Sleep-Quality Monitoring

**Source:** Sensor Interfacing Technique Report, Project 4 (PDF starter template).  
**Category:** Wearable sensing / embedded systems prototype.

## Purpose
Bring up the I²C bus for a MAX30102 optical pulse-oximeter module and an MPU6050 accelerometer/gyroscope. The report's code scans for I²C devices; it does not yet read pulse or motion measurements.

## Components
- ESP32 development board
- MAX30102 module
- MPU6050 accelerometer/gyroscope
- Optional OLED
- USB power bank, enclosure and strap

## Files
- [I²C scanner firmware](firmware/i2c_scan_report_template.ino)
- [Hardware connections](hardware/connections.md)

## How to test
1. Confirm the exact breakout boards support the supply and logic voltage used.
2. Connect both modules to the ESP32 I²C bus.
3. Upload the scanner and open Serial Monitor at 115200 baud.
4. Record the detected I²C addresses and compare them with the module documentation.
5. Only after bus detection works, add the correct sensor-library acquisition code for the exact module/library versions.

## Limitations and responsible use
This is only an I²C bring-up template, not a complete pulse/sleep monitor. The project is educational and is not a medical device; it must not diagnose or rule out health conditions. Pulse accuracy and any sleep-related interpretation require appropriate validation. Protect personal data and obtain consent before collecting another person's readings.