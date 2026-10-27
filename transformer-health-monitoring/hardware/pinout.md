# Hardware Pinout

| Component | ESP32 Pin |
|---|---:|
| DS18B20 data | GPIO 4 |
| ACS712 analog output | GPIO 34 |
| ZMPT101B analog output | GPIO 35 |
| Oil-level sensor | GPIO 32 |
| Buzzer | GPIO 25 |
| Warning LED | GPIO 26 |
| Fault LED | GPIO 27 |
| Relay | GPIO 33 |
| OLED SDA | GPIO 21 |
| OLED SCL | GPIO 22 |

## Common Connections

- Sensors and modules must share GND with the ESP32 where appropriate.
- DS18B20 requires a suitable pull-up resistor on its data line according to the sensor/module configuration.
- OLED uses I2C at the default address `0x3C` in the example firmware.
- The relay logic in the example assumes an active-low relay module.

## Safety

For demonstration, use isolated low-voltage sources. The voltage/current sensor interfaces must be correctly rated and isolated before any connection to mains or transformer circuits. Never connect hazardous voltage directly to the ESP32.