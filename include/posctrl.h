#include "API.h"

//Position controller header file.
//I'll put a better description later

#ifndef POSCTRL_H_

#define POSCTRL_H_

float getPosX();
float getPosY();
float getAngle();

void trackPos(void * args);

#endif
