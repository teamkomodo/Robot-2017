#ifndef BallManipulator_H
#define BallManipulator_H



#include <Commands/Subsystem.h>
#include "WPILib.h"


class BallManipulator : public Subsystem {
private:
	Talon conveyorBeltMotor {0};

public:
	BallManipulator();
	void InitDefaultCommand();

	void run();
	void stop();
};


#endif  // BallManipulator_H
