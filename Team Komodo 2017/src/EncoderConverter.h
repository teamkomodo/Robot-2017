/*
 * EncoderConverter.h
 *
 *  Created on: Jan 28, 2017
 *      Author: Max Davy
 */

#ifndef SRC_ENCODERCONVERTER_H_
#define SRC_ENCODERCONVERTER_H_

class EncoderConverter {
public:
	EncoderConverter();
	virtual ~EncoderConverter();
	int EncoderConverter::InchesToEncoder(float inches);
	int EncoderConverter::DegreesToEncoder(float degrees);
};

#endif /* SRC_ENCODERCONVERTER_H_ */
