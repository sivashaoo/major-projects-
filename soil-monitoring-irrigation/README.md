# Project 1 — Real-Time Soil Monitoring and Automated Irrigation Control

**Source:** Sensor Interfacing Technique Report, Project 1 (PDF starter template).  
**Category:** Major-project collection / smart agriculture prototype.

## Purpose
Read a capacitive soil-moisture sensor and request irrigation when the soil is dry. The code uses a dry threshold and a wet threshold (hysteresis) to reduce rapid relay switching.

## Components
- Arduino Uno
- Capacitive soil-moisture sensor
- 5 V relay module or correctly rated logic-level MOSFET driver
- Low-voltage DC pump and separate pump supply
- Jumper wires
- Optional DHT22 and LCD

## Files
- [Firmware](firmware/soil_irrigation_report_template.ino)
- [Connections](hardware/connections.md)

## Setup
1. Install Arduino IDE and select Arduino Uno.
2. Connect the sensor output to A0 and driver input to D7 as described in the connection notes.
3. Upload the starter sketch and open Serial Monitor at 9600 baud.
4. Measure readings in dry and wet soil; calibrate `DRY_THRESHOLD` and `WET_THRESHOLD`.
5. Test relay logic with the pump disconnected or a safe low-voltage indicator before connecting the pump.

## Important limitations
This is the report's starter program, not a complete field-ready irrigation controller. It does not implement the report's suggested minimum pump-run timing or sensor-disconnect validation. Add these before unattended use. Expected results are not experimentally verified.

## Safety
Never power a pump from a microcontroller GPIO. Use a driver/relay rated for startup current, a separate supply, suitable protection and safe electrical separation. Add a water-level interlock and dry-run protection before practical use.