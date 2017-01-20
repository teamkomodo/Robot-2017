#ifndef TeleopControl_H
#define TeleopControl_H



#include "../CommandBase.h"
#include "../definitions.h"


class TeleopControl : public CommandBase {
private:
	Joystick *gamePad1;

public:
	TeleopControl();
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;
};



#endif  // TeleopControl_H
