# Testing and Validation Procedure

## Bench checks
1. Verify the ESP32 supply and common ground.
2. Confirm MPU6050 I2C communication.
3. Confirm DHT22 temperature and humidity values are plausible.
4. Check TFT initialization and readability.
5. Test LED, buzzer driver, and encoder acknowledgement switch separately.

## RPM validation
1. Compare displayed RPM against a reference tachometer or a known rotation rate.
2. Confirm the encoder pulses counted per revolution.
3. Adjust PULSES_PER_REV and compare at multiple speeds.

## Threshold validation
1. Record baseline vibration with the sensor mounted securely under normal operating conditions.
2. Set warning and critical thresholds using manufacturer guidance or an appropriate engineering assessment.
3. Simulate threshold crossings safely; do not create dangerous vibration or deliberately overheat a real machine.
4. Confirm warning/critical status, LED, buzzer acknowledgement, and re-arming.

## ThingSpeak
1. Create a channel with five numeric fields.
2. Set the Write API Key locally in the firmware.
3. Confirm Wi-Fi connection and inspect field values.
4. Respect the update interval limits for your ThingSpeak account.
5. Confirm local monitoring continues without Wi-Fi.

## Limitations
The current vibration feature is only acceleration-magnitude deviation from 1 g, not a validated RMS or FFT metric. A robust version should sample at a stable rate, remove gravity/offset, and calculate features over a window. DHT22 measures ambient temperature, not winding or bearing temperature. Do not claim hardware testing is complete until these checks have actually been performed.

## Acceptance checklist
- [ ] Firmware compiles for the selected ESP32 board.
- [ ] Sensor readings are plausible and sensor failures are visible.
- [ ] RPM agrees with a reference tachometer within a documented tolerance.
- [ ] Warning and critical thresholds are validated.
- [ ] TFT, LED, buzzer, and acknowledgement behave as expected.
- [ ] ThingSpeak mapping and upload interval are verified.
- [ ] Test results and photos are recorded.