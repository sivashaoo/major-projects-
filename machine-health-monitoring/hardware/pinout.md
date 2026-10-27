# Hardware Pinout and Wiring

These connections follow the firmware defaults. Verify the exact ESP32 board and breakout requirements before powering up.

| Module / signal | ESP32 pin | Notes |
|---|---:|---|
| MPU6050 SDA | GPIO 21 | I2C data |
| MPU6050 SCL | GPIO 22 | I2C clock |
| DHT22 DATA | GPIO 15 | Add pull-up if the module lacks one |
| Encoder CLK | GPIO 32 | Interrupt input |
| Encoder DT | GPIO 33 | Declared but not used to decode direction |
| Encoder switch | GPIO 25 | Active-low alarm acknowledgement |
| Status LED | GPIO 27 | Use a series current-limiting resistor |
| Buzzer control | GPIO 14 | Use a transistor/driver if required |
| ILI9341 CS | GPIO 5 | SPI chip select |
| ILI9341 DC | GPIO 2 | Data/command |
| ILI9341 RESET | GPIO 4 | Display reset |
| ILI9341 SCK | GPIO 18 | Default ESP32 VSPI clock |
| ILI9341 MOSI / SDI | GPIO 23 | Default ESP32 VSPI MOSI |
| ILI9341 MISO / SDO | GPIO 19 | Only if required by the module |

## Power and safety
- Connect module grounds to ESP32 ground.
- Use an ESP32-compatible 3.3 V logic display breakout and follow its power requirements.
- Do not drive a high-current buzzer directly from an ESP32 GPIO.
- Never connect ESP32 GPIO directly to mains or motor power terminals. Use suitable isolated instrumentation.
- GPIO 2 and GPIO 5 are boot-strapping pins on some ESP32 variants; choose alternate pins if boot problems occur and update the code.

## Encoder calibration
Set PULSES_PER_REV to the number of falling-edge CLK pulses counted per shaft revolution. The firmware does not currently decode direction from DT.