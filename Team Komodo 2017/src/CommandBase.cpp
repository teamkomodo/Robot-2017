/*
 * CommandBase.cpp
 *
 *  Created on: Jan 17, 2017
 *      Author: Daniel
 */

#include <CommandBase.h>
#include <Commands/Scheduler.h>

std::unique_ptr<Drive> drive = std::make_unique<Drive>();

CommandBase::CommandBase(const std::string &name) :
	frc::Command(name) {

}
