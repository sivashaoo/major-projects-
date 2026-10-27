# Project 4 — Hardware Connections

| Module | ESP32 connection | Notes |
|---|---|---|
| MAX30102 SDA | GPIO21 (SDA) | I²C data |
| MAX30102 SCL | GPIO22 (SCL) | I²C clock |
| MPU6050 SDA | GPIO21 (SDA) | Share the I²C bus |
| MPU6050 SCL | GPIO22 (SCL) | Share the I²C bus |
| Module VCC | Voltage supported by the exact breakout | Verify the breakout's regulator and logic-level compatibility |
| Module GND | ESP32 GND | Common reference |

The report identifies GPIO21/GPIO22 as common ESP32 I²C pins. The Uno alternative is SDA=A4 and SCL=A5, but the provided sketch is for ESP32.

## Bring-up
Upload `i2c_scan_report_template.ino`, open Serial Monitor at 115200 baud, and note each detected address. If no devices appear, check SDA/SCL orientation, supply, common ground and breakout documentation. Sensor addresses can vary by board configuration.

Use 3.3 V-compatible modules and confirm voltage support before connecting. The code only scans I²C; sensor data acquisition must be implemented separately.