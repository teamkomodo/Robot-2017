/*
 * CommandBase.cpp
 *
 *  Created on: Jan 17, 2017
 *      Author: Daniel
 */

#include <CommandBase.h>
#include <Commands/Scheduler.h>

#include "Subsystems/Drive.h"
#include "Subsystems/RobotLifter.h"




Drive *CommandBase::driveSubsystem = new Drive();
RobotLifter *CommandBase::lifterSubsystem = new RobotLifter();

std::unique_ptr<OI> CommandBase::oi = std::make_unique<OI>();


CommandBase::CommandBase(const std::string &name) : frc::Command(name) {
	// Literally worthless.
}
