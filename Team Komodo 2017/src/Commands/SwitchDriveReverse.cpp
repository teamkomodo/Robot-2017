#include "SwitchDriveReverse.h"

SwitchDriveReverse::SwitchDriveReverse() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void SwitchDriveReverse::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void SwitchDriveReverse::Execute() {
	//OI->retrieveOperatorInterface().toggleReverseDrive()
	CommandBase::retrieveOperatorInterface()->toggleReverseDrive();
	shouldStop = true;
}

// Make this return true when this Command no longer needs to run execute()
bool SwitchDriveReverse::IsFinished() {
	return shouldStop;
}

// Called once after isFinished returns true
void SwitchDriveReverse::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SwitchDriveReverse::Interrupted() {

}
