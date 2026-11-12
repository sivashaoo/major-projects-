# Major Projects – Electrical & Electronics Engineering

**Sivasahoo.N** · Electrical Engineering · Embedded Systems · Industrial IoT · Automation

A portfolio of larger engineering projects spanning electrical equipment monitoring, industrial safety, automation, sensor-based systems, and IoT prototypes. Each project includes concept documentation, firmware (where available), hardware notes, and clear scope statements.

---

## Featured Projects

| Project | Focus Area | Current Scope | Link |
|---------|------------|---------------|------|
| **Mine Vehicle Safety (Low Visibility)** | Industrial safety, sensing, simulation | System concept, safety logic, prototype planning, hardware notes | [Open](./mine-vehicle-safety/) |
| **Transformer Health Monitoring** | Electrical equipment monitoring | Monitoring & protection concept | [Open](./transformer-health-monitoring/) |
| **Smart Waste Segregation** | Sensors, motors, automation | Sensor-driven sorting prototype | [Open](./SMART-WASTE-SEGREGATION/) |
| **Machine Health Monitoring** | Condition monitoring | ESP32 + vibration (analog) + DS18B20 temperature + alert LED | [Open](./machine-health-monitoring/) |
| **Soil Monitoring & Automated Irrigation** | Agriculture, sensing, control | Soil-moisture starter firmware with hysteresis + wiring notes | [Open](./soil-monitoring-irrigation/) |
| **Wearable Vital-Sign & Sleep Monitoring** | Sensor interfacing | I²C bring-up template (MAX30102 / MPU6050). Current sketch scans devices only | [Open](./wearable-vital-sign-sleep-monitoring/) |
| **Sensor Failure Detection & Maintenance** | Fault detection | Generic analog threshold monitor + event counter | [Open](./sensor-failure-maintenance/) |
| **Smart Retail Inventory** | Load sensing | ESP32 + HX711 load-cell starter template | [Open](./smart-retail-inventory/) |
| **Connected Vehicle Diagnostics** | Automotive sensor demo | Bench-top DS18B20 temperature monitor with local alert (not full remote diagnostics) | [Open](./connected-vehicle-diagnostics/) |

---

## Engineering Workflow

Every project follows (or aims to follow) this process:

1. **Define the problem** — objective, inputs, outputs, constraints, and safety considerations
2. **Design the system** — sensors, controller, power, actuators, and communication
3. **Build and document** — readable firmware, pin tables, and setup instructions
4. **Test and calibrate** — record conditions, expected vs observed behaviour, and limitations
5. **Improve iteratively** — clearly separate implemented features from planned features

---

## Technologies Used

- **Embedded:** ESP32, Arduino, Embedded C/C++, sensor interfacing
- **Electrical:** Equipment monitoring concepts, protection ideas, power-system applications
- **Automation:** Relay/actuator control, threshold logic, system integration
- **IoT:** Connected monitoring concepts and simple dashboards
- **Simulation:** MATLAB/Simulink (where included in individual project folders)

---

## Documentation Standards

- Each project README should clearly state: objective, components, wiring, firmware setup, test procedure, and limitations
- Starter templates are labeled honestly and are **not** presented as verified production systems
- Hardware-dependent behaviour must be tested on real boards and modules
- Use proper isolation, fuses, current limits, and safe low-voltage setups where appropriate
- Never commit Wi-Fi passwords, API keys, tokens, or other secrets

---

## Related Work

- **Mini Projects (ESP32 / Arduino / Sensors)** → [sivashaoo/mini-projects](https://github.com/sivashaoo/mini-projects)
- **GitHub Profile** → [github.com/sivashaoo](https://github.com/sivashaoo)

---

**Project documentation is updated iteratively as implementations are developed and tested.**
