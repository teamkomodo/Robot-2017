/*
 * OI.h
 *
 *  Created on: Jan 17, 2017
 *      Author: Daniel
 */

#ifndef SRC_OI_H_
#define SRC_OI_H_



// This is a really shitty system
// There is a function in Joystick that gives us
// the number of buttons, but too lazy to figure out
// a way to use that, if it can be done at all
#define NUMBER_OF_BUTTONS_JOYSTICK_1  100
#define NUMBER_OF_BUTTONS_JOYSTICK_2  100

#include "WPILib.h"
#include "definitions.h"

class OI {
private:
	Joystick *leftJoystick;
	Joystick *rightJoystick;
	Joystick *dolphin;

	// Change to match the actual number of button
	bool previousButtonStateJoystick1[NUMBER_OF_BUTTONS_JOYSTICK_1];
	bool previousButtonStateJoystick2[NUMBER_OF_BUTTONS_JOYSTICK_2];

public:
	OI();

	Joystick* getLeftJoystick();
	Joystick* getRightJoystick();
	Joystick* getDolphin();

	bool isButtonJustPressedJoystick1(int buttonID);
	bool isButtonJustPressedJoystick2(int buttonID);

	void updateButtonStateJoystick1();
	void updateButtonStateJoystick2();
};



#endif /* SRC_OI_H_ */
