#ifndef WaitForDuration_H
#define WaitForDuration_H

#include "WPILIB.h"
#include "Commands/TimedCommand.h"

class WaitForDuration : public TimedCommand {
public:
	WaitForDuration(double timeout);
	void Initialize();
	void Execute();
	void End();
	void Interrupted();
};

#endif  // WaitForDuration_H
