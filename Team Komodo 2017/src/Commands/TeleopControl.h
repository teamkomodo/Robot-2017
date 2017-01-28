#ifndef TeleopControl_H
#define TeleopControl_H


#include "../definitions.h"
#include "CommandBase.h"
#include "WPILib.h"

class Drive;
class TeleopControl : public CommandBase {
private:
	Joystick *gamePad;
	Drive* driveSubsystem;
	bool driveReverse;
	bool buttonDone;
	int reverseButtonIndex;

public:
	TeleopControl();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};



#endif  // TeleopControl_H
