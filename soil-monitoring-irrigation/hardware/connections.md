# Project 1 — Hardware Connections

| Component pin | Arduino Uno connection | Notes |
|---|---|---|
| Soil sensor AO | A0 | Analog moisture reading |
| Soil sensor VCC | Module-supported supply | Verify the exact module's voltage requirement |
| Soil sensor GND | GND | Common reference for low-voltage sensing |
| Relay/driver IN | D7 | Firmware assumes an active-LOW relay; verify before use |
| Relay/driver logic GND | Arduino GND | For a non-isolated low-voltage driver, follow its datasheet |

## Pump power path
Use a separate, correctly rated pump supply through the relay contacts or a suitable motor driver. Do not connect the pump to an Arduino pin or power it from the board's 5 V rail. Follow the relay/driver and pump datasheets; use suitable fuse and inductive-load protection.

## Calibration and first test
1. Keep the pump power disconnected.
2. Open Serial Monitor at 9600 baud.
3. Record A0 readings in dry soil and well-watered soil.
4. Set `DRY_THRESHOLD` and `WET_THRESHOLD` from measured values. The report's sample values (650 and 580) are not universal.
5. Verify that the relay output changes as intended. Confirm active-LOW/active-HIGH behavior before connecting the pump.

The PDF gives the above signal mapping; physical wiring and voltage compatibility must be checked against the actual sensor and driver modules.