/*
 * CommandBase.h
 *
 *  Created on: Jan 17, 2017
 *      Author: Daniel
 */

#ifndef SRC_COMMANDBASE_H_
#define SRC_COMMANDBASE_H_

#include "WPILib.h"

#include <memory>
#include <string>

class CommandBase : frc::Command {
public:
	CommandBase(const std::string& name);
	CommandBase() = default;

	static std::unique_ptr<Drive> drive;
	static std::unique_ptr<OI> oi;

};


#endif /* SRC_COMMANDBASE_H_ */
