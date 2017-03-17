#ifndef TurnLeftDegrees_H
#define TurnLeftDegrees_H

#include "../CommandBase.h"
#include "WPIlib.h"

class TurnLeftDegrees : public CommandBase {
private:
	Drive* driveSubsystem;
	double degrees;
	bool isDone = false;
	double inchesToEncoders(double inches);
	double degreesToEncoders(double degrees);
public:
	TurnLeftDegrees(double degrees);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // TurnLeftDegrees_H
