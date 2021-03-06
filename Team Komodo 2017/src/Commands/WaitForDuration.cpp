#include "WaitForDuration.h"
#include "WPILIB.h"

//Timeout (in seconds!) but with millisecond granularity
WaitForDuration::WaitForDuration(double timeout) : TimedCommand(timeout) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void WaitForDuration::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void WaitForDuration::Execute() {
	std::cout << "Hello?" << std::endl;
	SmartDashboard::PutString("AUTON_STATUS", "Waiting for autonomous. Nothing is currently running.");
}

// Called once after command times out
void WaitForDuration::End() {
	SmartDashboard::PutString("AUTON_STATUS", "Command finished.");

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void WaitForDuration::Interrupted() {

}
