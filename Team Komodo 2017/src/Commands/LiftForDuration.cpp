#include "LiftForDuration.h"

LiftForDuration::LiftForDuration(double timeout) : TimedCommand(timeout) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	liftSubsystem = CommandBase::retrieveLiftSubsystem();
	Requires(CommandBase::retrieveLiftSubsystem());
}

// Called just before this Command runs the first time
void LiftForDuration::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void LiftForDuration::Execute() {
	liftSubsystem->setSpeed(1);
}

// Called once after the timeout
void LiftForDuration::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LiftForDuration::Interrupted() {

}
