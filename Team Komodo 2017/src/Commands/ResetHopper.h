#ifndef ResetHopper_H
#define ResetHopper_H

#include "../definitions.h"
#include "CommandBase.h"
#include "WPILib.h"

class ResetHopper : public CommandBase {
private:
	bool isDone = false;
	int step = 1;
	Hopper* hopperSubsystem;
public:
	ResetHopper();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // ResetHopper_H
