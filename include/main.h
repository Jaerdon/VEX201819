#ifndef MAIN_H_

#define MAIN_H_

#include <API.h>
#include "math.h"

#ifdef __cplusplus
extern "C" {
#endif

//Motors
#define MOT_BR 1
#define MOT_BL 2
#define MOT_FR 3
#define MOT_FL 4
#define MOT_LIFT 5

//IMEs
#define IME_BR 0
#define IME_BL 1
#define IME_FR -1
#define IME_FL -1
#define IME_LIFT -1
#define NUMBER_OF_IME 2

//Autonomous Setup
#define POS_LSB 1
#define POS_MSB 2

void autonomous();
void initializeIO();
void initialize();
void operatorControl();

#ifdef __cplusplus
}
#endif

#endif
