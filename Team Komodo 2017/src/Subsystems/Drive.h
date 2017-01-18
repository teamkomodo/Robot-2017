#ifndef Drive_H
#define Drive_H

#include <Commands/Subsystem.h>
#include "WPILib.h"
#include "Robot.cpp"

class Drive : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	RobotDrive _drive = new RobotDrive(LEFT_DRIVE_OUTPUT_CHANNEL, RIGHT_DRIVE_OUTPUT_CHANNEL);


public:
	Drive();
	void InitDefaultCommand();
	void Forward(int speed);
	void Backward(int speed);
	void Left(double amt);
	void Right(double amt);
	void Arcade(int y, int x);
	void Stop();
};

#endif  // Drive_H
