#include "RobotLifter.h"
#include "../definitions.h"



#include "WPILib.h"

RobotLifter::RobotLifter() : Subsystem("RobotLifter") {
	liftMotor = new Talon(WINCH_OUTPUT_CHANNEL);
}

void RobotLifter::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// The one that is called when the subsystem is idle.
	//SetDefaultCommand(new LiftWithGamepad());
}


void RobotLifter::setSpeed(int speed) {
	liftMotor->SetSpeed(speed);
}
