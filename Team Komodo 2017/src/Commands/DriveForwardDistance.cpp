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

	autoPosition = SmartDashboard::GetNumber("autonomousPosition (1=left 2=center 3=right", CENTER_POSITION);
	distanceInches = 150; // originally 100
	reverseDistanceInches = 20;//originally 20
	secondDistanceInches = 20;//we need to determine this
	autoStep = DRIVE_FORWARD_BEFORE_TURN;
	waitTime = 3; //originally 3
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
	SmartDashboard::PutNumber("Auto Step", autoStep);
	SmartDashboard::PutNumber("Gyro Angle", driveGyro->GetAngle());
	SmartDashboard::PutNumber("Gyro Rate", driveGyro->GetRate());
	SmartDashboard::PutNumber("Left Encoder Value", driveSubsystem->GetLeftEncoderValue());
	SmartDashboard::PutNumber("Right Encoder Value", driveSubsystem->GetRightEncoderValue());
	switch(autoStep){
	case DRIVE_FORWARD_BEFORE_TURN://drive forward
		if (fabs(driveSubsystem->GetLeftEncoderValue()*-1) < distanceInches * ENCODER_VALUES_PER_INCH
				|| fabs(driveSubsystem->GetRightEncoderValue()*-1) < distanceInches * ENCODER_VALUES_PER_INCH){
			driveSubsystem->Arcade(-.75, 0.0, editedGyroAngle);	//was .75
		} else {
			driveSubsystem->ResetRightEncoder();
			driveSubsystem->ResetLeftEncoder();
			driveGyro->Reset();
			driveSubsystem->Arcade(0,0, 0);
			Wait(waitTime);
			driveSubsystem->ResetRightEncoder();
			driveSubsystem->ResetLeftEncoder();
			//move on to the next step based on which peg we're going for
			if (autoPosition == CENTER_POSITION){//if we're going for the center peg
				autoStep = DRIVE_BACKWARD;//we don't need to turn, just back up
			}else if(autoPosition == RIGHT_POSITION){//if we're going for the the right peg
				autoStep = TURN_LEFT;//we need to turn left towards it
			}else if (autoPosition == LEFT_POSITION){//if we're going for the left peg
				autoStep = TURN_RIGHT;//we need to turn right
			}
		}
	break;
	case DRIVE_BACKWARD://drive backward
		if(fabs(driveSubsystem->GetLeftEncoderValue()) < reverseDistanceInches * ENCODER_VALUES_PER_INCH
				|| fabs(driveSubsystem->GetRightEncoderValue()) < reverseDistanceInches * ENCODER_VALUES_PER_INCH){
			driveSubsystem->Arcade(.8, 0.0, editedGyroAngle);	//was .75
		}else {
			driveSubsystem->Arcade(0,0, 0);
			autoStep = STOP;
		}
	break;
	case TURN_LEFT://turn left
		//turn left
		autoStep = DRIVE_FORWARD_AFTER_TURN;//then go forward again
	break;
	case TURN_RIGHT://turn right
		//turn right
		autoStep = DRIVE_FORWARD_AFTER_TURN;//then go forward again
	break;
	case DRIVE_FORWARD_AFTER_TURN://drive forward again
		if (fabs(driveSubsystem->GetLeftEncoderValue()*-1) < secondDistanceInches * ENCODER_VALUES_PER_INCH
						|| fabs(driveSubsystem->GetRightEncoderValue()*-1) < secondDistanceInches * ENCODER_VALUES_PER_INCH){
					driveSubsystem->Arcade(-.75, 0.0, editedGyroAngle);	//was .75
				} else {
					driveSubsystem->ResetRightEncoder();
					driveSubsystem->ResetLeftEncoder();
					driveGyro->Reset();
					driveSubsystem->Arcade(0,0, 0);
					Wait(waitTime);
					driveSubsystem->ResetRightEncoder();
					driveSubsystem->ResetLeftEncoder();
					autoStep = DRIVE_BACKWARD;//drive backward
				}
	break;
	case STOP://stop
	default:
		driveSubsystem->Arcade(0,0, 0);
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
