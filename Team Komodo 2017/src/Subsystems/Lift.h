#ifndef RobotLifter_H
#define RobotLifter_H

#include "WPILib.h"
#include <Commands/Subsystem.h>

#include "../Commands/LiftWithGamepad.h"
#include "../definitions.h"

class Lift : public Subsystem {
private:
	Talon liftMotor {WINCH_OUTPUT_CHANNEL};

public:
	Lift();
	void InitDefaultCommand() override;

	void setSpeed(int speed);
	void Stop();
};



#endif
