#ifndef RobotLifter_H
#define RobotLifter_H



#include "WPILib.h"
#include <Commands/Subsystem.h>


class RobotLifter : public Subsystem {
private:
	Talon *liftMotor;

public:
	RobotLifter();
	void InitDefaultCommand() override;

	void setSpeed(int speed);
};



#endif
