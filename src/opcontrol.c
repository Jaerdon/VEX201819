#include "main.h"
#include "posctrl.c"
#include "motorctrl.c"

void operatorControl() {
	while (1) {
		float left = 1.27f*pow(joystickGetAnalog(1, 2), 0.9f);
		float right = 1.27f*pow(joystickGetAnalog(1, 3), 0.9f);

		setMotor(MOT_BR, right);
		setMotor(MOT_BL, left);
		setMotor(MOT_FR, right);
		setMotor(MOT_FL, left);
	}
}
