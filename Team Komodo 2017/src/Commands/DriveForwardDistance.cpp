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
	driveSubsystem = CommandBase::retrieveDriveSubsystem();
	driveGyro = driveSubsystem->GetDriveGyro();

	//distances are now in definitions.h

	//get value from SmartDashboard for what position we're in
	autoPosition = SmartDashboard::GetNumber("autonomousPosition (1=left 2=center 3=right", CENTER_POSITION);

	autoStep = DRIVE_FORWARD_BEFORE_TURN;
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
	if (fabs(driveGyro->GetRate()) > 0.04 ) {	//works well at .04
		editedGyroAngle = driveGyro->GetAngle();
	}else{
		driveGyro->Reset();
		editedGyroAngle = 0;
	}
	//put the info on the smartDashboard for troubleshooting
	SmartDashboard::PutNumber("Auto Step", autoStep);
	SmartDashboard::PutNumber("Gyro Angle", driveGyro->GetAngle());
	SmartDashboard::PutNumber("Gyro Rate", driveGyro->GetRate());
	SmartDashboard::PutNumber("Left Encoder Value", driveSubsystem->GetLeftEncoderValue());
	SmartDashboard::PutNumber("Right Encoder Value", driveSubsystem->GetRightEncoderValue());
	//depending on what value autoStep has
	switch(autoStep){
	case DRIVE_FORWARD_BEFORE_TURN://drive forward; this will get run first
		//if the encoders haven't reached the values
		if (fabs(driveSubsystem->GetLeftEncoderValue()) < inchesToEncoders(DISTANCE_BEFORE_TURN)
				|| fabs(driveSubsystem->GetRightEncoderValue()) < inchesToEncoders(DISTANCE_BEFORE_TURN)){
			//drive forward
			driveSubsystem->Arcade(-.75, 0.0, editedGyroAngle);	//was .75
		} else {//if the encoders have reached the values
			//reset encoders and gyro
			driveSubsystem->ResetRightEncoder();
			driveSubsystem->ResetLeftEncoder();
			driveGyro->Reset();
			//stop the robot
			driveSubsystem->Arcade(0,0, 0);
			//wait
			Wait(WAIT_TIME);
			driveSubsystem->ResetRightEncoder();
			driveSubsystem->ResetLeftEncoder();
			//move on to the next step based on which peg we're going for
			if (autoPosition == CENTER_POSITION){
				//if we're going for the center peg
				//we don't need to turn, just back up
				autoStep = DRIVE_BACKWARD;
			}else if(autoPosition == RIGHT_POSITION){
				//if we're going for the the right peg
				//we need to turn left towards it
				autoStep = TURN_LEFT;
			}else if (autoPosition == LEFT_POSITION){
				//if we're going for the left peg
				//we need to turn right
				autoStep = TURN_RIGHT;
			}
		}
	break;
	case DRIVE_BACKWARD://drive backward
		//if the encoders haven't reached the right values yet
		if(fabs(driveSubsystem->GetLeftEncoderValue()) < inchesToEncoders(DISTANCE_REVERSE)
				|| fabs(driveSubsystem->GetRightEncoderValue()) < inchesToEncoders(DISTANCE_REVERSE)){
			//drive backwards
			driveSubsystem->Arcade(.8, 0.0, editedGyroAngle);	//was .75
		}else {//if they have
			//stop driving
			driveSubsystem->Arcade(0,0, 0);
			//go on to the next step
			autoStep = STOP;
		}
	break;
	case TURN_LEFT://turn left
		//if the encoders haven't reached the right value
		if (fabs(driveSubsystem->GetLeftEncoderValue()) < degreesToEncoders(TURN_DEGREES)
					|| fabs(driveSubsystem->GetRightEncoderValue()) < degreesToEncoders(TURN_DEGREES)){
			//turn
			driveSubsystem->Arcade(0, -0.75, editedGyroAngle);
		} else {//if the encoders have reached the right values
			//reset encoders and gyros
			driveSubsystem->ResetRightEncoder();
			driveSubsystem->ResetLeftEncoder();
			driveGyro->Reset();
			//stop the robot
			driveSubsystem->Arcade(0,0, 0);
			//wait
			Wait(WAIT_TIME);
			driveSubsystem->ResetRightEncoder();
			driveSubsystem->ResetLeftEncoder();
			//go to the next step
			autoStep = DRIVE_FORWARD_AFTER_TURN;
		}
	break;
	case TURN_RIGHT://turn right
		//if the encoders haven't reached the right value
		if (fabs(driveSubsystem->GetLeftEncoderValue()) < degreesToEncoders(TURN_DEGREES)
				|| fabs(driveSubsystem->GetRightEncoderValue()) < degreesToEncoders(TURN_DEGREES)){
			//turn
			driveSubsystem->Arcade(0, 0.75, editedGyroAngle);
		} else {//if the encoders have reached the right values
			//reset encoders and gyros
			driveSubsystem->ResetRightEncoder();
			driveSubsystem->ResetLeftEncoder();
			driveGyro->Reset();
			//stop the robot
			driveSubsystem->Arcade(0,0, 0);
			//wait
			Wait(WAIT_TIME);
			driveSubsystem->ResetRightEncoder();
			driveSubsystem->ResetLeftEncoder();
			//go to the next step
			autoStep = DRIVE_FORWARD_AFTER_TURN;
		}
	break;
	case DRIVE_FORWARD_AFTER_TURN://drive forward again
		//if we haven't reached the desired encoder values
		if (fabs(driveSubsystem->GetLeftEncoderValue()) < inchesToEncoders(DISTANCE_AFTER_TURN)
						|| fabs(driveSubsystem->GetRightEncoderValue()) < inchesToEncoders(DISTANCE_AFTER_TURN)){
			//drive forward
			driveSubsystem->Arcade(-.75, 0.0, editedGyroAngle);
		} else {//if we have reached the encoder values
			//reset encoders and gyro
			driveSubsystem->ResetRightEncoder();
			driveSubsystem->ResetLeftEncoder();
			driveGyro->Reset();
			//stop the robot
			driveSubsystem->Arcade(0,0, 0);
			//wait
			Wait(WAIT_TIME);
			driveSubsystem->ResetRightEncoder();
			driveSubsystem->ResetLeftEncoder();
			//go on to the next step
			autoStep = DRIVE_BACKWARD;
		}
	break;
	case STOP://stop
	default://if autoStep isn't one of the values listed above this will run.
		//stop the robot
		driveSubsystem->Arcade(0,0, 0);
		//tell the scheduler to stop running this command
		isDone = true;
	break;
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
