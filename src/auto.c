#include "main.h"
#include "posctrl.h"

void autonomous() {
  //Use VEX cortex pin jacks to binary set starting position
  int lsb = digitalRead(POS_LSB);
  int msb = digitalRead(POS_MSB);

  taskCreate(trackPos, TASK_DEFAULT_STACK_SIZE, NULL, TASK_PRIORITY_DEFAULT);
  switch ((msb<<1)+lsb) {
    case 0: { //Start PosA
      break;
    }
    case 1: { //Start PosB
      break;
    }
    case 2: { //Start PosC
      break;
    }
    case 3: { //Start PosD
      break;
    }
  }

}
