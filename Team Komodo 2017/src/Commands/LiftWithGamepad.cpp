#include "LiftWithGamepad.h"




LiftWithGamepad::LiftWithGamepad() : CommandBase("LiftWithGamepad") {
	lifterSubsystem = CommandBase::retrieveLiftSubsystem();
	// Use Requires() here to declare subsystem dependencies
	Requires(lifterSubsystem);

	gamePad = CommandBase::retrieveOperatorInterface()->getDolphin();
}

// Called just before this Command runs the first time
void LiftWithGamepad::Initialize() {
}

// Called repeatedly when this Command is scheduled to run
void LiftWithGamepad::Execute() {
		lifterSubsystem->setSpeed(fabs(gamePad->GetRawAxis(DOLPHIN_LSTICK_Y)));//set the speed to absolute value of the joystick position
}

// Make this return true when this Command no longer needs to run execute()
bool LiftWithGamepad::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void LiftWithGamepad::End() {
	lifterSubsystem->Stop();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LiftWithGamepad::Interrupted() {
	End();
}
