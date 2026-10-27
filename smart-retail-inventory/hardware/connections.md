# Project 8 — Hardware Connections

| HX711 / component | ESP32 connection | Notes |
|---|---|---|
| HX711 DT/DOUT | GPIO19 | Data from HX711 |
| HX711 SCK/CLK | GPIO18 | Clock |
| HX711 VCC | Supply supported by HX711 breakout | Check module datasheet and logic levels |
| HX711 GND | ESP32 GND | Common reference |
| Load cell wires | HX711 load-cell terminals | Follow the exact amplifier/load-cell wiring diagram |
| LED anode | GPIO2 through current-limiting resistor | LED cathode to GND |

## Mechanical setup and calibration
1. Secure the load cell and platform so load is transferred in the intended direction.
2. Start with the platform empty; the code calls `tare()` at startup.
3. Apply a known weight and determine the correct scale factor.
4. Replace `scale.set_scale(1.0)` with the calibrated factor and set a realistic occupancy threshold.
5. Add and remove items and compare reported grams with a reference scale/manual count.

The report suggests GPIO19/GPIO18 for DT/SCK. Load-cell wire colors and pin labels vary; use the datasheet for your exact cell and HX711 board. Do not assume the sample scale factor or 20 g threshold is accurate without calibration.