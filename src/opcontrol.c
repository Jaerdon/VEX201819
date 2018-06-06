#include "main.h"
#include "poscontrol.c"

void operatorControl() {
	taskCreate(trackPos, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT);
	while (1) {
		delay(20);
	}
}
