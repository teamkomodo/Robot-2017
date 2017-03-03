/*
 * Created 01/28/17 by Max Davy
 * Portions of code courtesy FRC Team 6012 STEAMRollers
 */
#include "DriveForwardDistance.h"
#include "OI.h"
#include "EncoderConverter.h"

DriveForwardDistance::DriveForwardDistance(float inches) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	distanceInches = inches;
	driveSubsystem = CommandBase::retrieveDriveSubsystem();
	Requires(CommandBase::retrieveDriveSubsystem());
}

// Called just before this Command runs the first time
void DriveForwardDistance::Initialize() {
	driveSubsystem->ResetLeftEncoder();
	driveSubsystem->ResetRightEncoder();
}

// Called repeatedly when this Command is scheduled to run
void DriveForwardDistance::Execute() {
	if (driveSubsystem->GetLeftEncoderValue() > EncoderConverter::InchesToEncoder(-distanceInches)
	  && driveSubsystem->GetRightEncoderValue() < EncoderConverter::InchesToEncoder(distanceInches)){
			driveSubsystem->Arcade(1, 0, 0);
		} else {
			isDone = true;
			driveSubsystem->ResetRightEncoder();
			driveSubsystem->ResetLeftEncoder();
			driveSubsystem->Arcade(0,0, 0);
		}
}

// Make this return true when this Command no longer needs to run execute()
bool DriveForwardDistance::IsFinished() {
	return isDone;
}

// Called once after isFinished returns true
void DriveForwardDistance::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveForwardDistance::Interrupted() {

}
