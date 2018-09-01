#include "main.h"
#include "posctrl.h"
#include "motorctrl.h"

/*void lift(void * args) {
	int liftHeight = 0;

	while (1) {
		if (joystickGetDigital(1, 8, JOY_UP))
			//sendLift(liftHeight, 127);
		if (joystickGetDigital(1, 8, JOY_RIGHT))
			//sendLift(liftHeight, 63);
		if (joystickGetDigital(1, 8, JOY_DOWN))
			//sendLift(liftHeight, 0);


	}
}*/

void driveTrain(void * args) {
	while (1) {
		float left = joystickGetAnalog(1, 2);
		float right = joystickGetAnalog(1, 3);

		setMotor(MOT_BR, right);
		setMotor(MOT_BL, left);
		setMotor(MOT_FR, right);
		setMotor(MOT_FL, left);
	}
}

void operatorControl() {
	//taskCreate(driveTrain, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT);
	//taskCreate(updateMotors, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT);
	//taskCreate(trackPos, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT);
	//taskCreate(lift, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT);
	while (1) {
		//Handle boring stuff here.
	}
}
