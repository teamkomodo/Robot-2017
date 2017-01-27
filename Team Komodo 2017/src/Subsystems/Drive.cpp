#include "Drive.h"
#include "../Commands/TeleopControl.h"

Drive::Drive() : Subsystem("DriveSubsystem") {
}

void Drive::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new TeleopControl());
}


// Put methods for controlling this subsystem
// here. Call these from Commands.

void Drive::Forward(int speed) {
	drive.ArcadeDrive(speed, 0);
}

void Drive::Backward(int speed) {
	drive.ArcadeDrive(-speed, 0);
}

void Drive::Left(double amt) {
	drive.ArcadeDrive(0, -amt);
}

void Drive::Right(double amt) {
	drive.ArcadeDrive(0, amt);
}

void Drive::Arcade(int speed, int turn) {
	drive.ArcadeDrive(speed, turn);
}

void Drive::Stop() {
	drive.ArcadeDrive(0, 0.0);
}
