#include "main.h"
#include "motorctrl.h"
#include "posctrl.h"

/*
 * Runs pre-initialization code. This function will be started in kernel mode one time while the
 * VEX Cortex is starting up. As the scheduler is still paused, most API functions will fail.
 *
 * The purpose of this function is solely to set the default pin modes (pinMode()) and port
 * states (digitalWrite()) of limit switches, push buttons, and solenoids. It can also safely
 * configure a UART port (usartOpen()) but cannot set up an LCD (lcdInit()).
 */
void initializeIO() {
}

/*
 * Runs user initialization code. This function will be started in its own task with the default
 * priority and stack size once when the robot is starting up. It is possible that the VEXnet
 * communication link may not be fully established at this time, so reading from the VEX
 * Joystick may fail.
 *
 * This function should initialize most sensors (gyro, encoders, ultrasonics), LCDs, global
 * variables, and IMEs.
 *
 * This function must exit relatively promptly, or the operatorControl() and autonomous() tasks
 * will not start. An autonomous mode selection menu like the pre_auton() in other environments
 * can be implemented in this task if desired.
 */
void initialize() {
  setTeamName("5840D");

  int IMECount = imeInitializeAll();
  if (IMECount != NUMBER_OF_IME) { /*Do nothing because laziness. Should turn on an error LED or something later.*/ }

  lcdInit(uart1);
  lcdClear(uart1);

  /*
   * Motors should get initialized here.
   * Keep in mind, the main PTCs are from ports 1-5 and 6-10. Since in reality it's rather unlikely
   * that all motors will be going at exactly the same time, it might be better to split up motor
   * grouping, having different motors for the same task appear on each of the two main PTCs.
   * This way, if one is flipped, you would still have a system (ex: a drive train) running, just
   * at half the power. This doesn't affect the individual PTCs on each of the 393 motors.
   */
  motors[0] = createMotor(MOT_BR, IME_BR, true);
  motors[1] = createMotor(MOT_BL, IME_BL, true);
  motors[2] = createMotor(MOT_FR, IME_FR, false);
  motors[3] = createMotor(MOT_FL, IME_FL, false);
}
