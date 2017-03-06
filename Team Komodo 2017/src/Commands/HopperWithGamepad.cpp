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
	if(gamePad->GetRawButton(10)){//if the button to override limits is pressed
		if(gamePad->GetRawButton(2)){//if the button is pressed
			hopperSubsystem->run(1);//run the conveyor forward
		}else if (gamePad->GetRawButton(3)){//if the button is pressed
			hopperSubsystem->run(-1);//run the conveyor backward
		}else{//if neither button is pressed
			hopperSubsystem->run(0);//stop the motor
		}
	}else{//if the button to override the limits isn't pressed
		if(gamePad->GetRawButton(2)){//if the 'dump' button is pressed
				if (encoder->GetRaw()< HOPPER_MAXIMUM_ENCODER || !hopperSubsystem->isLimitSwitchPressed()){//if the encoder is less than the maximum and the limit switch isn't pressed
					hopperSubsystem->run(1);//run the hopper motor forward (tighten the cloth)
				}
			}
		if (gamePad->GetRawButton(3)){//if the 'lower' button is pressed
			if (encoder->GetRaw()> 410){//if the encoder value is greater than 0 (allow for the motor not stopping immediately)
				hopperSubsystem->run(-1);//run the hopper motor backward
			}
		}else{//if neither button is pressed
			hopperSubsystem->run(0);//stop the motor
		}
	}

	if(gamePad->GetRawButton(9)){//if the button to reset the encoder is pressed
		encoder->Reset();//reset the encoder
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
