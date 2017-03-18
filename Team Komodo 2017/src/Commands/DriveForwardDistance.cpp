/*
 * Created 01/28/17 by Max Davy
 * Portions of code courtesy FRC Team 6012 STEAMRollers
 */
#include "DriveForwardDistance.h"
#include "OI.h"
#include "WPIlib.h"

DriveForwardDistance::DriveForwardDistance(double inches) : CommandBase("DriveForwardDistance") {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(CommandBase::retrieveDriveSubsystem());
	driveSubsystem = CommandBase::retrieveDriveSubsystem();
	driveGyro = driveSubsystem->GetDriveGyro();

	this->inches = inches;
	editedGyroAngle = 0;
}

// Called just before this Command runs the first time
void DriveForwardDistance::Initialize() {
	//reset encoders and gyros
	driveSubsystem->ResetLeftEncoder();
	driveSubsystem->ResetRightEncoder();
	driveGyro->Reset();
}

// Called repeatedly when this Command is scheduled to run
void DriveForwardDistance::Execute() {
	//gyro drive
	if (fabs(driveGyro->GetRate()) > 0.025 ) {	//works well at .04
		editedGyroAngle = driveGyro->GetAngle();
	}else{
		driveGyro->Reset();
		editedGyroAngle = 0;
	}
	//put the info on the smartDashboard for troubleshooting
	SmartDashboard::PutNumber("Gyro Angle", driveGyro->GetAngle());
	SmartDashboard::PutNumber("Gyro Rate", driveGyro->GetRate());
	SmartDashboard::PutNumber("Left Encoder Value", driveSubsystem->GetLeftEncoderValue());
	SmartDashboard::PutNumber("Right Encoder Value", driveSubsystem->GetRightEncoderValue());
	//if the encoders haven't reached the values
	if (fabs(driveSubsystem->GetLeftEncoderValue()) < inchesToEncoders(inches)
				|| fabs(driveSubsystem->GetRightEncoderValue()) < inchesToEncoders(inches)){
		//drive forward
		driveSubsystem->Arcade(.67, 0.0, editedGyroAngle);	//was .75
	} else {//if the encoders have reached the values
		//stop the robot
		driveSubsystem->Arcade(0,0, 0);
		//wait
		Wait(.5);
		//reset encoders and gyro
		driveSubsystem->ResetRightEncoder();
		driveSubsystem->ResetLeftEncoder();
		driveGyro->Reset();
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

//----------functions to make it easier above----------//
//convert inches to the encoder value the motors need to rotate
//(in the same direction) for the robot to move forward that many inches
double DriveForwardDistance::inchesToEncoders(double inches){
	return inches*ENCODER_VALUES_PER_INCH;
}
//convert degrees to the encoder value that the motors need to rotate
//(in opposite directions)for the robot to rotate that many degrees
double DriveForwardDistance::degreesToEncoders(double degrees){
	return inchesToEncoders((degrees / 360)* M_PI * ROBOT_WIDTH_INCHES);
}
