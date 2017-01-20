#include "Drive.h"
#include "WPILib.h"
#include "definitions.h"



Drive::Drive() : Subsystem("DriveSubsystem") {
	drive = new RobotDrive(LEFT_DRIVE_OUTPUT_CHANNEL, RIGHT_DRIVE_OUTPUT_CHANNEL);
}

void Drive::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new TeleopControl());
}


// Put methods for controlling this subsystem
// here. Call these from Commands.

void Drive::Forward(int speed) {
	drive->ArcadeDrive(speed, 0);
}

void Drive::Backward(int speed) {
	drive->ArcadeDrive(-speed, 0);
}

void Drive::Left(double amt) {
	drive->ArcadeDrive(0, -amt);
}

void Drive::Right(double amt) {
	drive->ArcadeDrive(0, amt);
}

void Drive::Arcade(int speed, int turn) {
	drive->ArcadeDrive(speed, turn);
}

void Drive::Stop() {
	drive->ArcadeDrive(0, 0.0);
}
