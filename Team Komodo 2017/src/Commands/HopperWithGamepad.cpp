#include "HopperWithGamepad.h"
#include "../Subsystems/Hopper.h"
#include "definitions.h"

HopperWithGamepad::HopperWithGamepad() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	gamePad = CommandBase::retrieveOperatorInterface()->getJoystick2();
	hopperSubsystem = CommandBase::retrieveHopperSubsystem();
	encoder = hopperSubsystem->getEncoder();
}

// Called just before this Command runs the first time
void HopperWithGamepad::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void HopperWithGamepad::Execute() {
	if(gamePad->GetRawButton(5)){
		//while(encoder->GetRaw()< HOPPER_MAXIMUM_ENCODER){
			hopperSubsystem->run(.5);
		//}
		//hopperSubsystem->stop();
	}else if (gamePad->GetRawButton(3)){
		//while(encoder->GetRaw()> 0){
			hopperSubsystem->run(-.5);
		//}
		//hopperSubsystem->stop();
	}else{
		hopperSubsystem->stop();
	}
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
