/*
 * CommandBase.h
 *
 *  Created on: Jan 17, 2017
 *      Author: Daniel
 */

#ifndef SRC_COMMANDBASE_H_
#define SRC_COMMANDBASE_H_



#include <memory>
#include <string>
#include <cstddef>

// #include <Commands/Command.h>
// #include <Commands/Scheduler.h>

#include "OI.h"

#include "Subsystems/Drive.h"
#include "Subsystems/Lift.h"
#include "Subsystems/BallManipulator.h"

class CommandBase : public frc::Command {
private:
//	static std::unique_ptr<Drive> driveSubsystem;
//	static std::unique_ptr<Lift> lifterSubsystem;
//	static std::unique_ptr<BallManipulator> ballManipulatorSubsystem;
//	static std::unique_ptr<OI> oi;
public:
	CommandBase(const std::string& name);
	CommandBase() = default;

	static Drive* retrieveDriveSubsystem();
	static Lift* retrieveLiftSubsystem();
	static BallManipulator* retrieveBallManipulatorSubsystem();
	static OI* retrieveOperatorInterface();
	static Hopper* retrieveHopperSubsystem();

};



#endif /* SRC_COMMANDBASE_H_ */
