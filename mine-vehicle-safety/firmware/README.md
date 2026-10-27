# MineGuard Firmware Plan

## Main Tasks

1. Initialize sensors and communication.
2. Read vehicle/environment data.
3. Check sensor health.
4. Process object detections and distances.
5. Calculate collision risk.
6. Apply visibility-dependent speed policy.
7. Drive warning indicators.
8. Execute local fail-safe behavior when required.
9. Send status/events to the control room.
10. Log important safety events.

## Main State Machine

```text
START
  ↓
SELF TEST
  ↓
SENSOR READY? ── No ──→ DEGRADED / FAIL-SAFE
  │ Yes
  ↓
NORMAL MONITORING
  ↓
WARNING? ── Yes ──→ DRIVER ALERT
  │
  ↓
CRITICAL? ── Yes ──→ PROTECTIVE ACTION / STOP
  │ No
  ↓
COMMUNICATION HEALTH CHECK
  ↓
Repeat
```

## Communication Timeout

The prototype requirement is to enter local fail-safe behavior after approximately 10 seconds of communication loss. The vehicle must not depend on a remote operator being available for immediate protection.

## Sensor Health

The firmware should distinguish between:

- Sensor available and trusted.
- Sensor degraded.
- Sensor unavailable.
- Multiple-sensor failure.

The safety response should become more conservative as confidence decreases.

## Future Hardware Implementation

The exact controller board, GPIO assignments, communication protocol, motor/vehicle interface and safety-rated stopping interface must be selected and validated before hardware deployment.
