#include "WPILib.h"
#include "definitions.h"

#include <CameraServer.h>
#include <Subsystems/Lift.h>

#include "CommandBase.h"



/**
 * The code for Team Komodo's 2017 robot.
 *
 * Author: Team Komodo 2017 Programming Team
 *         	 (Alex Jones, Sean Kelly, Max D, Daniel Chao)
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
 */
void Robot::RobotInit() {
//	//Start camera streaming
//	cs::UsbCamera camera = CameraServer::GetInstance()->StartAutomaticCapture();
//	//make sure the resolution is high enough *this has not been tested
//	camera.SetResolution(640, 480);
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
}

/**
 * Updates the robot when in the autonomous period.
 */
void Robot::AutonomousPeriodic() {
}

/**
 * Called every time the robot starts the teleop period.
 */
void Robot::TeleopInit() {
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
