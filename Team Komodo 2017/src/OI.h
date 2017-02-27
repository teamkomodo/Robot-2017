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
	int numberOfButtonsLeftJoystick;
	int numberOfButtonsRightJoystick;
	int numberOfButtonsDolphin;

	// Change to match the actual number of button
	bool previousButtonStateLeftJoystick[50];
	bool previousButtonStateRightJoystick[50];
	bool previousButtonStateDolphin[50];

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
