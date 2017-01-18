/*
 * OI.h
 *
 *  Created on: Jan 17, 2017
 *      Author: Daniel
 */

#ifndef SRC_OI_H_
#define SRC_OI_H_

#include "WPILib.h";
#include "definitions.h"

class OI {
private:
	Joystick gamePad1 = new Joystick(GAMEPAD_1_INPUT_CHANNEL);
	Joystick gamePad2 = new Joystick(GAMEPAD_2_INPUT_CHANNEL);
public:
	Joystick OI::getJoystick1();
	Joystick OI::getJoystick2();
};

#endif /* SRC_OI_H_ */
