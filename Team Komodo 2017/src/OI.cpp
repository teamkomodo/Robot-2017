/*
 * OI.cpp
 *
 *  Created on: Jan 17, 2017
 *      Author: Daniel
 */

#include <OI.h>
#include "WPILib.h"

#include "./Commands/SwitchDriveReverse.h"

OI::OI() {
	leftJoystick = new Joystick(GAMEPAD_1_INPUT_CHANNEL);
	rightJoystick = new Joystick(GAMEPAD_2_INPUT_CHANNEL);
	dolphin = new Joystick(GAMEPAD_3_INPUT_CHANNEL);

	leftTrigger = new JoystickButton(leftJoystick, 1);
	rightTrigger = new JoystickButton(rightJoystick, 1);

	leftTrigger->ToggleWhenPressed(new SwitchDriveReverse());

	numberOfButtonsLeftJoystick = leftJoystick->GetButtonCount();
	numberOfButtonsRightJoystick = rightJoystick->GetButtonCount();
	numberOfButtonsDolphin = dolphin->GetButtonCount();
}

/**
 * Returns a pointer to the left joystick control
 */
Joystick* OI::getLeftJoystick() {
	return leftJoystick;
}

/**
 * Returns a pointer to the right joystick control
 */
Joystick* OI::getRightJoystick() {
	return rightJoystick;
}

/**
 * Returns a pointer to the dolphin control
 */
Joystick* OI::getDolphin(){
	return dolphin;
}


/**
 * Checks if this is the first cycle the button has been pressed for
 * Left Joystick
 *
 * Ensures that a button calls only work once, and don't repeat until
 * the button is released
 */
bool OI::isButtonJustPressedLeftJoystick(int buttonID) {
	if (leftJoystick->GetRawButton(buttonID) && !previousButtonStateLeftJoystick[buttonID]) {
		previousButtonStateLeftJoystick[buttonID] = true;
		return true;
	}

	return false;
}

/**
 * Checks if this is the first cycle the button has been pressed for
 * Right Joystick
 *
 * Ensures that a button calls only work once, and don't repeat until
 * the button is released
 */
bool OI::isButtonJustPressedRightJoystick(int buttonID) {
	if (rightJoystick->GetRawButton(buttonID) && !previousButtonStateRightJoystick[buttonID]) {
		previousButtonStateRightJoystick[buttonID] = true;
		return true;
	}

	return false;
}

/**
 * Checks if this is the first cycle the button has been pressed for
 * Dolphin
 *
 * Ensures that a button calls only work once, and don't repeat until
 * the button is released
 */
bool OI::isButtonJustPressedDolphin(int buttonID) {
	if (dolphin->GetRawButton(buttonID) && !previousButtonStateDolphin[buttonID]) {
		previousButtonStateDolphin[buttonID] = true;
		return true;
	}

	return false;
}

/**
 * Updates the button state array for left joystick
 *
 * MUST BE CALLED ONLY AT THE END OF AN UPDATE CYCLE
 */
void OI::updateButtonStateLeftJoystick() {
	for (int i=0; i<numberOfButtonsLeftJoystick; i++) {
		previousButtonStateLeftJoystick[i] = leftJoystick->GetRawButton(i);
	}
}

/**
 * Updates the button state array for right joystick
 *
 * MUST BE CALLED ONLY AT THE END OF AN UPDATE CYCLE
 */
void OI::updateButtonStateRightJoystick() {
	for (int i=0; i<numberOfButtonsRightJoystick; i++) {
		previousButtonStateRightJoystick[i] = rightJoystick->GetRawButton(i);
	}
}

/**
 * Updates the button state array for dolphin
 *
 * MUST BE CALLED ONLY AT THE END OF AN UPDATE CYCLE
 */
void OI::updateButtonStateDolphin() {
	for (int i=0; i<numberOfButtonsDolphin; i++) {
		previousButtonStateDolphin[i] = dolphin->GetRawButton(i);
	}
}

void OI::toggleReverseDrive() {
	reverseDrive = !reverseDrive;
}

bool OI::isReverseDrive() {
	return reverseDrive;
}
