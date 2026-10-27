# Project 10 — Hardware Connections

## Pin connections from the report's starter code

| Component | Arduino Uno connection | Notes |
|---|---|---|
| DS18B20 data (DQ) | D2 | Add a 4.7 kΩ pull-up from DQ to the sensor's compatible logic supply |
| DS18B20 VDD | Compatible sensor supply | Check the exact sensor/probe pinout |
| DS18B20 GND | GND | Common ground |
| Alert LED anode | D8 through a current-limiting resistor | LED cathode to GND |

## Test procedure
1. Disconnect all vehicle wiring; this is a bench prototype.
2. Verify the DS18B20 pinout from its datasheet or probe documentation.
3. Install the Arduino OneWire and DallasTemperature libraries.
4. Upload `connected_vehicle_diagnostics_report_template.ino`.
5. Open Serial Monitor at 9600 baud and check temperature output.
6. Confirm that the LED remains off below the configured threshold and activates above it or when a sensor fault is detected.

## Important notes
- The 80 °C threshold is a report example for a bench demonstration only.
- The sketch checks only a basic numeric range; it should be extended to handle the DS18B20 disconnected-device sentinel explicitly.
- Do not connect directly to vehicle wiring or CAN bus. Vehicle integration needs an approved interface, protection/isolation, and qualified expertise.
- The report discusses remote diagnostics broadly, but this particular code only prints locally over Serial.