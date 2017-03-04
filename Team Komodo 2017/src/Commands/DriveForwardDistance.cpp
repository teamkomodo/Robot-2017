/*
 * Created 01/28/17 by Max Davy
 * Portions of code courtesy FRC Team 6012 STEAMRollers
 */
#include "DriveForwardDistance.h"
#include "OI.h"
#include "EncoderConverter.h"

DriveForwardDistance::DriveForwardDistance() : CommandBase("DriveForwardDistance") {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(CommandBase::retrieveDriveSubsystem());
	distanceInches = 66;//7ft 10in (94 in)from alliance station to baseline - 28 inches robot length
	driveSubsystem = CommandBase::retrieveDriveSubsystem();
	driveGyro = driveSubsystem->GetDriveGyro();
	editedGyroAngle = 0;
}

// Called just before this Command runs the first time
void DriveForwardDistance::Initialize() {
	driveSubsystem->ResetLeftEncoder();
	driveSubsystem->ResetRightEncoder();
	distanceInches = SmartDashboard::GetNumber("autonomousDistance", 66);
}

// Called repeatedly when this Command is scheduled to run
void DriveForwardDistance::Execute() {
	if (fabs(driveGyro->GetRate()) > 0.035 && fabs(driveGyro->GetRate()) < 30) {
		editedGyroAngle = driveGyro->GetAngle();
	}else{
		driveGyro->Reset();
		editedGyroAngle = 0;
	}
	SmartDashboard::PutNumber("Left Encoder Value", driveSubsystem->GetLeftEncoderValue());
	SmartDashboard::PutNumber("Right Encoder Value", driveSubsystem->GetRightEncoderValue());
	//if (fabs(driveSubsystem->GetLeftEncoderValue()) < EncoderConverter::InchesToEncoder(distanceInches)
	//  && fabs(driveSubsystem->GetRightEncoderValue()) < EncoderConverter::InchesToEncoder(distanceInches)){
	if (fabs(driveSubsystem->GetLeftEncoderValue()) < distanceInches * ENCODER_VALUES_PER_INCH
		&& fabs(driveSubsystem->GetRightEncoderValue()) < distanceInches * ENCODER_VALUES_PER_INCH){
			driveSubsystem->Arcade(.5, 0, editedGyroAngle);
		} else {
			driveSubsystem->ResetRightEncoder();
			driveSubsystem->ResetLeftEncoder();
			driveSubsystem->Arcade(0,0, 0);
			isDone = true;
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
