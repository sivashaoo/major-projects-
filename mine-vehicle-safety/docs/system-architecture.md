# MineGuard System Architecture

## 1. Overview

MineGuard is a layered safety system for open-cast mine vehicles operating in fog and low visibility.

## 2. Architecture

```text
                    ┌──────────────────────┐
                    │ Environment / Weather│
                    │ Fog / Dust / Rain     │
                    └──────────┬───────────┘
                               │
 ┌──────────────┐  ┌───────────▼──────────┐  ┌──────────────┐
 │ Thermal      │  │ Sensor & Vehicle Data │  │ LiDAR        │
 │ Camera       ├─►│ Fusion Layer          │◄─┤              │
 └──────────────┘  └───────────┬──────────┘  └──────────────┘
                                │
                    ┌───────────▼───────────┐
                    │ AI Object Detection    │
                    │ Truck / Person / Rock  │
                    │ / Unknown              │
                    └───────────┬───────────┘
                                │
                    ┌───────────▼───────────┐
                    │ Collision Risk Engine  │
                    │ Distance + Motion +    │
                    │ Vehicle State + Fog    │
                    └───────────┬───────────┘
                                │
             ┌──────────────────┼─────────────────┐
             ▼                  ▼                 ▼
      Driver Warning      Speed Advisory     Fail-Safe Stop
             │                  │                 │
             └──────────────────┼─────────────────┘
                                ▼
                    ┌───────────────────────┐
                    │ Control Room / V2X    │
                    │ Event & Vehicle Data  │
                    └───────────────────────┘
```

## 3. Sensor Roles

### Thermal camera
Primary object-detection source for low-visibility operation. It is useful for detecting heat signatures when visible-light visibility is poor.

### LiDAR
Provides distance and spatial measurements. In dense fog, scattering can degrade performance, so LiDAR is treated as complementary rather than the sole safety source.

### Ultrasonic fallback
Provides a local short-range threshold check when other sensing becomes unreliable.

### GPS
Provides position, heading and mine entry/exit information.

### Vehicle/load information
Loaded and empty trucks have different braking and traffic behavior, so the safety engine uses load state.

## 4. Decision Pipeline

1. Read environment and vehicle state.
2. Read available sensors.
3. Detect/classify objects.
4. Fuse object and distance information.
5. Estimate collision risk.
6. Apply visibility and road-condition speed policy.
7. Warn the driver.
8. If required, activate local fail-safe protection.
9. Send important events to the control room.

## 5. Human-Machine Interface

The prototype provides a driver-cabin view containing relevant sensor/risk information. A control-room view provides system state and event information.

## 6. Redundancy Principle

The system is intentionally designed so that failure of one sensor does not automatically mean that the vehicle is allowed to continue at normal operating conditions. Instead, the system degrades to another sensing path or to a conservative/fail-safe state.
