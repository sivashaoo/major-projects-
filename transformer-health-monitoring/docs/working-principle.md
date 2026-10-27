# Working Principle

The system continuously measures important transformer parameters and evaluates their condition.

1. **Temperature sensing** – DS18B20 measures transformer temperature.
2. **Current sensing** – ACS712 provides a prototype current measurement.
3. **Voltage sensing** – ZMPT101B provides a prototype voltage measurement.
4. **Oil-level sensing** – the analog oil sensor estimates the oil level.
5. **ESP32 processing** – sensor readings are compared with warning and critical thresholds.
6. **Local indication** – OLED shows measurements and health status; LEDs and buzzer indicate warnings/faults.
7. **Protection** – a relay is activated/deactivated according to the prototype fault logic.
8. **IoT monitoring** – ESP32 sends measurements and fault information to ThingSpeak over Wi-Fi.

## System Flow

`Temperature / Current / Voltage / Oil Sensors → ESP32 → Fault Detection → Display + Alerts + Relay → ThingSpeak`

## Prototype Fault Logic

- High temperature can produce a critical shutdown condition.
- Temperature warning produces an alert without critical shutdown.
- Excess current can trigger overload/high-current protection.
- Voltage outside the configured range is treated as abnormal.
- Low oil level produces a fault condition.

The thresholds and sensor conversion equations are demonstration values and must be calibrated and validated before any real transformer application.