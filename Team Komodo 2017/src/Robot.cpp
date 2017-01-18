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
	Joystick gamePad2;//initialize accessory gamepad
	Joystick gamePad1;//initialize drive gamepad
	Talon liftMotor;//initialize lift motor


public:
	/**
	 * runs once at the beginning of the program
	 */
	void RobotInit() {
		cs::UsbCamera camera = CameraServer::GetInstance()->StartAutomaticCapture();//Start camera streaming
		camera.SetResolution(640, 480);//make sure the resolution is high enough *this has not been tested
		}
	Robot() :
		gamePad2(GAMEPAD_2_INPUT_CHANNEL),
		gamePad1()
		liftMotor(WINCH_OUTPUT_CHANNEL),
		myRobot(LEFT_DRIVE_OUTPUT_CHANNEL, RIGHT_DRIVE_OUTPUT_CHANNEL)//set the channels for the gamepad and lift motor
	{
		myRobot.SetExpiration(0.1);
	}

	/**
	 * This loops while the robot is running
	 */
	void OperatorControl() {
		while (IsOperatorControl() && IsEnabled()) {
			liftMotor.SetSpeed(gamePad2.GetRawAxis(GAMEPAD_RIGHT_STICK_Y));//set the lift motor speed to the vertical position of the right joystick
			myRobot.ArcadeDrive(gamePad.GetRawAxis(GAMEPAD_LEFT_STICK_Y),-gamePad.GetRawAxis(GAMEPAD_LEFT_STICK_X));//set the forward speed of the bot to the vertical position of the left joystick and the turn angle to the horizontal position
			//myRobot.ArcadeDrive(stick); // drive with arcade style (use right stick)
			frc::Wait(0.005);			// wait for a motor update time
		}
	}
};

START_ROBOT_CLASS(Robot)
