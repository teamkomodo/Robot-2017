#ifndef RobotLifter_H
#define RobotLifter_H

#include "WPILib.h"
#include <Commands/Subsystem.h>

#include "Definitions.h"

class Lift : public Subsystem {
private:
	VictorSP liftMotor {WINCH_OUTPUT_CHANNEL};
	DigitalInput limitSwitch {LIFT_LIMIT_SWITCH_CHANNEL};

public:
	Lift();
	void InitDefaultCommand() override;
	bool isLimitSwitchPressed();
	void setSpeed(int speed);
	void Stop();
};



#endif
