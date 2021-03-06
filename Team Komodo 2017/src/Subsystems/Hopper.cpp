/*
 * Created 01/28/17 by Max Davy
 */
#include "Hopper.h"
#include "../definitions.h"
#include "WPILib.h"

Hopper::Hopper() : Subsystem("Hopper") {
	HopperEncoder = new Encoder(HOPPER_ENCODER_CHANNEL_A, HOPPER_ENCODER_CHANNEL_B);

}

void Hopper::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

void Hopper::run(float speed) {
	// We might want a constant for the speed
	// 1 is probably not the speed we want
	HopperMotor.SetSpeed(speed);
}

void Hopper::stop() {
	HopperMotor.SetSpeed(0);
}

Encoder* Hopper::getEncoder(){
	return HopperEncoder;
}

bool Hopper::isLimitSwitchPressed(){
	return limitSwitch.GetValue()>1000;
}
