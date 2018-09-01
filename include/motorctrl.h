#include "API.h"

//Motor controller header file. Handles motor control "object" (because C isn't OOP) and all that jazz.
//I'll put a better description later

#ifndef MOTORCTRL_H_
#define MOTORCTRL_H_

typedef struct {
	int inverted;	//Set to true if motor needs polarity swapped without changing the wiring.

	float speed;	//Desired speed of the motor in RPM.
	float velocity; //Actual rotational velocity.
	float acceleration; //Change in rotational velocity.

	/*
	 * PID Variables
	 * I am aware that in general rotational position uses theta, rotational
	 * velocity uses omega, and rotational acceleration uses alpha. However,
	 * I didn't want to deal with those characters. Oh well.
	 */
	float errV;	//Velocity error	   (P)
	float errX;	//Position error	   (I)
	float errA;	//Acceleration error (D)

	unsigned char port;       //Cortex port (channel) the motor is connected to.
	unsigned char imeAddress; //Address of motor encoder.
} Motor393;

Motor393 motors[10]; //There are 10 motor ports, therefore 10 useable motor objects. Set these in init.c

void updateMotors(void * args);
void setMotor(int port, float speed);

Motor393 createMotor(unsigned char port, unsigned char imeAddress, bool inverted);

#endif
