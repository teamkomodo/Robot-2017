#ifndef LiftForDuration_H
#define LiftForDuration_H

#include "../CommandBase.h"
#include "Commands/TimedCommand.h"


class LiftForDuration : public TimedCommand {
private:
	Lift* liftSubsystem;

public:
	LiftForDuration(double timeout);
	void Initialize();
	void Execute();
	void End();
	void Interrupted();
};

#endif  // LiftForDuration_H
