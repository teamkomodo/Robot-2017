#include "DriveForwardDistance.h"
#include "OI.h"
#include "EncoderConverter.h"

DriveForwardDistance::DriveForwardDistance() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	driveSubsystem = CommandBase::retrieveDriveSubsystem();
	Requires(CommandBase::retrieveLiftSubsystem());
}

// Called just before this Command runs the first time
void DriveForwardDistance::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void DriveForwardDistance::Execute(float inches) {
	if (driveSubsystem->GetLeftEncoderValue() > EncoderConverter::InchesToEncoder(-inches)
	  && driveSubsystem->GetRightEncoderValue() < EncoderConverter::InchesToEncoder(inches)){
			driveSubsystem->Arcade(1, 0);
		} else {
			isDone = true;
			driveSubsystem->ResetRightEncoder();
			driveSubsystem->ResetLeftEncoder();
			driveSubsystem->Arcade(0,0);
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
