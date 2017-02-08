#include "LiftWithGamepad.h"




LiftWithGamepad::LiftWithGamepad() : CommandBase("LiftWithGamepad") {
	lifterSubsystem = CommandBase::retrieveLiftSubsystem();
	// Use Requires() here to declare subsystem dependencies
	Requires(lifterSubsystem);

	gamePad = CommandBase::retrieveOperatorInterface()->getJoystick2();
}

// Called just before this Command runs the first time
void LiftWithGamepad::Initialize() {
}

// Called repeatedly when this Command is scheduled to run
void LiftWithGamepad::Execute() {
	// Set the lift motor speed to the y-axis of the right joystick
	if(lifterSubsystem->isLimitSwitchPressed()){//if the limit switch is pressed, stop the motor
		lifterSubsystem->setSpeed(0);
	}else{
		lifterSubsystem->setSpeed(gamePad->GetRawAxis(GAMEPAD_1_STICK_Y));//otherwise control it with the joystick
	}
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
