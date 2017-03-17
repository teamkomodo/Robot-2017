#ifndef DriveForwardDistance_H
#define DriveForwardDistance_H

#include "../definitions.h"
#include "CommandBase.h"
#include "WPILib.h"

class DriveForwardDistance : public CommandBase {
private:
	bool isDone = false;
	//distances are now in definitions.h

	int editedGyroAngle;
	double inches;

	Drive* driveSubsystem;
	ADXRS450_Gyro* driveGyro;

public:
	DriveForwardDistance(double inches);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	double inchesToEncoders(double inches);
	double degreesToEncoders(double degrees);
};

#endif  // DriveForwardDistance_H
