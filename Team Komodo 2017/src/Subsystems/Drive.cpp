#include "Drive.h"
#include "../Commands/TeleopControl.h"
#include <string>

Drive::Drive() : Subsystem("DriveSubsystem") {
	rightEncoder = new Encoder(RIGHT_ENCODER_CHANNEL_A, RIGHT_ENCODER_CHANNEL_B);
	leftEncoder = new Encoder(RIGHT_ENCODER_CHANNEL_A, RIGHT_ENCODER_CHANNEL_B);
}

void Drive::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new TeleopControl());
}


// Put methods for controlling this subsystem
// here. Call these from Commands.

void Drive::Forward(double speed) {
	drive.ArcadeDrive(speed, 0);
}

void Drive::Backward(double speed) {
	drive.ArcadeDrive(-speed, 0);
}

void Drive::Left(double amt) {
	drive.ArcadeDrive(0, -amt);
}

void Drive::Right(double amt) {
	drive.ArcadeDrive(0, amt);
}

void Drive::Arcade(double speed, double turn) {
	drive.ArcadeDrive(speed, turn);
	std::cout << "Speed:"+std::to_string(speed) + " Turn:"+std::to_string(turn) << std::endl;
}

void Drive::Stop() {
	drive.ArcadeDrive(0, 0.0);
}

void Drive::ResetLeftEncoder(){
	leftEncoder->Reset();
}

void Drive::ResetRightEncoder(){
	rightEncoder->Reset();
}

int Drive::GetLeftEncoderValue(){
	return leftEncoder->GetRaw();
}

int Drive::GetRightEncoderValue(){
	return rightEncoder->GetRaw();
}

Encoder* Drive::GetLeftEncoder(){
	return leftEncoder;
}

Encoder* Drive::GetRightEncoder(){
	return rightEncoder;
}
