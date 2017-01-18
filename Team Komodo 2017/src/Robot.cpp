#include "WPILib.h"
#include "definitions.h"
#include <CameraServer.h>

/**
 * This is a demo program showing the use of the RobotDrive class.
 * The SampleRobot class is the base of a robot application that will automatically call your
 * Autonomous and OperatorControl methods at the right time as controlled by the switches on
 * the driver station or the field controls.
 *
 * WARNING: While it may look like a good choice to use for your code if you're inexperienced,
 * don't. Unless you know what you are doing, complex code will be much more difficult under
 * this system. Use IterativeRobot or Command-Based instead if you're new.
 */
class Robot: public frc::IterativeRobot {
	RobotDrive myRobot;  // robot drive system
	Joystick gamePad;//initialize gamepad
	Talon liftMotor;//initialize lift motor
	int leftStickX = 0;
	int leftStickY = 0;
	int rightStickX = 0;
	int rightStickY = 0;

public:
	/**
	 * runs once at the beginning of the program
	 */
	Robot() :
			gamePad(GAMEPAD_INPUT_CHANNEL),
			liftMotor(WINCH_OUTPUT_CHANNEL),
			myRobot(LEFT_DRIVE_OUTPUT_CHANNEL, RIGHT_DRIVE_OUTPUT_CHANNEL)//set the channels for the gamepad and lift motor
	{
			myRobot.SetExpiration(0.1);
	}

	void RobotInit() {
		cs::UsbCamera camera = CameraServer::GetInstance()->StartAutomaticCapture();//Start camera streaming
		camera.SetResolution(640, 480);//make sure the resolution is high enough *this has not been tested
	}

	void TeleopPeriodic() {
		liftMotor.SetSpeed(rightStickX);
		myRobot.ArcadeDrive(leftStickY, leftStickX);
	}

	void TeleopContinuous() {
		leftStickX = gamePad.GetRawAxis(GAMEPAD_LEFT_STICK_X);
		leftStickY = gamePad.GetRawAxis(GAMEPAD_LEFT_STICK_Y);
		leftStickX = gamePad.GetRawAxis(GAMEPAD_RIGHT_STICK_X);
		leftStickY = gamePad.GetRawAxis(GAMEPAD_RIGHT_STICK_Y);
	}
};

START_ROBOT_CLASS(Robot)
