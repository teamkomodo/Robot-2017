#include "ConveyorButtonControl.h"
#include "../CommandBase.h"

ConveyorButtonControl::ConveyorButtonControl() : CommandBase("ConveyorButtonControl") {
	// Use Requires() here to declare subsystem dependencies
	ballManipulatorSubsystem = CommandBase::retrieveBallManipulatorSubsystem();
	Requires(ballManipulatorSubsystem);

	gamePad = CommandBase::retrieveOperatorInterface()->getDolphin();
}

// Called just before this Command runs the first time
void ConveyorButtonControl::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void ConveyorButtonControl::Execute() {
	if (gamePad->GetRawButton(1)){
		ballManipulatorSubsystem->run();
	}
	else if (gamePad->GetRawButton(4)){
		ballManipulatorSubsystem->runBackward();
	}else{
		ballManipulatorSubsystem->stop();
	}
}

// Make this return true when this Command no longer needs to run execute()
bool ConveyorButtonControl::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void ConveyorButtonControl::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ConveyorButtonControl::Interrupted() {

}
