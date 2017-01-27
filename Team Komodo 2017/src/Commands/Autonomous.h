#ifndef Autonomous_H
#define Autonomous_H

#include <Commands/CommandGroup.h>
#include "WaitForDuration.h"
#include "LiftForDuration.h"

class Autonomous : public CommandGroup {
public:
	Autonomous();
};

#endif  // Autonomous_H
