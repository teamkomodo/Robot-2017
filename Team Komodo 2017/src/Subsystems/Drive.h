#ifndef Drive_H
#define Drive_H

#include <Commands/Subsystem.h>
#include "WPILib.h"
#include "../definitions.h"

class TeleopControl;
class Drive : public Subsystem {
private:
	RobotDrive drive {LEFT_DRIVE_OUTPUT_CHANNEL, RIGHT_DRIVE_OUTPUT_CHANNEL};
	Encoder *leftEncoder;
	Encoder *rightEncoder;
	ADXRS450_Gyro *driveGyro;

public:
	Drive();
	void InitDefaultCommand() override;

	void Forward(double speed);
	void Backward(double speed);
	void Left(double amt);
	void Right(double amt);
	void Arcade(double y, double x, double editedGyroAngle);
	void Tank(double left, double right);
	void Stop();
	void ResetLeftEncoder();
	void ResetRightEncoder();
	double GetLeftEncoderValue();
	double GetRightEncoderValue();
	Encoder* GetLeftEncoder();
	Encoder* GetRightEncoder();
	ADXRS450_Gyro* GetDriveGyro();
};



#endif  // Drive_H
