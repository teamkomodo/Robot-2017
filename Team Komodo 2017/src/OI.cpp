/*
 * OI.cpp
 *
 *  Created on: Jan 17, 2017
 *      Author: Daniel
 */

#include <OI.h>

OI::OI() {
	gamePad1 = new Joystick(GAMEPAD_1_INPUT_CHANNEL);
	gamePad2 = new Joystick(GAMEPAD_2_INPUT_CHANNEL);
}

Joystick* OI::getJoystick1() {
	return gamePad1;
}

Joystick* OI::getJoystick2() {
	return gamePad2;
}
