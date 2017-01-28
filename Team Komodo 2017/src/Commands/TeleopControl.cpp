#include "TeleopControl.h"
#include "../Subsystems/Drive.h"
#include "../CommandBase.h"


TeleopControl::TeleopControl() : CommandBase("TeleopControl") {
	// Use Requires() here to declare subsystem dependencies
	driveSubsystem = CommandBase::retrieveDriveSubsystem();
	driveReverse = false;
	buttonDone = true;
	reverseButtonIndex = 5;
	Requires(driveSubsystem);

	gamePad = CommandBase::retrieveOperatorInterface()->getJoystick1();
}

// Called just before this Command runs the first time
void TeleopControl::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void TeleopControl::Execute(){
	/*if(gamePad1->GetRawButton(reverseButtonIndex) == true && buttonDone == false){
		buttonDone = true;
		std::cout << "buttonDone = true;" << std::endl;
		SmartDashboard::PutString("Button State", "buttonDone = true;");
	}
	else if (gamePad1->GetRawButton(reverseButtonIndex) == false && buttonDone == true){
		buttonDone = false;
		std::cout << "buttonDone = false;" << std::endl;
		SmartDashboard::PutString("Button State", "buttonDone = false;");
	}
	driveSubsystem->Arcade(gamePad1->GetRawAxis(GAMEPAD_1_STICK_Y),
						   gamePad1->GetRawAxis(GAMEPAD_1_STICK_X));
						   */
	if(gamePad->GetRawButton(1)){
		std::cout << "buttonDone = true" << std::endl;
		SmartDashboard::PutString("Button State", "buttonDone = true");
	}else{
		std::cout << "buttonDone = false;" << std::endl;
		SmartDashboard::PutString("Button State", "buttonDone = false;");
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
