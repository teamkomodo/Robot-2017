#ifndef ReverseDistance_H
#define ReverseDistance_H

#include "../CommandBase.h"
#include "WPIlib.h"

class ReverseDistance : public CommandBase {
private:
	bool isDone = false;
	//distances are now in definitions.h

	int editedGyroAngle;
	double inches;

	Drive* driveSubsystem;
	ADXRS450_Gyro* driveGyro;

public:
	ReverseDistance(double inches);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	double inchesToEncoders(double inches);
	double degreesToEncoders(double degrees);
};

#endif  // ReverseDistance_H
