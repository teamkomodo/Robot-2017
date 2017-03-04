/*
 * Functions to convert inches of robot travel to encoder values
 *
 *  Created 01/28/17 by Max Davy
 *  Portions of code courtesy FRC Team 6012 STEAMRollers
 */

#include <EncoderConverter.h>
#include <math.h>
#include "definitions.h"

int EncoderConverter::InchesToEncoder(float inches) {
	int EncoderUnits = 0;
	EncoderUnits = inches * ENCODER_VALUES_PER_INCH;
	return EncoderUnits;
}

int EncoderConverter::DegreesToEncoder(float degrees) {
	int EncoderValues = 0;
	EncoderValues = EncoderConverter::InchesToEncoder((degrees / 360)* M_PI * ROBOT_WIDTH_INCHES);
	return EncoderValues;
}


