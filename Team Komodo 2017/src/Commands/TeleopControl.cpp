#include "TeleopControl.h"

TeleopControl::TeleopControl() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Drive);
}

// Called just before this Command runs the first time
void TeleopControl::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void TeleopControl::Execute() {
	drive->Arcade(oi->getJoystick1().GetRawAxis(GAMEPAD_1_STICK_Y), oi->getJoystick1().GetRawAxis(GAMEPAD_1_STICK_X))
}

// Make this return true when this Command no longer needs to run execute()
bool TeleopControl::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void TeleopControl::End() {
	drive->Stop();

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TeleopControl::Interrupted() {
	End();
}
