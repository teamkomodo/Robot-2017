#ifndef DriveForwardDistance_H
#define DriveForwardDistance_H

#include "../definitions.h"
#include "CommandBase.h"
#include "WPILib.h"

class DriveForwardDistance : public CommandBase {
private:
	bool isDone = false;
	int distanceInches;
	Drive* driveSubsystem;
public:
	DriveForwardDistance(float inches);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // DriveForwardDistance_H
