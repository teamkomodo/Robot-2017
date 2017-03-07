/*
 * Created 01/28/17 by Max Davy
 * Portions of code courtesy FRC Team 6012 STEAMRollers
 */
#include "ResetHopper.h"
#include "OI.h"
#include "EncoderConverter.h"

ResetHopper::ResetHopper() : CommandBase("ResetHopper") {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(CommandBase::retrieveHopperSubsystem());
	hopperSubsystem = CommandBase::retrieveHopperSubsystem();
}

// Called just before this Command runs the first time
void ResetHopper::Initialize() {
	step = 1;
	hopperSubsystem->getEncoder()->Reset();//reset the encoder
}

// Called repeatedly when this Command is scheduled to run
void ResetHopper::Execute() {
	SmartDashboard::PutNumber("Hopper Encoder Value", hopperSubsystem->getEncoder()->GetRaw());
	switch(step){
	case 1:
		if (hopperSubsystem->isLimitSwitchPressed()){//if the limit switched is pressed
			hopperSubsystem->run(0);//stop the motor
			hopperSubsystem->getEncoder()->Reset();//reset the encoder
			step = 2;//go on to the next step
		}else{//if the limit switch isn't pressed
			hopperSubsystem->run(.75);//run the hopper at 3/4 speed forward
		}
	break;
	case 2:
		if (hopperSubsystem->getEncoder()->GetRaw()>-HOPPER_MAXIMUM_ENCODER){//if the hopper encoder value is less than the maximum
			hopperSubsystem->run(-.75);//run the hopper at 3/4 speed backward
		}else{//if the encoder has reached the maximum value
			hopperSubsystem->run(0);//stop the motor
			hopperSubsystem->getEncoder()->Reset();//reset the encoder
			step = 3;//move to the next step
		}
	break;
	case 3:default:
		isDone = true;//tell the scheduler to stop running the command
	break;
	}
}

// Make this return true when this Command no longer needs to run execute()
bool ResetHopper::IsFinished() {
	return isDone;
}

// Called once after isFinished returns true
void ResetHopper::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ResetHopper::Interrupted() {

}
