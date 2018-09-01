#include "main.h"
#include "motorctrl.h"

//These values are based on the Ziegler–Nichols method. They need to be fined tuned in the future.
static float K_P = 75.6f;
static float K_I = 7560.0f;
static float K_D = 0.189f;

void updateMotors(void * args) {
	while (1) {
		for (int i = 0; i < 2; i++) {
			if (motors[i].imeAddress != -1) {
				//Get values for each motor
				int w = 0;
				imeGetVelocity(motors[i].imeAddress, &w);
				float v = (float)w / 30.056;
				motors[i].acceleration = v - motors[i].velocity;
				motors[i].velocity = v;

				//Adjust motor using PID control
				float error = motors[i].speed - v;
				if (error != 0) {
					motors[i].errA = motors[i].errV - error;
					motors[i].errX += error;
					motors[i].errV = error;

					//Actually sets the value.
					//One small issue I expect with this is the robot sliding: One might counter this with some max acceleration.
					motorSet(motors[i].port, motorGet(motors[i].port) + (K_P*error + K_I*motors[i].errX + K_D*motors[i].errA)*motors[i].inverted);
				}
			}
		}
	}
}

void setMotor(int port, float speed) {
	motors[port - 1].speed = speed;
}

Motor393 createMotor(unsigned char port, unsigned char imeAddress, bool inverted) {
	Motor393 motor;
	motor.port = port;
	motor.imeAddress = imeAddress;
	motor.inverted = inverted ? -1 : 1;

	if (imeAddress != -1) imeReset(imeAddress);

	return motor;
}
