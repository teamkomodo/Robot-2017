#include "Hopper.h"
#include "../definitions.h"
#include "WPILib.h"

Hopper::Hopper() : Subsystem("Hopper") {
	HopperEncoder = new Encoder(CONVEYOR_ENCODER_CHANNEL_A, CONVEYOR_ENCODER_CHANNEL_B);
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
