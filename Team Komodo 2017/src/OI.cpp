/*
 * OI.cpp
 *
 *  Created on: Jan 17, 2017
 *      Author: Daniel
 */

#include <OI.h>

OI::OI() {
	joystick1 = new Joystick(GAMEPAD_1_INPUT_CHANNEL);
	joystick2 = new Joystick(GAMEPAD_2_INPUT_CHANNEL);
}

/**
 * Returns a pointer to the joystick 1 control
 */
Joystick* OI::getJoystick1() {
	return joystick1;
}

/**
 * Returns a pointer to the joystick 2 control
 */
Joystick* OI::getJoystick2() {
	return joystick2;
}


/**
 * Checks if this is the first cycle the button has been pressed for
 * Joystick 1
 *
 * Ensures that a button calls only work once, and don't repeat until
 * the button is released
 */
bool OI::isButtonJustPressedJoystick1(int buttonID) {
	if (joystick1->GetRawButton(buttonID) && !previousButtonStateJoystick1[buttonID]) {
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
	if (joystick2->GetRawButton(buttonID) && !previousButtonStateJoystick2[buttonID]) {
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
		previousButtonStateJoystick1[i] = joystick1->GetRawButton(i);
	}
}

/**
 * Updates the button state array for joystick 2
 *
 * MUST BE CALLED ONLY AT THE END OF AN UPDATE CYCLE
 */
void OI::updateButtonStateJoystick2() {
	for (int i=0; i<NUMBER_OF_BUTTONS_JOYSTICK_2; i++) {
		previousButtonStateJoystick2[i] = joystick2->GetRawButton(i);
	}
}
