#ifndef RobotLifter_H
#define RobotLifter_H



#include "WPILib.h"
#include <Commands/Subsystem.h>


class Lift : public Subsystem {
private:
	Talon *liftMotor;

public:
	Lift();
	void InitDefaultCommand() override;

	void setSpeed(int speed);
	void Stop();
};



#endif
