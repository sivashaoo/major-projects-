# MineGuard Prototype Hardware Interface Plan

This document intentionally describes **signal roles**, not final GPIO numbers. Pin assignments must be finalized after the exact controller, sensor modules and communication hardware are selected.

| Interface | Signal role |
|---|---|
| Thermal camera | Camera data/control interface |
| LiDAR | Distance data interface |
| Ultrasonic | Trigger + echo / module data interface |
| GPS | Serial position data |
| Load sensor | Analog/digital load-state input |
| Vehicle speed | Vehicle speed input or calculated state |
| Buzzer | Driver warning output |
| Display | Driver information interface |
| Wiper motor/actuator | Cleaning control output |
| Wireless/V2X | Communication interface |
| Emergency/stop control | Fail-safe output to prototype actuator |

## Electrical Design Requirements

- Use regulated supply rails appropriate for each module.
- Common-ground and signal-level compatibility must be verified.
- Add protection for inductive loads such as motors.
- Provide fuse/current protection for prototype power.
- Keep sensor wiring away from noisy motor/power wiring where practical.
- Final hardware must be validated for vibration, dust, moisture and temperature before field use.
