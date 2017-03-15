#ifndef DriveForwardDistance_H
#define DriveForwardDistance_H

#include "../definitions.h"
#include "CommandBase.h"
#include "WPILib.h"

class DriveForwardDistance : public CommandBase {
private:
	bool isDone = false;
	double distanceInches;
	double reverseDistanceInches;
	int autoCount;
	double waitTime;
	int editedGyroAngle;
	Drive* driveSubsystem;
	ADXRS450_Gyro* driveGyro;
public:
	DriveForwardDistance();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // DriveForwardDistance_H
