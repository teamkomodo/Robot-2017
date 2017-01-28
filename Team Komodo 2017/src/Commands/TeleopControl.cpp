#include "TeleopControl.h"
#include "../Subsystems/Drive.h"
#include "../CommandBase.h"


TeleopControl::TeleopControl() : CommandBase("TeleopControl") {
	// Use Requires() here to declare subsystem dependencies
	driveSubsystem = CommandBase::retrieveDriveSubsystem();
	driveReverse = false;//used to tell if the robot is in reverse mode
	buttonPressed = false;//used in the code to prevent repeat button presses.
	Requires(driveSubsystem);

	gamePad = CommandBase::retrieveOperatorInterface()->getJoystick1();
}

// Called just before this Command runs the first time
void TeleopControl::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void TeleopControl::Execute(){
	//code to prevent repeated button presses. I copied it from the 2016 code but couldn't get it to work. 01/27/17 Max
	/*if(gamePad->GetRawButton(reverseButtonIndex)== true && buttonPressed == false){
		buttonPressed = true;

		SmartDashboard::PutBoolean("driveReverse", driveReverse);
	} else if(gamePad->GetRawButton(reverseButtonIndex) == false && buttonPressed == true){
		buttonPressed = false;
	}*/
	if(gamePad->GetRawButton(reverseButtonIndex)){//if the button is pressed (currently the trigger on the driver joystick)
		driveReverse = !driveReverse;//reverse the reverse variable
	}
	if(driveReverse){//if we're in reverse mode
		driveSubsystem->Arcade(-gamePad->GetRawAxis(GAMEPAD_1_STICK_Y),
									   -gamePad->GetRawAxis(GAMEPAD_1_STICK_X));//drive is reversed (not the minuses)
		SmartDashboard::PutString("ReverseDrive Status:", "Activated");
	}else{
		driveSubsystem->Arcade(gamePad->GetRawAxis(GAMEPAD_1_STICK_Y),
									   gamePad->GetRawAxis(GAMEPAD_1_STICK_X));//otherwise drive is normal
		SmartDashboard::PutString("ReverseDrive Status:", "Normal");
	}
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
