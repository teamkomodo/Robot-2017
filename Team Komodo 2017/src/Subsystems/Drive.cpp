#include "Drive.h"
#include "../Commands/TeleopControl.h"
#include <string>

Drive::Drive() : Subsystem("DriveSubsystem") {
	rightEncoder = new Encoder(RIGHT_ENCODER_CHANNEL_A, RIGHT_ENCODER_CHANNEL_B);
	leftEncoder = new Encoder(LEFT_ENCODER_CHANNEL_A, LEFT_ENCODER_CHANNEL_B);
	driveGyro = new ADXRS450_Gyro();
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

void Drive::Arcade(double speed, double turn, double editedGyroAngle) {
	// sstd::cout << "Angle: " + std::to_string(editedGyroAngle) << std::endl;
	SmartDashboard::PutNumber("Gyro Angle", editedGyroAngle);
	double gyroScaleFactor = SmartDashboard::GetNumber("gyroScaleFactor", 0.1);
	if (fabs(turn) > JOYSTICK_STANDARD_DRIFT) {
		drive.ArcadeDrive(speed, turn);
	} else {
		std::cout << "using editedangle" + std::to_string(gyroScaleFactor) + " angle: " + std::to_string(editedGyroAngle) << std::endl;
		drive.ArcadeDrive(speed, editedGyroAngle * gyroScaleFactor);
	}
	// std::cout << "Speed:"+std::to_string(speed) + " Turn:"+std::to_string(turn) << std::endl;
}

void Drive::Tank(double left, double right) {
	drive.TankDrive(left, right);
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

double Drive::GetLeftEncoderValue(){
	return leftEncoder->GetRaw();
}

double Drive::GetRightEncoderValue(){
	return rightEncoder->GetRaw();
}

Encoder* Drive::GetLeftEncoder(){
	return leftEncoder;
}

Encoder* Drive::GetRightEncoder(){
	return rightEncoder;
}

ADXRS450_Gyro* Drive::GetDriveGyro(){
	return driveGyro;
}
