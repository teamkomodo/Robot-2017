/*
 * Created 01/28/17 by Max Davy
 * Portions of code courtesy FRC Team 6012 STEAMRollers
 */
#include "DriveForwardDistance.h"
#include "OI.h"
#include "EncoderConverter.h"
#include "WPIlib.h"

DriveForwardDistance::DriveForwardDistance() : CommandBase("DriveForwardDistance") {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(CommandBase::retrieveDriveSubsystem());
	distanceInches = 150; // was 100
	reverseDistanceInches = 20;
	autoCount = 1;
	waitTime = 3; //was 3
	driveSubsystem = CommandBase::retrieveDriveSubsystem();
	driveGyro = driveSubsystem->GetDriveGyro();
	editedGyroAngle = 0;
}

// Called just before this Command runs the first time
void DriveForwardDistance::Initialize() {
	driveSubsystem->ResetLeftEncoder();
	driveSubsystem->ResetRightEncoder();
	driveGyro->Reset();
	//distanceInches = SmartDashboard::GetNumber("autonomousDistance", 66);
}

// Called repeatedly when this Command is scheduled to run
void DriveForwardDistance::Execute() {
	if (fabs(driveGyro->GetRate()) > 0.04 ) {	//works well at .04
		editedGyroAngle = driveGyro->GetAngle();
	}else{
		driveGyro->Reset();
		editedGyroAngle = 0;
	}
	SmartDashboard::PutNumber("Auto count", autoCount);
	SmartDashboard::PutNumber("Gyro Angle", driveGyro->GetAngle());
	SmartDashboard::PutNumber("Gyro Rate", driveGyro->GetRate());
	SmartDashboard::PutNumber("Left Encoder Value", driveSubsystem->GetLeftEncoderValue());
	SmartDashboard::PutNumber("Right Encoder Value", driveSubsystem->GetRightEncoderValue());
	//if (fabs(driveSubsystem->GetLeftEncoderValue()) < EncoderConverter::InchesToEncoder(distanceInches)
	//  && fabs(driveSubsystem->GetRightEncoderValue()) < EncoderConverter::InchesToEncoder(distanceInches)){
if (autoCount == 1){

	if (fabs(driveSubsystem->GetLeftEncoderValue()*-1) < distanceInches * ENCODER_VALUES_PER_INCH
		|| fabs(driveSubsystem->GetRightEncoderValue()*-1) < distanceInches * ENCODER_VALUES_PER_INCH){
			driveSubsystem->Arcade(-.75, 0.0, editedGyroAngle);	//was .75
		} else {
			driveSubsystem->ResetRightEncoder();
			driveSubsystem->ResetLeftEncoder();
			driveGyro->Reset();
			driveSubsystem->Arcade(0,0, 0);
			//Wait(waitTime);
			driveSubsystem->ResetRightEncoder();
			driveSubsystem->ResetLeftEncoder();
			//autoCount = 2;
			isDone = true;

		}
}

else if (autoCount == 2){
	if(fabs(driveSubsystem->GetLeftEncoderValue()) < reverseDistanceInches * ENCODER_VALUES_PER_INCH
		|| fabs(driveSubsystem->GetRightEncoderValue()) < reverseDistanceInches * ENCODER_VALUES_PER_INCH){
				driveSubsystem->Arcade(.8, 0.0, editedGyroAngle);	//was .75
			}
	else {
				driveSubsystem->ResetRightEncoder();
				driveSubsystem->ResetLeftEncoder();
				driveSubsystem->Arcade(0,0, 0);
				//Wait(20);
				isDone = true;

			}
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
