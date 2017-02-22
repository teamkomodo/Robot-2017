#include "HopperWithGamepad.h"
#include "../Subsystems/Hopper.h"
#include "definitions.h"

HopperWithGamepad::HopperWithGamepad() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	gamePad = CommandBase::retrieveOperatorInterface()->getDolphin();
	hopperSubsystem = CommandBase::retrieveHopperSubsystem();
	ballManipulatorSubsystem = CommandBase::retrieveBallManipulatorSubsystem();
	encoder = hopperSubsystem->getEncoder();
}

// Called just before this Command runs the first time
void HopperWithGamepad::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void HopperWithGamepad::Execute() {
	hopperSubsystem->run(gamePad->GetRawAxis(GAMEPAD_3_RSTICK_Y));
	if (abs(gamePad->GetRawAxis(GAMEPAD_3_RSTICK_Y))>.2){
		ballManipulatorSubsystem->runBackward();
	}else{
		ballManipulatorSubsystem->stop();
	}
	SmartDashboard::PutNumber("Hopper Encoder Value", encoder->GetRaw());
}
// Make this return true when this Command no longer needs to run execute()
bool HopperWithGamepad::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void HopperWithGamepad::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void HopperWithGamepad::Interrupted() {

}
