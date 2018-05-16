void beltControl(float value) {
  // Set both belt motors to the same value.
	motor[beltRight] = value;
	motor[beltLeft]  = value;
}

void flashlightControl(float value) {
	// Set both flashlights to the same value.
	motor[flashlightLeft]  = value;
	motor[flashlightRight] = value;
}

void flashlightOn(bool status) {
	// Flip flashlights based on boolean status.
	if (status) { flashlightControl(LIGHT_ON); }
	else { flashlightControl(LIGHT_OFF); }
}

void warningLEDControl(int value) {
	// Set warning LEDs to the same value.
	SensorValue[warningLED1] = value;
	SensorValue[warningLED2] = value;
}

void warningOn(bool status) {
	// Flip warning LEDs based on boolean status.
	if (status) { warningLEDControl(LED_ON); }
	else { warningLEDControl(LED_OFF); }
}

void runningLEDControl(int value) {
	// Set running LEDs to the same value.
	SensorValue[runningLED1] = value;
	SensorValue[runningLED2] = value;
}

void runningOn(bool status) {
	// Flip warning LEDs based on boolean status.
	if (status) { runningLEDControl(LED_ON); }
	else { runningLEDControl(LED_OFF); }
}

void stopLEDControl(int value) {
	// Set stop LEDs to the same value.
	SensorValue[stopLED1] = value;
	SensorValue[stopLED2] = value;
}

void stopOn(bool status) {
	// Flip stop LEDs based on boolean status.
	if (status) { stopLEDControl(LED_ON); }
	else { stopLEDControl(LED_OFF); }
}
