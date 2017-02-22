#ifndef HopperWithGamepad_H
#define HopperWithGamepad_H

#include "../CommandBase.h"

class HopperWithGamepad : public CommandBase {
private:
	Joystick *gamePad;
	Encoder *encoder;
	Hopper* hopperSubsystem;
	BallManipulator *ballManipulatorSubsystem;
public:
	HopperWithGamepad();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // HopperWithGamepad_H
