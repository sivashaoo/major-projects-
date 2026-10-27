# IoT-Based Machine Health Monitoring and Predictive Maintenance

## Overview
An ESP32 prototype that monitors vibration, ambient temperature, humidity, and rotational speed. It displays readings on an ILI9341 TFT, raises a local critical alarm, and uploads measurements to ThingSpeak when Wi-Fi is available.

**Category:** Major project. **Current method:** Rule/threshold-based condition monitoring; no trained AI model or remaining-useful-life prediction is implemented yet.

## Hardware
- ESP32 development board
- MPU6050 accelerometer/gyroscope
- DHT22 temperature and humidity sensor
- Rotary encoder coupled to the monitored shaft
- ILI9341 TFT display
- LED and buzzer

## Firmware setup
1. Install ESP32 board support in Arduino IDE.
2. Install Adafruit ILI9341, Adafruit GFX, Adafruit MPU6050, Adafruit Unified Sensor, and DHT sensor libraries.
3. Open `firmware/machine_health_monitor.ino`.
4. Set Wi-Fi credentials and a ThingSpeak Write API Key locally. Do not commit a real key to a public repository.
5. Calibrate the encoder pulses-per-revolution value and vibration thresholds.
6. Create a ThingSpeak channel with fields: Field 1 vibration estimate (g), Field 2 temperature (°C), Field 3 humidity (%), Field 4 RPM, Field 5 status (0 normal, 1 warning, 2 critical).

## Status logic
- **NORMAL:** values remain below configured thresholds.
- **WARNING:** temperature or vibration deviation reaches its warning threshold.
- **CRITICAL:** temperature reaches the critical threshold, vibration estimate reaches its absolute limit, or vibration deviation reaches its critical threshold. LED turns on and buzzer sounds until acknowledged.

Thresholds are demonstration starting points, not universal machine-safety limits. Establish a baseline and safe limits for the actual machine.

## Important limitations
- The current MPU6050 calculation is acceleration-magnitude deviation from 1 g. It is not a validated vibration RMS/FFT measurement and can be affected by orientation, gravity, mounting, and motion. For robust condition monitoring, sample at a stable rate, remove gravity/offset, and calculate RMS and/or frequency-domain features over a window.
- DHT22 measures ambient air conditions, not internal winding or bearing temperature.
- RPM depends on correct encoder calibration.
- Wi-Fi upload is best-effort; local display and alarms should work independently.
- Test on a low-voltage bench setup. Never connect ESP32 GPIO directly to mains or industrial motor power circuits.

## Project files
- [Firmware](firmware/machine_health_monitor.ino)
- [Hardware pinout](hardware/pinout.md)
- [Testing procedure](docs/testing-procedure.md)

Compile and test the firmware/hardware before claiming a working demonstration.