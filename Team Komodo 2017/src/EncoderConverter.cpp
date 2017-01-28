/*
 * EncoderConverter.cpp
 *
 *  Created on: Jan 28, 2017
 *      Author: Max Davy
 */

#include <EncoderConverter.h>
#include <math.h>
#include "definitions.h"

EncoderConverter::EncoderConverter() {
	// TODO Auto-generated constructor stub

}

int EncoderConverter::InchesToEncoder(float inches) {
	int EncoderUnits = 0;
	EncoderUnits = inches * ENCODER_VALUES_PER_INCH;//56.7 assuming 4 inch high-traction wheels
	return EncoderUnits;
}

int EncoderConverter::DegreesToEncoder(float degrees) {
	int EncoderValues = 0;
	EncoderValues = EncoderConverter::InchesToEncoder((degrees / 360)* M_PI * 17.625);
	return EncoderValues;
}

EncoderConverter::~EncoderConverter() {
	// TODO Auto-generated destructor stub
}

