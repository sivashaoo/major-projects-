# MineGuard Prototype Bill of Materials

| Item | Purpose | Prototype note |
|---|---|---|
| Embedded controller | Main control/processing | Raspberry Pi Pico or suitable board |
| Thermal camera | Low-visibility object detection | Primary detection path |
| LiDAR | Distance/spatial sensing | Complementary sensor |
| Ultrasonic sensor | Short-range fallback | Threshold/backup detection |
| GPS module | Position and heading | Mine entry/exit and tracking |
| Load sensor/interface | Loaded/empty state | Vehicle load information |
| Wireless module | Vehicle/control-room communication | Depends on selected network |
| Buzzer/indicator | Driver warning | Local alert |
| Display | Driver information | Cabin status/risk display |
| Wiper/cleaning mechanism | Thermal camera cleaning | Prototype contamination response |
| Power regulation/protection | Stable supply | Must be sized for actual hardware |

## Early Cost Direction

The prototype discussion used approximate example values of ₹4,000 for a thermal camera, ₹3,000 for LiDAR and ₹3,000 for the controller, with a rough overall prototype target around ₹15,000. These values are planning estimates only and should be replaced with actual purchase quotations.

## Selection Criteria

- Low cost.
- Easy maintenance.
- Suitable sensing range.
- Low-visibility performance.
- Low power consumption where practical.
- Easy integration with the selected controller.
- Availability of replacement parts.
- Appropriate environmental protection for the intended test environment.
