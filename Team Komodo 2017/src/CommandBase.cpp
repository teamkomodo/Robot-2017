/*
 * CommandBase.cpp
 *
 *  Created on: Jan 17, 2017
 *      Author: Daniel
 */

#include <CommandBase.h>

// std::unique_ptr<Drive> CommandBase::driveSubsystem = std::make_unique<Drive>();
/*std::unique_ptr<Lift> CommandBase::lifterSubsystem = std::make_unique<Lift>();
std::unique_ptr<BallManipulator> CommandBase::ballManipulatorSubsystem =
		std::make_unique<BallManipulator>();

std::unique_ptr<OI> CommandBase::oi = std::make_unique<OI>();*/

CommandBase::CommandBase(const std::string &name) : frc::Command(name) {
	// Literally worthless.
}

Drive* CommandBase::retrieveDriveSubsystem() {
	static std::unique_ptr<Drive> driveSubsystem;
	if(!driveSubsystem) {
		driveSubsystem = std::make_unique<Drive>();
	}
	return driveSubsystem.get();
}

Lift* CommandBase::retrieveLiftSubsystem() {
	static std::unique_ptr<Lift> liftSubsystem;
	if(!liftSubsystem) {
		liftSubsystem = std::make_unique<Lift>();
	}
	return liftSubsystem.get();

}

BallManipulator* CommandBase::retrieveBallManipulatorSubsystem() {
	static std::unique_ptr<BallManipulator> ballManipulatorSubsystem;
	if(!ballManipulatorSubsystem) {
		ballManipulatorSubsystem = std::make_unique<BallManipulator>();
	}
	return ballManipulatorSubsystem.get();
}
OI* CommandBase::retrieveOperatorInterface() {
	static std::unique_ptr<OI> oi;
	if(!oi) {
		oi = std::make_unique<OI>();
	}
	return oi.get();
}
