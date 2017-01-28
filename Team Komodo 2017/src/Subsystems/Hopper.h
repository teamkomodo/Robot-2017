#ifndef Hopper_H
#define Hopper_H



#include <Commands/Subsystem.h>
#include "WPILib.h"
#include "definitions.h"


class Hopper : public Subsystem {
private:
	Talon HopperMotor {CONVEYOR_OUTPUT_CHANNEL};
	Encoder *HopperEncoder;

public:
	Hopper();
	void InitDefaultCommand();

	void run(float speed);
	void stop();
	Encoder* getEncoder();
};


#endif  // BallManipulator_H
