#include <Subsystems/Lift.h>
#include "../definitions.h"

#include "WPILib.h"

#include "../Commands/LiftWithGamepad.h"



Lift::Lift() : Subsystem("Lift") {
	liftMotor = new Talon(WINCH_OUTPUT_CHANNEL);
}

void Lift::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// The one that is called when the subsystem is idle.
	SetDefaultCommand(new LiftWithGamepad());
}


void Lift::setSpeed(int speed) {
	liftMotor->SetSpeed(speed);
}


void Lift::Stop() {
	liftMotor->SetSpeed(0);
}
