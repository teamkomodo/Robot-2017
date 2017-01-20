/*
 * CommandBase.h
 *
 *  Created on: Jan 17, 2017
 *      Author: Daniel
 */

#ifndef SRC_COMMANDBASE_H_
#define SRC_COMMANDBASE_H_



#include <Subsystems/Lift.h>
#include <memory>
#include <string>

// #include <Commands/Command.h>
// #include <Commands/Scheduler.h>

#include "OI.h"
#include "Subsystems/Drive.h"

class CommandBase : public frc::Command {
public:
	CommandBase(const std::string& name);
	CommandBase() = default;

	static std::unique_ptr<Drive> driveSubsystem;
	static std::unique_ptr<Lift> lifterSubsystem;
	static std::unique_ptr<OI> oi;

};



#endif /* SRC_COMMANDBASE_H_ */
