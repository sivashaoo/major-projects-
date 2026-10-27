# MineGuard Prototype Test Plan

## Test Matrix

| ID | Test | Expected result |
|---|---|---|
| T01 | Normal visibility | Vehicle operates under normal policy |
| T02 | Light fog | Speed advisory decreases; detection remains active |
| T03 | Dense fog | Conservative speed and increased caution |
| T04 | Stationary truck | Early warning and collision-risk response |
| T05 | Blind corner | Hazard detected before unsafe approach |
| T06 | Communication failure | Local protection continues; fail-safe after configured timeout |
| T07 | Thermal camera failure | Cleaning/degraded logic activates |
| T08 | LiDAR degradation | Thermal/ultrasonic redundancy used; conservative policy |
| T09 | Passing lane clear | Empty truck performs one controlled lane change |
| T10 | Passing lane blocked | Empty truck reverses to clearance/waiting bay |
| T11 | Person detected | High-priority warning/horn and safe separation |
| T12 | Rock detected | Hazard warning and safe response |
| T13 | Loaded vehicle | More conservative stopping behavior |
| T14 | Empty vehicle | Empty-vehicle traffic maneuver logic |
| T15 | Rain/dirt | Reduced speed and larger safety margin |
| T16 | GPS entry/exit | Mine-zone state changes correctly |

## Demonstration Acceptance Criteria

- No repeated left/right lane oscillation.
- No vehicle merging during collision scenarios.
- A blocked passing lane results in waiting/clearance-bay behavior.
- Communication failure does not disable local safety logic.
- Sensor failure results in degraded or fail-safe behavior.
- Driver warning appears before the critical state where the configured model allows.
- Event timeline records major safety events.

## Real-World Validation Required

Before field deployment, validate sensor detection ranges, fog performance, stopping distance, braking response, road geometry, radio coverage, GPS accuracy, environmental sealing, camera contamination, human detection, false positives/negatives and the applicable mine safety requirements.
