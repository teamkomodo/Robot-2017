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
	encoder->Reset();
}

// Called repeatedly when this Command is scheduled to run
void HopperWithGamepad::Execute() {
	if(gamePad->GetRawButton(10)){
		if(gamePad->GetRawButton(2)){
			hopperSubsystem->run(1);
		}else if (gamePad->GetRawButton(3)){
			hopperSubsystem->run(-1);
		}
	}else{
		if(gamePad->GetRawButton(2)){
				if (encoder->GetRaw()< HOPPER_MAXIMUM_ENCODER){
					hopperSubsystem->run(1);
				}
			}else if (gamePad->GetRawButton(3)){
				if (encoder->GetRaw()> 410){
					hopperSubsystem->run(-1);
				}
			}else{
				hopperSubsystem->run(0);
			}
	}

	if(gamePad->GetRawButton(9)){
		encoder->Reset();
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
