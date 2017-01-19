#ifndef Drive_H
#define Drive_H



#include <Commands/Subsystem.h>
#include "WPILib.h"


class Drive : public Subsystem {
private:
	RobotDrive *drive;

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
