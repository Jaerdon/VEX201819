#include "main.h"
#include "posctrl.h"
#include "motorctrl.h"

float x = 0;
float y = 0;
float theta = 0;

float IN_PER_TICK = 8 * 3.14 / 392; //Inches per encoder tick.
float BASELINE = 14;   //Distance between centers of each wheel.

void trackPos(void * args) {
	while (1) {
		int ticksL, ticksR;
		imeGet(motors[MOT_BL].imeAddress, &ticksL);
		imeGet(motors[MOT_BR].imeAddress, &ticksR);

		float distL = ticksL * IN_PER_TICK;
		float distR = ticksR * IN_PER_TICK;
		float distC = (distL + distR) / 2;

		theta = (distR - distL) / BASELINE;
		x = distC * cosf(theta);
		y = distC * sinf(theta);
	}
}

float getPosX() {
	return x;
}

float getPosY() {
	return y;
}

float getAngle() {
	return theta;
}
