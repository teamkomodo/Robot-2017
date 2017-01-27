#ifndef LiftWithGamepad_H
#define LiftWithGamepad_H



#include "../CommandBase.h"

/**
 * Uses joystick 1, probably not what you'd actually want
 * considering the drive also uses it too.
 * Feel free to change it
 */
class LiftWithGamepad : public CommandBase {
private:
	Joystick *gamePad;
	Lift* lifterSubsystem;

public:
	LiftWithGamepad();
	void Initialize() override;
	void Execute() override;
	bool IsFinished() override;
	void End() override;
	void Interrupted() override;
};



#endif  // LiftWithGamepad_H
