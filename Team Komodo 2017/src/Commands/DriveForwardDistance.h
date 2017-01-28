#ifndef DriveForwardDistance_H
#define DriveForwardDistance_H

#include "../definitions.h"
#include "CommandBase.h"
#include "WPILib.h"

class DriveForwardDistance : public CommandBase {
private:
	bool isDone = false;
	Drive* driveSubsystem;
public:
	DriveForwardDistance();
	void Initialize();
	void Execute(float inches);
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // DriveForwardDistance_H
