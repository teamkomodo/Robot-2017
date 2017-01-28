#ifndef Drive_H
#define Drive_H

#include <Commands/Subsystem.h>
#include "WPILib.h"
#include "../definitions.h"

class TeleopControl;
class Drive : public Subsystem {
private:
	RobotDrive drive {LEFT_DRIVE_OUTPUT_CHANNEL, RIGHT_DRIVE_OUTPUT_CHANNEL};

public:
	Drive();
	void InitDefaultCommand() override;

	void Forward(int speed);
	void Backward(int speed);
	void Left(double amt);
	void Right(double amt);
	void Arcade(int y, int x);
	void Stop();
};



#endif  // Drive_H
