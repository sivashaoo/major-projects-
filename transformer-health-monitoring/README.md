# ⚡ IoT-Based Transformer Health Monitoring and Protection System

An ESP32-based prototype for real-time transformer condition monitoring, fault detection, alerts, and automatic protection. Sensor data is displayed locally and uploaded to ThingSpeak for remote monitoring.

## Features

- 🌡️ Transformer temperature monitoring
- ⚡ Current and voltage monitoring
- 🛢️ Oil-level monitoring
- 📟 OLED local display
- ☁️ ThingSpeak IoT cloud monitoring
- 🚨 Fault detection and warning alerts
- 🔔 Buzzer and LED indication
- 🔌 Relay-based prototype protection
- 📡 Wi-Fi connectivity using ESP32

## Hardware

- ESP32
- DS18B20 temperature sensor
- ACS712 current sensor
- ZMPT101B voltage sensor
- Oil-level sensor
- 0.96-inch I2C OLED
- Buzzer
- Warning LED
- Fault LED
- Relay module

## ThingSpeak Fields

| Field | Parameter |
|---|---|
| 1 | Temperature (°C) |
| 2 | Current (A) |
| 3 | Voltage (V) |
| 4 | Oil Level (%) |
| 5 | Health Status |
| 6 | Fault Code |

## Fault Codes

| Code | Meaning |
|---:|---|
| 0 | No fault |
| 1 | High temperature |
| 2 | Temperature warning |
| 3 | Overload |
| 4 | High current |
| 5 | Abnormal voltage |
| 6 | Low oil level |

## Project Flow

`Sensors → ESP32 → Fault Analysis → OLED / Buzzer / Relay → Wi-Fi → ThingSpeak`

## Repository Structure

```text
transformer-health-monitoring/
├── README.md
├── src/
│   └── transformer-health-monitoring.ino
├── hardware/
│   └── pinout.md
└── docs/
    └── working-principle.md
```

## Important Safety Note

This is an educational prototype, not a certified transformer protection system. The ACS712 and ZMPT101B readings require calibration for the exact modules used. Do not connect the ESP32 or prototype sensors directly to hazardous mains voltage. Use properly isolated, low-voltage test sources during development.
