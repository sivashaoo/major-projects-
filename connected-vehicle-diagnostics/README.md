# Project 10 — Connected Vehicle Performance and Remote Diagnostics

**Source:** Sensor Interfacing Technique Report, Project 10 (PDF starter template).  
**Application domain:** Automotive sensing.  
**Category:** Major-project collection / bench-top automotive sensing prototype.

## Purpose
Monitor a temperature sensor on a bench, flag readings outside the configured demonstration range, and report the temperature or a sensor-fault message over Serial. An LED indicates a fault.

The report explicitly excludes direct vehicle-bus access and self-driving functions from this introductory prototype. This is not automotive-grade diagnostic equipment.

## Components
- Arduino Uno
- DS18B20 temperature sensor
- 4.7 kΩ pull-up resistor between DS18B20 data and compatible logic supply
- LED and current-limiting resistor
- Breadboard and jumper wires
- Current-limited low-voltage USB/bench power

## Files
- [Firmware](firmware/connected_vehicle_diagnostics_report_template.ino)
- [Hardware connections](hardware/connections.md)

## Setup
1. Install Arduino IDE and the OneWire and DallasTemperature libraries.
2. Wire the DS18B20 data line to D2 and add the required pull-up resistor.
3. Connect the LED to D8 through a current-limiting resistor.
4. Upload the sketch and open Serial Monitor at 9600 baud.
5. Test with a known safe temperature range and controlled bench inputs.
6. Record sensor readings and fault-trigger conditions.

## Report code behavior
- Reads temperature from the DS18B20.
- Treats readings outside the basic validity range as a sensor fault.
- Turns the alert LED on if the reading is invalid or exceeds 80 °C.
- Prints the temperature or `SENSOR_FAULT` to Serial.

The 80 °C value is a bench-demonstration threshold only, not an automotive safety limit.

## Limitations and safety
This template does not implement GPS, accelerometer acquisition, timestamped fault logging, remote communication, OBD-II, or CAN-bus diagnostics. Those are broader concepts discussed in the report, not functions of this starter sketch. Do not connect the Arduino directly to vehicle wiring or CAN lines. Work on a bench; real-vehicle integration requires an approved diagnostic interface, suitable protection/isolation, and qualified guidance. Compile and test before claiming a working prototype.