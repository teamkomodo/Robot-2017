#include "Drive.h"
#include "WPILib.h"
#include "definitions.h";


Drive::Drive() : Subsystem("ExampleSubsystem") {

}

void Drive::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}


// Put methods for controlling this subsystem
// here. Call these from Commands.

void Drive::Forward(int speed) {
	_drive.ArcadeDrive(speed, 0);
}

void Drive::Backward(int speed) {
	_drive.ArcadeDrive(-speed, 0);
}

void Drive::Left(double amt) {
	_drive.ArcadeDrive(0, -amt);
}

void Drive::Right(double amt) {
	_drive.ArcadeDrive(0, amt);
}

void Drive::Arcade(int speed, int turn) {
	_drive.ArcadeDrive(speed, turn);
}

void Drive::Stop() {
	_drive.ArcadeDrive(0, 0.0);
}
