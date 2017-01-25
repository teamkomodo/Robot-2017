#include "BallManipulator.h"
#include "../definitions.h"
#include "WPILib.h"

BallManipulator::BallManipulator() : Subsystem("BallManipulator") {
}

void BallManipulator::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

void BallManipulator::run() {
	// We might want a constant for the speed
	// 1 is probably not the speed we want
	conveyorBeltMotor.SetSpeed(1);
}

void BallManipulator::stop() {
	conveyorBeltMotor.SetSpeed(0);
}
