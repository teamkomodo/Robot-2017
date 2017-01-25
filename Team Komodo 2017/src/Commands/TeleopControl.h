#ifndef TeleopControl_H
#define TeleopControl_H



#include "../CommandBase.h"
#include "../definitions.h"


class TeleopControl : public CommandBase {
private:
	Joystick *gamePad1;

public:
	TeleopControl();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};



#endif  // TeleopControl_H
