void elevator() {

	while (SensorValue[bottomLimit] != 1) {
		beltControl(BELT_SPEED);
	}

	beltControl(MOTOR_STOP);

}

int sense() {
	int  senseValue;

	//while (true) {
	for(int rounds = 5; rounds > 0; rounds--) {

		flashlightOn(true);
		warningOn(false);
		wait1Msec(SENSE_WAIT * 1000);

		if (rounds % 2 == 0) { senseValue = SensorValue[lfLeft]; }
		else { senseValue = SensorValue[lfRight]; }

		wait1Msec(500);
		flashlightOn(false);

		if (senseValue < GREEN_HI &&
			  senseValue > GREEN_LOW)  {
			 return GREEN;
		} else if (senseValue < ORANGE_HI &&
			         senseValue > ORANGE_LOW)  {
			 return ORANGE;
		} else {
			warningOn(true);
		}

	}

	// After 5 attempts, if still unknown, deflect to default.
	return CONTINGENCY;

}

void paddle(int which) {
	if (which == GREEN) {
		motor[paddleLeft]  = PADDLE_SPEED;
	}	else if (which == ORANGE) {
		motor[paddleRight] = PADDLE_SPEED;
	}
	wait1Msec(HIT_WAIT * 1000);
	stopPaddles();
}

void reset() {

	bool leftStatus = false;
	bool rightStatus = false;

	while (!leftStatus && !rightStatus) {
		stopPaddles();

		leftStatus  = (SensorValue[potentLeft]  < LEFT_OK);
		rightStatus = (SensorValue[potentRight] < RIGHT_OK);

		if (!leftStatus) { motor[paddleLeft] = RESET_SPEED;	}
		if (!rightStatus) { motor[paddleRight] = RESET_SPEED;	}
	}
}
