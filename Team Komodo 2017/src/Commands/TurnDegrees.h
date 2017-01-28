#ifndef TurnDegrees_H
#define TurnDegrees_H

#include "../CommandBase.h"

class TurnDegrees : public CommandBase {
private:
	bool isDone = false;
	Drive* driveSubsystem;
public:
	TurnDegrees();
	void Initialize();
	void Execute(float degreesToTurn, bool turnLeft);
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // TurnDegrees_H
