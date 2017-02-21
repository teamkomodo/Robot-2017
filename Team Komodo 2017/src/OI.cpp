/*
 * OI.cpp
 *
 *  Created on: Jan 17, 2017
 *      Author: Daniel
 */

#include <OI.h>

OI::OI() {
	leftJoystick = new Joystick(GAMEPAD_1_INPUT_CHANNEL);
	rightJoystick = new Joystick(GAMEPAD_2_INPUT_CHANNEL);
	dolphin = new Joystick(GAMEPAD_3_INPUT_CHANNEL);
}

/**
 * Returns a pointer to the joystick 1 control
 */
Joystick* OI::getLeftJoystick() {
	return leftJoystick;
}

/**
 * Returns a pointer to the joystick 2 control
 */
Joystick* OI::getRightJoystick() {
	return rightJoystick;
}

Joystick* OI::getDolphin(){
	return dolphin;
}


/**
 * Checks if this is the first cycle the button has been pressed for
 * Joystick 1
 *
 * Ensures that a button calls only work once, and don't repeat until
 * the button is released
 */
bool OI::isButtonJustPressedJoystick1(int buttonID) {
	if (leftJoystick->GetRawButton(buttonID) && !previousButtonStateJoystick1[buttonID]) {
		previousButtonStateJoystick1[buttonID] = true;
		return true;
	}

	return false;
}

/**
 * Checks if this is the first cycle the button has been pressed for
 * Joystick 2
 *
 * Ensures that a button calls only work once, and don't repeat until
 * the button is released
 */
bool OI::isButtonJustPressedJoystick2(int buttonID) {
	if (rightJoystick->GetRawButton(buttonID) && !previousButtonStateJoystick2[buttonID]) {
		previousButtonStateJoystick2[buttonID] = true;
		return true;
	}

	return false;
}


/**
 * Updates the button state array for joystick 1
 *
 * MUST BE CALLED ONLY AT THE END OF AN UPDATE CYCLE
 */
void OI::updateButtonStateJoystick1() {
	for (int i=0; i<NUMBER_OF_BUTTONS_JOYSTICK_1; i++) {
		previousButtonStateJoystick1[i] = leftJoystick->GetRawButton(i);
	}
}

/**
 * Updates the button state array for joystick 2
 *
 * MUST BE CALLED ONLY AT THE END OF AN UPDATE CYCLE
 */
void OI::updateButtonStateJoystick2() {
	for (int i=0; i<NUMBER_OF_BUTTONS_JOYSTICK_2; i++) {
		previousButtonStateJoystick2[i] = rightJoystick->GetRawButton(i);
	}
}
