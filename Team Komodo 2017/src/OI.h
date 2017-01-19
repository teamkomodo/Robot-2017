/*
 * OI.h
 *
 *  Created on: Jan 17, 2017
 *      Author: Daniel
 */

#ifndef SRC_OI_H_
#define SRC_OI_H_

#include "WPILib.h"
#include "definitions.h"

class OI {
private:
	Joystick *gamePad1;
	Joystick *gamePad2;

public:
	OI();

	Joystick* getJoystick1();
	Joystick* getJoystick2();
};

#endif /* SRC_OI_H_ */
