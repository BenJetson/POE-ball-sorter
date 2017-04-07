void beltControl(float value) {
	motor[beltRight] = value;
	motor[beltLeft]  = value;
}

void flashlightControl(float value) {
	motor[flashlightLeft]  = value;
	motor[flashlightRight] = value;
}

void flashlightOn(bool status) {
	if (status) { flashlightControl(LIGHT_ON); }
	else { flashlightControl(LIGHT_OFF); }
}

void warningLEDControl(int value) {
	SensorValue[warningLED] = value;
}

void warningOn(bool status) {
	if (status) { warningLEDControl(LED_ON); }
	else { warningLEDControl(LED_OFF); }
}

void runningLEDControl(int value) {
	SensorValue[runningLED] = value;
}

void runningOn(bool status) {
	if (status) { runningLEDControl(LED_ON); }
	else { runningLEDControl(LED_OFF); }
}

void stopPaddles() {
	motor[paddleLeft]  = 0;
	motor[paddleRight] = 0;
}
