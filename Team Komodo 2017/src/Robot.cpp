#include "WPILib.h"
#include "definitions.h"

// #include <CameraServer.h>
#include <Subsystems/Lift.h>

#include "CommandBase.h"

#include "Commands/TeleopControl.h"

#include "Subsystems/Lift.h"
#include "Subsystems/Drive.h"
#include "Commands/TeleopControl.h"
#include "Commands/HopperWithGamepad.h"
#include "Commands/LiftWithGamepad.h"
#include "Commands/ResetHopper.h"

#include "Commands/ConveyorButtonControl.h"
#include "Commands/DriveForwardDistance.h"


/**
 * The code for Team Komodo's 2017 robot.
 *
 * Author: Team Komodo 2017 Programming Team
 *         	 (Alex Jones, Sean Kelly, Max Davy, Daniel Chao)
 *
 * Add your name above
 */
class Robot: public frc::IterativeRobot {
public:
	void RobotInit();
	void DisabledInit();
	void DisabledPeriodic();

	void AutonomousInit();
	void AutonomousPeriodic();

	void TeleopInit();
	void TeleopPeriodic();

	void TestPeriodic();

private:

};


/**
 * Called when the robot is first started up.
 * The camera would be initialized here it but it is currently not on the robot.
 * I'm going to add the camera to see if it will cause the code to fail
 */
void Robot::RobotInit() {
	SmartDashboard::PutNumber("gyroDriftValue", 0.035);
	SmartDashboard::PutNumber("gyroRushSpeed", 30);
	SmartDashboard::PutNumber("gyroScaleFactor", 0.11);
	SmartDashboard::PutNumber("autonomousDistance", 66);
	SmartDashboard::PutNumber("autonomousPosition (1=left 2=center 3=right", CENTER_POSITION);
//	Start camera streaming
	cs::UsbCamera camera = CameraServer::GetInstance()->StartAutomaticCapture();
//	make sure the resolution is high enough *this has not been tested
	camera.SetResolution(896, 504);
//	SmartDashboard::PutNumber("Drive Mode Input", 1);
}

/**
 * Called every time the robot starts the autonomous period.
 */

void Robot::DisabledInit() {

}

/**
 * Updates the robot while disabled.
 */
void Robot::DisabledPeriodic() {
}

/**
 * Called every time the robot starts the autonomous period.
 * Previously, this would stop running commands but because the scheduler works
 *    by running each command one time and then stopping(until the TeleopPeriodic()runs again (apprx 20 Hz or so)
 *    Thus we don't need to stop the commands before autonomous.
 */
void Robot::AutonomousInit() {
	Scheduler::GetInstance()->RemoveAll();
	Scheduler::GetInstance()->AddCommand(new DriveForwardDistance);
	Scheduler::GetInstance()->AddCommand(new ResetHopper);
	std::cout << "Starting Autonomous" << std::endl;
}

/**
 * Updates the robot when in the autonomous period.
 */
void Robot::AutonomousPeriodic() {
	Scheduler::GetInstance()->Run();
}

/**
 * Called every time the robot starts the teleop period.
 */
void Robot::TeleopInit() {
	// You don't need to manually start the default command of a subsystem
	// Experimentally confirmed 1/26/17 Max + Daniel
	// Apparently you actually do, just don't put it in TeleopPeriodic
	// or it will create a new TeleopControl object every 20 milliseconds 02/18/17 Max
	Scheduler::GetInstance()->RemoveAll();
	Scheduler::GetInstance()->AddCommand(new TeleopControl);
	Scheduler::GetInstance()->AddCommand(new LiftWithGamepad);
	Scheduler::GetInstance()->AddCommand(new HopperWithGamepad);
	Scheduler::GetInstance()->AddCommand(new ConveyorButtonControl);
}

/**
 * Updates the robot when in the teleop period.
 */
void Robot::TeleopPeriodic() {
	// For some reason I had to explicitly add TeleopControl to the Scheduler.
	//even though it is the default command of the Drive subsystem
	//and the default command of the lift subsystem, LiftWithGamepad, was getting
	//run without me having to add it. 01/27/17 Max
	//Cancel that. It caused big problems 02/18/17 Max

	Scheduler::GetInstance()->Run();
}

/**
 * Updates the robot when in the test period.
 */
void Robot::TestPeriodic() {
	// LiveWindow::GetInstance()->Run();
}

START_ROBOT_CLASS(Robot)
