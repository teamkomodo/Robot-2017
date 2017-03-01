#ifndef SwitchDriveReverse_H
#define SwitchDriveReverse_H

#include "../CommandBase.h"

class SwitchDriveReverse : public CommandBase {
private:
	bool shouldStop = false;
public:
	SwitchDriveReverse();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // SwitchDriveReverse_H
