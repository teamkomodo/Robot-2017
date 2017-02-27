/*
 * OI.h
 *
 *  Created on: Jan 17, 2017
 *      Author: Daniel
 */

#ifndef SRC_OI_H_
#define SRC_OI_H_


// There is a function in Joystick that gives us
// the number of buttons, but too lazy to figure out
// a way to use that, if it can be done at all

#include "WPILib.h"
#include "definitions.h"

class OI {
private:
	Joystick *leftJoystick;
	Joystick *rightJoystick;
	Joystick *dolphin;
	int numberOfButtonsLeftJoystick = 100;
	int numberOfButtonsRightJoystick = 100;
	int numberOfButtonsDolphin = 100;

	// Change to match the actual number of button
	bool previousButtonStateLeftJoystick[numberOfButtonsLeftJoystick];
	bool previousButtonStateRightJoystick[numberOfButtonsRightJoystick];
	bool previousButtonStateDolphin[numberOfButtonsDolphin];

public:
	OI();

	Joystick* getLeftJoystick();
	Joystick* getRightJoystick();
	Joystick* getDolphin();

	bool isButtonJustPressedLeftJoystick(int buttonID);
	bool isButtonJustPressedRightJoystick(int buttonID);
	bool isButtonJustPressedDolphin(int buttonID);

	void updateButtonStateLeftJoystick();
	void updateButtonStateRightJoystick();
	void updateButtonStateDolphin();
};



#endif /* SRC_OI_H_ */
