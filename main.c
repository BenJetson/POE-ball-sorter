#pragma config(Sensor, in1,    lfLeft,         sensorLineFollower)
#pragma config(Sensor, in2,    light,          sensorReflection)
#pragma config(Sensor, in5,    lfMid,          sensorLineFollower)
#pragma config(Sensor, in8,    lfRight,        sensorLineFollower)
#pragma config(Sensor, dgtl1,  stopBump,       sensorTouch)
#pragma config(Sensor, dgtl2,  bottomLimit,    sensorTouch)
#pragma config(Sensor, dgtl7,  warningLED1,    sensorLEDtoVCC)
#pragma config(Sensor, dgtl8,  warningLED2,    sensorLEDtoVCC)
#pragma config(Sensor, dgtl9,  stopLED1,       sensorLEDtoVCC)
#pragma config(Sensor, dgtl10, stopLED2,       sensorLEDtoVCC)
#pragma config(Sensor, dgtl11, runningLED1,    sensorLEDtoVCC)
#pragma config(Sensor, dgtl12, runningLED2,    sensorLEDtoVCC)
#pragma config(Motor,  port1,           flashlightLeft, tmotorVexFlashlight, openLoop, reversed)
#pragma config(Motor,  port2,           beltLeft,      tmotorVex393_MC29, openLoop, reversed)
#pragma config(Motor,  port3,           paddleLeft,    tmotorServoStandard, openLoop)
#pragma config(Motor,  port8,           paddleRight,   tmotorServoStandard, openLoop)
#pragma config(Motor,  port9,           beltRight,     tmotorVex393_MC29, openLoop)
#pragma config(Motor,  port10,          flashlightRight, tmotorVexFlashlight, openLoop, reversed)
//*!!Code automatically generated by 'ROBOTC' configuration wizard               !!*//

#include "constants.c";      // Import constants file.
#include "basic-control.c";  // Import basic control methods.
#include "behaviors.c";      // Import advanced control methods.

task haltDetection() {
	// Task that endlessly loops and checks
  //   if the EMERGENCY STOP button has
  //   been pressed.

	while (true) {
		if (SensorValue[stopBump] == 1) {
			stopMachine();
		}
	}
}

task main() {
	// Initialization
	startTask(haltDetection);
	int detected;
	reset();

	// Set LEDs and wait the startup delay.
	runningOn(true);
	warningOn(true);
	stopOn(false);
	wait1Msec(STARTUP_DELAY * 1000);
	warningOn(false);

	writeDebugStreamLine("STARTING!");

	// If a ball is already in the sensory area,
	//   stop the machine from starting up.
	if (SensorValue[bottomLimit] == 1) {
		writeDebugStreamLine("ERROR! Machine cannot be started with ball in sensory area.");
		stopMachine();
	}

	while (true) {        // Will loop until forced to exit.
		reset();            // Reset paddles.
		elevator();         // Start elevator and wait for balls.
		detected = sense(); // Discern the color of ball and store it.
		reset();            // Reset paddles.
		paddle(detected);   // Pass color of ball, then hit with paddle.
	}

}
