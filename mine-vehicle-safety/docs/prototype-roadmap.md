# MineGuard Prototype Roadmap

## Phase 1 — Simulation

- Browser-based MineGuard simulation.
- Fog, dust and rain controls.
- Loaded/empty vehicle states.
- Traffic conflict scenarios.
- Sensor and communication failure scenarios.
- Driver and control-room views.

## Phase 2 — Hardware Prototype

- Integrate embedded controller.
- Connect thermal camera.
- Add LiDAR and ultrasonic fallback.
- Add GPS and load-state input.
- Add warning buzzer/display.
- Add wireless communication.
- Demonstrate camera cleaning/wiper mechanism.

## Phase 3 — AI

- Collect representative thermal images.
- Label truck/person/rock/unknown objects.
- Train and validate a compact detection/classification model.
- Measure precision, recall and false-alarm behavior.
- Optimize the model for the selected edge hardware.

## Phase 4 — Sensor Fusion

- Fuse thermal detection with LiDAR range.
- Add ultrasonic confirmation for short range.
- Add sensor-health/confidence logic.
- Test single-sensor failures.

## Phase 5 — Controlled Field Validation

- Test in a controlled mine-like environment first.
- Validate stopping-distance assumptions.
- Validate communication-loss response.
- Validate fog/dust/rain performance.
- Compare system alerts against human observations.

## Phase 6 — Production Readiness

- Industrial enclosure and connectors.
- Automotive/mine-rated power design.
- EMC/environmental testing.
- Functional-safety engineering.
- Cybersecurity and secure communication.
- Formal site-specific safety validation.
