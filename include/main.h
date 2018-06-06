#ifndef MAIN_H_

#define MAIN_H_

#include <API.h>

#ifdef __cplusplus
extern "C" {
#endif

//Motors
#define MOT_BR '1';
#define MOT_BL '2';
#define MOT_FR '3';
#define MOT_FL '4';

//IMEs
#define IME_UR 0
#define IME_UL 1
#define IME_BR 2
#define IME_BL 3
#define NUMBER_OF_IME 4

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
