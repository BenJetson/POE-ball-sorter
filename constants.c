#ifndef CONSTANTS
#define CONSTANTS

// Constants

// Basic Values & Base Units
const int MOTOR_MAX     = 127;
const int MOTOR_STOP    = 0;
const int LIGHT_ON      = -127;
const int LIGHT_OFF     = 0;
const int LED_ON        = 1;
const int LED_OFF       = 0;

// Speeds & Servo Values
const int BELT_SPEED    = floor(MOTOR_MAX / 4);
const int RV_BELT_SPEED = - floor(MOTOR_MAX / 3);
const int PADDLE_HOME   = 127;
const int PADDLE_MAX    = -127;

// Delays
const int SENSE_WAIT    = 2;
const int HIT_WAIT    = 1;
const int WARNING_DELAY = 2;
const int STARTUP_DELAY = 1;
const int RVS_WAIT      = 0.5;
const int RVS_TIME      = 1;

// Detection values
const int GREEN         = 1;
const int ORANGE        = 2;
const int CONTINGENCY   = GREEN;
const int MAX_ATTEMPTS  = 3;

// Sensory margins
const int GREEN_LOW     = 50;
const int GREEN_HI      = 150;
const int ORANGE_LOW    = 151;
const int ORANGE_HI     = 250;


#endif
