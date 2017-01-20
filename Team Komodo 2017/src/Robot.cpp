#include "WPILib.h"
#include "definitions.h"

#include <CameraServer.h>
#include <Subsystems/Lift.h>

#include "CommandBase.h"

#include "Subsystems/Drive.h"
#include "Commands/TeleopControl.h"
#include "Commands/LiftWithGamepad.h"



/**
 * The code for Team Komodo's 2017 robot.
 *
 * Originally said some shit about SampleRobot
 * Figured it was time to update that
 *
 * Author: Team Komodo 2017 Programming Team
 *         	 (Alex Jones,
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
	Command *teleopDriveCommand;
	Command *liftGamepadControlCommand;
};






/**
 * Called when the robot is first started up.
 */
void Robot::RobotInit() {
	teleopDriveCommand = new TeleopControl();
	liftGamepadControlCommand = new LiftWithGamepad();

	//Start camera streaming
	cs::UsbCamera camera = CameraServer::GetInstance()->StartAutomaticCapture();
	//make sure the resolution is high enough *this has not been tested
	camera.SetResolution(640, 480);
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
	// Scheduler::GetInstance()->Run();
}

/**
 * Called every time the robot starts the autonomous period.
 */
void Robot::AutonomousInit() {
	// Makes sure the commands stop running when autonomous starts
	teleopDriveCommand->Cancel();
	liftGamepadControlCommand->Cancel();
}

/**
 * Updates the robot when in the autonomous period.
 */
void Robot::AutonomousPeriodic() {
	// The Autonomous period should be a CommandGroup and not be utilizing the Scheduler
	// Scheduler::GetInstance()->Run();
}

/**
 * Called every time the robot starts the teleop period.
 */
void Robot::TeleopInit() {
	//I'm pretty sure that the following isn't really needed because the Scheduler will start them
	//But I'm not sure

	// Gets the commands up and runnin'
	// teleopDriveCommand->Start();
	// liftGamepadControlCommand->Start();
}

/**
 * Updates the robot when in the teleop period.
 */
void Robot::TeleopPeriodic() {
	Scheduler::GetInstance()->Run();
}

/**
 * Updates the robot when in the test period.
 */
void Robot::TestPeriodic() {
	LiveWindow::GetInstance()->Run();
}





START_ROBOT_CLASS(Robot)
