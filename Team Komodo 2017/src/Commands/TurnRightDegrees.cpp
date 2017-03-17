#include "TurnRightDegrees.h"
#include "WPIlib.h"

TurnRightDegrees::TurnRightDegrees(double degrees) : CommandBase("TurnRightDegrees") {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(CommandBase::retrieveDriveSubsystem());
	driveSubsystem = CommandBase::retrieveDriveSubsystem();
	this->degrees = degrees;
}

// Called just before this Command runs the first time
void TurnRightDegrees::Initialize() {
	driveSubsystem->ResetLeftEncoder();
	driveSubsystem->ResetRightEncoder();
}

// Called repeatedly when this Command is scheduled to run
void TurnRightDegrees::Execute() {
	SmartDashboard::PutNumber("Left Encoder Value", driveSubsystem->GetLeftEncoderValue());
	SmartDashboard::PutNumber("Right Encoder Value", driveSubsystem->GetRightEncoderValue());
	if (fabs(driveSubsystem->GetLeftEncoderValue()) < degreesToEncoders(degrees)
					|| fabs(driveSubsystem->GetRightEncoderValue()) < degreesToEncoders(degrees)){
		//turn
		driveSubsystem->Arcade(0, 0.75, 0);
	} else {//if the encoders have reached the right values
		//stop the robot
		driveSubsystem->Arcade(0,0, 0);
		//wait
		Wait(.5);
		//reset encoders and gyro
		driveSubsystem->ResetRightEncoder();
		driveSubsystem->ResetLeftEncoder();
		isDone = true;
	}

}

// Make this return true when this Command no longer needs to run execute()
bool TurnRightDegrees::IsFinished() {
	return isDone;
}

// Called once after isFinished returns true
void TurnRightDegrees::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TurnRightDegrees::Interrupted() {

}

//----------functions to make it easier above----------//
//convert inches to the encoder value the motors need to rotate
//(in the same direction) for the robot to move forward that many inches
double TurnRightDegrees::inchesToEncoders(double inches){
	return inches*ENCODER_VALUES_PER_INCH;
}
//convert degrees to the encoder value that the motors need to rotate
//(in opposite directions)for the robot to rotate that many degrees
double TurnRightDegrees::degreesToEncoders(double degrees){
	return inchesToEncoders((degrees / 360)* M_PI * ROBOT_WIDTH_INCHES);
}
