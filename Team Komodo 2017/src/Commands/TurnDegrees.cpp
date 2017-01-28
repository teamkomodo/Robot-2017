#include "DriveForwardDistance.h"
#include "OI.h"
#include "EncoderConverter.h"
#include "TurnDegrees.h"

TurnDegrees::TurnDegrees() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	driveSubsystem = CommandBase::retrieveDriveSubsystem();
	Requires(CommandBase::retrieveLiftSubsystem());
}

// Called just before this Command runs the first time
void TurnDegrees::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void TurnDegrees::Execute(float degreesToTurn, bool turnLeft) {
		if (turnLeft){
			if (driveSubsystem->GetLeftEncoderValue() < EncoderConverter::DegreesToEncoder(degreesToTurn) && driveSubsystem->GetRightEncoderValue() < EncoderConverter::DegreesToEncoder(degreesToTurn)){
				driveSubsystem->Arcade(0, .45); // move forward for variable amount
			}
			else{
				driveSubsystem->Arcade(0, 0);
				driveSubsystem->ResetLeftEncoder();
				driveSubsystem->ResetRightEncoder();
			}
		}
		else{ //turn right
			if (driveSubsystem->GetLeftEncoderValue() > (-1 * EncoderConverter::DegreesToEncoder(degreesToTurn)) && driveSubsystem->GetRightEncoderValue() > (-1 * EncoderConverter::DegreesToEncoder(degreesToTurn))) {
				driveSubsystem->Arcade(0, -.45); // move forward for variable amount
			} else {
				driveSubsystem->Arcade(0, 0);
				driveSubsystem->ResetLeftEncoder();
				driveSubsystem->ResetRightEncoder();
			}
		}
}

// Make this return true when this Command no longer needs to run execute()
bool TurnDegrees::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void TurnDegrees::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TurnDegrees::Interrupted() {

}
