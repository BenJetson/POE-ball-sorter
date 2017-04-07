#ifndef CONSTANTS
#define CONSTANTS

// Constants
const int MOTOR_MAX    = 127;
const int MOTOR_STOP   = 0;
const int BELT_SPEED   = floor(MOTOR_MAX / 3);
const int PADDLE_SPEED = floor(MOTOR_MAX / 2);
const int RESET_SPEED  = floor(PADDLE_SPEED / 2);
const int RIGHT_OK     = 0;
const int LEFT_OK      = 0;
const int LIGHT_ON     = -127;
const int LIGHT_OFF    = 0;
const int LED_ON       = 1;
const int LED_OFF      = 0;
const int SENSE_WAIT   = 1;
const int GREEN_LOW    = 9999;
const int GREEN_HI     = 9999;
const int ORANGE_LOW   = 9999;
const int ORANGE_HI    = 9999;
const int GREEN        = 1;
const int ORANGE       = 2;
const int CONTINGENCY  = GREEN;
const float HIT_WAIT   = 1;

#endif
