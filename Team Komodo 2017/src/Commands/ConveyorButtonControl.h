#ifndef ConveyorButtonControl_H
#define ConveyorButtonControl_H



#include "CommandBase.h"
#include "WPILib.h"


class ConveyorButtonControl : public CommandBase {
private:
	Joystick *gamePad;
	BallManipulator* ballManipulatorSubsystem;

public:
	ConveyorButtonControl();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};



#endif  // ConveyorButtonControl_H
