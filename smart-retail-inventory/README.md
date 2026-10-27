# Project 8 — Smart Retail Inventory and Customer-Experience Monitoring

**Source:** Sensor Interfacing Technique Report, Project 8 (PDF starter template).  
**Category:** Retail automation / inventory sensing.

## Purpose
Use a load cell and HX711 amplifier to measure shelf load, classify a shelf position as occupied or empty, and turn on a status LED when the measured load is above a threshold.

## Components
- ESP32 development board
- Load cell and HX711 amplifier module
- LED and current-limiting resistor
- Stable compatible supply and shelf/platform fixture
- Optional Wi-Fi dashboard

## Files
- [Firmware](firmware/retail_inventory_report_template.ino)
- [Hardware connections](hardware/connections.md)

## Setup
1. Install an Arduino-compatible HX711 library.
2. Connect DT to GPIO19 and SCK to GPIO18; connect the LED to GPIO2 through a resistor.
3. Mechanically mount the load cell so the shelf/platform load transfers correctly.
4. Upload the code and open Serial Monitor at 115200 baud.
5. Calibrate the scale with known weights and replace `set_scale(1.0)` with the measured calibration factor.
6. Set the occupancy threshold for the actual products and compare estimates with manual counts.

## Limitations
The report's code is a starter template. Weight sensing alone cannot identify an SKU or reliably infer quantity for products of different masses. The sample calibration factor and 20 g threshold are not universal. No dashboard is implemented in this template.

## Privacy
This sensor-only demonstration does not require customer identification. Avoid collecting identifiable customer data unless necessary and appropriately consented.