# Major Projects — Electrical & Electronics Engineering

This repository collects major engineering projects with firmware, hardware connections, setup notes, and testing guidance. Starter code copied from the **Sensor Interfacing Technique Report** is labeled as such; it is not claimed to be experimentally validated.

## Existing projects

### Smart Waste Segregation
Automated waste segregation using sensors and motorized sorting mechanisms.

**Folder:** [SMART-WASTE-SEGREGATION/](./SMART-WASTE-SEGREGATION/)

### Transformer Health Monitoring
An IoT-based transformer/electrical equipment monitoring and protection project.

**Folder:** [transformer-health-monitoring/](./transformer-health-monitoring/)

### Mine Vehicle Safety
A mine-vehicle safety concept for low-visibility conditions, with system architecture, safety logic, prototype planning, hardware notes, and an interactive simulation.

**Folder:** [mine-vehicle-safety/](./mine-vehicle-safety/)

### Industrial Machine Health Monitoring — Report Project 3
ESP32 starter template using an analog vibration input, DS18B20 temperature sensor, and alert LED. The original repository firmware remains separate from the PDF template.

**Folder:** [machine-health-monitoring/](./machine-health-monitoring/)

### Project 1 — Soil Monitoring and Automated Irrigation
Arduino Uno starter template with capacitive soil-moisture sensing, relay control, hysteresis, wiring notes, and calibration guidance.

**Folder:** [soil-monitoring-irrigation/](./soil-monitoring-irrigation/)

### Project 4 — Wearable Vital-Sign and Sleep-Quality Monitoring
ESP32 I²C scanner template for MAX30102 and MPU6050 module bring-up. The supplied code scans for I²C devices; it does not yet acquire pulse or motion data.

**Folder:** [wearable-vital-sign-sleep-monitoring/](./wearable-vital-sign-sleep-monitoring/)

### Project 7 — Sensor-Based Failure Detection and Maintenance Scheduling
Arduino Uno generic analog monitor with threshold alert and event counter.

**Folder:** [sensor-failure-maintenance/](./sensor-failure-maintenance/)

### Project 8 — Smart Retail Inventory and Customer-Experience Monitoring
ESP32 and HX711 load-cell starter template for shelf-load/occupancy detection.

**Folder:** [smart-retail-inventory/](./smart-retail-inventory/)

### Project 10 — Connected Vehicle Performance and Remote Diagnostics
Arduino Uno and DS18B20 bench-top temperature monitor with an alert LED. This is a local serial demonstration, not full remote diagnostics or automotive-grade equipment.

**Folder:** [connected-vehicle-diagnostics/](./connected-vehicle-diagnostics/)

## Repository layout

```text
major-projects-/
├── README.md
├── SMART-WASTE-SEGREGATION/
├── transformer-health-monitoring/
├── mine-vehicle-safety/
├── machine-health-monitoring/
├── soil-monitoring-irrigation/
├── wearable-vital-sign-sleep-monitoring/
├── sensor-failure-maintenance/
├── smart-retail-inventory/
└── connected-vehicle-diagnostics/
```

## Notes
- The sensor-interfacing project folders preserve the report's starter-code logic and document its connection guidance.
- Calibrate sensor thresholds and scale factors for the exact modules before testing.
- Compile and test each sketch with the intended hardware before claiming a working prototype.
- Use low-voltage demonstration circuits, suitable drivers, fuses, isolation, and enclosures where required.
- Keep secrets such as Wi-Fi credentials and API keys out of public commits.
- Distinguish proposed/expected results from measured results in project documentation.
