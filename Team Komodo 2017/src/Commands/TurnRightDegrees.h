#ifndef TurnRightDegrees_H
#define TurnRightDegrees_H

#include "../CommandBase.h"
#include "WPIlib.h"

class TurnRightDegrees : public CommandBase {
private:
	Drive* driveSubsystem;
	double degrees;
	double inchesToEncoders(double inches);
	double degreesToEncoders(double degrees);
	bool isDone = false;
public:
	TurnRightDegrees(double degrees);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // TurnRightDegrees_H
