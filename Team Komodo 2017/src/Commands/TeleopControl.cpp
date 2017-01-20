#include "TeleopControl.h"



TeleopControl::TeleopControl() : CommandBase("TeleopControl") {
	// Use Requires() here to declare subsystem dependencies
	Requires(CommandBase::driveSubsystem.get());

	gamePad1 = oi->getJoystick1();
}

// Called just before this Command runs the first time
void TeleopControl::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void TeleopControl::Execute() {
	driveSubsystem->Arcade(gamePad1->GetRawAxis(GAMEPAD_1_STICK_Y),
						   gamePad1->GetRawAxis(GAMEPAD_1_STICK_X));
}

// Make this return true when this Command no longer needs to run execute()
bool TeleopControl::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void TeleopControl::End() {
	driveSubsystem->Stop();

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TeleopControl::Interrupted() {
	End();
}
