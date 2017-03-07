#ifndef Hopper_H
#define Hopper_H



#include <Commands/Subsystem.h>
#include "WPILib.h"
#include "definitions.h"


class Hopper : public Subsystem {
private:
	VictorSP HopperMotor {HOPPER_OUTPUT_CHANNEL};
	Encoder *HopperEncoder;
	AnalogInput limitSwitch{HOPPER_LIMIT_SWITCH_CHANNEL};

public:
	Hopper();
	void InitDefaultCommand();

	void run(float speed);
	void stop();
	bool isLimitSwitchPressed();
	Encoder* getEncoder();
};


#endif  // BallManipulator_H
