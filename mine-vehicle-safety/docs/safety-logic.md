# MineGuard Safety Logic

## Operating States

- SAFE: normal operation when risk is low.
- WARNING: increased risk; driver receives warning and speed guidance.
- CRITICAL: immediate hazard; protective action is required.
- DEGRADED: one or more sensing/communication functions are unavailable.
- FAIL-SAFE: system cannot guarantee normal safe operation and commands the appropriate conservative response.

## Visibility Policy

| Condition | Prototype target speed |
|---|---:|
| Clear/normal | 45 km/h policy limit |
| Light fog | 30 km/h |
| Dense fog | 18 km/h |
| Sensor-degraded | 15 km/h |

For the traffic-passing demonstration, the project also uses a 25 km/h normal operating example and approximately 15 km/h for dirt/rain conditions. These are prototype values, not production mine speed limits.

## Collision Risk Inputs

The risk engine considers:

- Object distance.
- Relative movement.
- Vehicle speed.
- Loaded/empty state.
- Visibility.
- Road condition.
- Sensor health.
- Safety buffer.
- Communication state.

## Traffic Conflict Logic

1. Detect a slower/loaded vehicle ahead.
2. Determine whether the passing lane is clear.
3. If clear, command a controlled lane change.
4. Do not repeatedly toggle lanes.
5. After adequate separation, return to the main lane.
6. If the passing lane is blocked, reverse toward the designated clearance bay and wait.
7. Resume only when the conflict is cleared.

## Pedestrian Logic

A detected person is treated as a high-priority object. The prototype can issue a horn/warning when a person enters the configured detection range. The vehicle must maintain a conservative separation distance.

## Rock/Hazard Logic

Rocks and unknown objects are treated as hazards. The system should not interpret a temporary sensor fluctuation as permission to accelerate through an uncertain hazard.

## Communication Failure

The local safety function must not depend completely on the control room. When communication is lost:

- Continue local sensing and risk assessment.
- Start the communication-failure timer.
- Apply the configured degraded operating policy.
- At approximately 10 seconds without communication, activate the prototype fail-safe behavior.
- Loaded vehicle: automatic stop.
- If a local traffic maneuver is unsafe, stop/wait rather than force the maneuver.

## Sensor Failure

### Thermal failure
Attempt the camera-cleaning/wiper action. If the thermal signal remains unavailable, enter degraded/fail-safe behavior.

### LiDAR degradation
Reduce confidence in LiDAR-derived information and use available thermal/ultrasonic information. Apply a conservative speed policy.

### Multiple-sensor failure
If the remaining sensors cannot provide sufficient confidence for safe operation, stop the vehicle.

## Safety Principle

**Unknown condition → conservative response.**

The prototype should never convert missing or unreliable sensor information into a false SAFE state.
