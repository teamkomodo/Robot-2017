#ifndef BallManipulator_H
#define BallManipulator_H



#include <Commands/Subsystem.h>
#include "WPILib.h"
#include "definitions.h"


class BallManipulator : public Subsystem {
private:
	VictorSP conveyorBeltMotor {CONVEYOR_OUTPUT_CHANNEL};

public:
	BallManipulator();
	void InitDefaultCommand();

	void run();
	void runBackward();
	void stop();
};


#endif  // BallManipulator_H
