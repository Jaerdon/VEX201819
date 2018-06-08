#include "main.h"
#include "motorctrl.h"


static Motor393 motors[10]; //There are 10 motor ports, therefore 10 useable motor objects. Set these in init.c

//These values are based on the Ziegler–Nichols method. They need to be fined tuned in the future.
static float Kp = 75.6f;
static float Ki = 7560.0f;
static float Kd = 0.189f;

static void updateMotors() {
  for (int i = 0; i < 10; i++) {
  	//Get values for each motor
  	int w = 0;
  	imeGetVelocity(motors[i].imeAddress, &w); 
  	float v = (float)w / 30.056;
  	motor[i].acceleration = v - motor[i].velocity;
  	motor[i].velocity = v;

  	//Adjust motor using PID control
  	float error = motor[i].speed - v;
  	if (error != 0) {
	  	motor[i].errA = motor[i].errV - error;
	  	motor[i].errX += error;
	  	motor[i].errV = error;

	  	//Actually sets the value.
	  	//One small issue I expect with this is the robot sliding: One might counter this with some max acceleration.
	  	motorSet(motor[i].port, Kp*error + Ki*motor[i].errX + Kd*motor[i].errA);
  	}
  }
}

static void setMotor(int port, float speed) {
	motor[port - 1].speed = speed;
}