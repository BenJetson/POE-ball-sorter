void reset() {
	// Reset both paddles to their home position.
	motor[paddleLeft]  = PADDLE_HOME;
	motor[paddleRight] = PADDLE_HOME;
	writeDebugStreamLine("Paddles reset!");
}

void elevator() {

	// Waits for bottom bump switch to be pressed,
  //   then stops the belt and returns nothing.

	writeDebugStreamLine("Elevator enabled and waiting for ball.");
	while (SensorValue[bottomLimit] != 1) {
		beltControl(BELT_SPEED);
	}

	beltControl(MOTOR_STOP);
	writeDebugStreamLine("Ball detected in sensory area.");

	wait1Msec(RVS_WAIT * 1000);
	writeDebugStreamLine("REVERSING to release pressure.");
	beltControl(RV_BELT_SPEED);
	wait1Msec(RVS_TIME * 1000);
	beltControl(MOTOR_STOP);
	writeDebugStreamLine("ELEVATOR DISABLED.");


}

int sense() {

	// Attempts to determine whether ball in sensory
	//   mechanism is orange or green, then returns
  //   the results.

	int  senseValue;

	//while (true) {
	for(int rounds = 0;rounds < MAX_ATTEMPTS ;rounds++) {

		// Reset LEDs.
		flashlightOn(true);
		warningOn(false);

		writeDebugStreamLine("Detection initiated. Waiting to settle.");
		writeDebugStreamLine("This is attempt %d of 5.", rounds+1);
		wait1Msec(SENSE_WAIT * 1000); // Wait for bals to come to rest.

		//Disabled because no 2 line followers give the same reading
		// Alternate line follower use based on attempt #.
		//if (rounds % 2 == 0) { senseValue = SensorValue[lfLeft]; }
		//else { senseValue = SensorValue[lfRight]; }

		// Just use light sensor.
		senseValue=SensorValue[light];

		writeDebugStreamLine("Detection complete. Sample collected.");
		wait1Msec(500);
		flashlightOn(false);

		if (senseValue < GREEN_HI &&
			  senseValue > GREEN_LOW)  {
			 	writeDebugStreamLine("GREEN DETECTED");
			  return GREEN;
		} else if (senseValue < ORANGE_HI &&
			         senseValue > ORANGE_LOW)  {
			 	writeDebugStreamLine("ORANGE DETECTED");
			  return ORANGE;
		} else {
			// If indeterminate...
			writeDebugStreamLine("Detection failed. Will retry after delay.");

			warningOn(true);                 // Enable warning LED
			wait1Msec(WARNING_DELAY * 1000); // then wait
			writeDebugStreamLine("Continuing.");
		}

	}

	// After MAX_ATTEMPTS, if still unknown, deflect to default.
	writeDebugStreamLine("Detection failed permanently. Contingency used.");
	return CONTINGENCY;

}

void paddle(int which) {

	// Accepts an argument of the color integer,
  //   and enables the appropriate paddle servo.
  //   Then waits the set period and returns nothing.

	if (which == GREEN) {
		// Hit green ball with left paddle.
		writeDebugStreamLine("Green paddle!");
		motor[paddleLeft]  = PADDLE_MAX;
	}	else if (which == ORANGE) {
		// Hit orange ball with right paddle.
		writeDebugStreamLine("Orange paddle!");
		motor[paddleRight] = PADDLE_MAX;
	}

	wait1Msec(1000*HIT_WAIT); // Delay after hitting balls.

}

void stopMachine() {
	writeDebugStreamLine("EMERGENCY STOP!");

	// Set LEDs
	warningOn(false);
	runningOn(false);
	stopOn(true);

	// Stop the machine permanently.
	stopAllTasks();
}
