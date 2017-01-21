/*
 * CommandBase.cpp
 *
 *  Created on: Jan 17, 2017
 *      Author: Daniel
 */

#include <CommandBase.h>

std::unique_ptr<Drive> CommandBase::driveSubsystem = std::make_unique<Drive>();
std::unique_ptr<Lift> CommandBase::lifterSubsystem = std::make_unique<Lift>();
std::unique_ptr<BallManipulator> CommandBase::ballManipulatorSubsystem =
		std::make_unique<BallManipulator>();

std::unique_ptr<OI> CommandBase::oi = std::make_unique<OI>();


CommandBase::CommandBase(const std::string &name) : frc::Command(name) {
	// Literally worthless.
}
