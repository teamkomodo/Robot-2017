#ifndef TeleopControl_H
#define TeleopControl_H

#define reverseButtonIndex	1

#include "../definitions.h"
#include "CommandBase.h"
#include "WPILib.h"

class Drive;
class TeleopControl : public CommandBase {
private:
	Joystick *leftJoystick;
	Joystick *rightJoystick;
	Drive* driveSubsystem;
	ADXRS450_Gyro* driveGyro;

	bool driveReverse;

public:
	TeleopControl();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};



#endif  // TeleopControl_H
