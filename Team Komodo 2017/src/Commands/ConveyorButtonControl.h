#ifndef ConveyorButtonControl_H
#define ConveyorButtonControl_H



#include "../CommandBase.h"


class ConveyorButtonControl : public CommandBase {
private:
	Joystick *gamePad;
	int buttonID;
	BallManipulator* ballManipulatorSubsystem;

public:
	ConveyorButtonControl(int controlButtonID);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};



#endif  // ConveyorButtonControl_H
