#include "TeleopControl.h"
#include "../Subsystems/Drive.h"
#include "../CommandBase.h"


TeleopControl::TeleopControl() : CommandBase("TeleopControl") {
	// Use Requires() here to declare subsystem dependencies
	driveSubsystem = CommandBase::retrieveDriveSubsystem();
	driveReverse = false;//used to tell if the robot is in reverse mode
	buttonPressed = false;//used in the code to prevent repeat button presses.
	Requires(driveSubsystem);

	leftJoystick = CommandBase::retrieveOperatorInterface()->getLeftJoystick();
	rightJoystick = CommandBase::retrieveOperatorInterface()->getRightJoystick();
}

// Called just before this Command runs the first time
void TeleopControl::Initialize() {
	SmartDashboard::GetNumber("Drive Mode (1=Tank 2=Arcade 3=Split Arcade)", 1);
}

// Called repeatedly when this Command is scheduled to run
void TeleopControl::Execute(){
	if(leftJoystick->GetRawButton(reverseButtonIndex)){//if the button is pressed (currently the trigger on the driver joystick)
		driveReverse = !driveReverse;//toggle reverse mode
		if (driveReverse == true){
			SmartDashboard::PutString("ReverseDrive Status (Press left joystick trigger to toggle)", "Activated");
		}else{
			SmartDashboard::PutString("ReverseDrive Status (Press left joystick trigger to toggle)", "Normal");
		}
	}
	switch (SmartDashboard::GetNumber("Drive Mode (1=Tank 2=Arcade 3=Split Arcade)", 1)){
	case 1://tank drive
		SmartDashboard::PutString("Drive Mode", "Tank");
		if(driveReverse){//if we're in reverse mode
			//tank drive in reverse using the left and right joysticks
				driveSubsystem->Tank(leftJoystick->GetRawAxis(GAMEPAD_1_STICK_Y), rightJoystick->GetRawAxis(GAMEPAD_2_STICK_Y));
			}else{
				//tank drive forward using the left and right joysticks
				driveSubsystem->Tank(-leftJoystick->GetRawAxis(GAMEPAD_1_STICK_Y), -rightJoystick->GetRawAxis(GAMEPAD_2_STICK_Y));
			}
	break;
	case 2://arcade
		SmartDashboard::PutString("Drive Mode", "Arcade");
		if(driveReverse){//if we're in reverse mode
				//arcade drive in reverse using the left joystick
				driveSubsystem->Arcade(-leftJoystick->GetRawAxis(GAMEPAD_1_STICK_Y), leftJoystick->GetRawAxis(GAMEPAD_1_STICK_X));
			}else{
				//arcade drive forward using the left joystick
				driveSubsystem->Arcade(leftJoystick->GetRawAxis(GAMEPAD_1_STICK_Y), leftJoystick->GetRawAxis(GAMEPAD_1_STICK_X));
			}
	break;
	case 3://split arcade
	default:
		SmartDashboard::PutString("Drive Mode", "Split Arcade");
		if(driveReverse){//if we're in reverse mode
			//drive in reverse using split arcade (forward motion controlled by left gamepad y axis, turn controlled by right gamepad x axis)
			driveSubsystem->Arcade(-leftJoystick->GetRawAxis(GAMEPAD_1_STICK_Y), rightJoystick->GetRawAxis(GAMEPAD_2_STICK_X));
		}else{
			//drive forward using split arcade (forward motion controlled by left gamepad y axis, turn controlled by right gamepad x axis)
			driveSubsystem->Arcade(leftJoystick->GetRawAxis(GAMEPAD_1_STICK_Y), rightJoystick->GetRawAxis(GAMEPAD_2_STICK_X));
		}
	break;
	}
	//post encoder values to Smart Dashboard
	SmartDashboard::PutNumber("Left Encoder Value", driveSubsystem->GetLeftEncoderValue());
	SmartDashboard::PutNumber("Right Encoder Value", driveSubsystem->GetRightEncoderValue());
}


// Make this return true when this Command no longer needs to run execute()
bool TeleopControl::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void TeleopControl::End() {
	driveSubsystem->Stop();

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TeleopControl::Interrupted() {
	End();
}
