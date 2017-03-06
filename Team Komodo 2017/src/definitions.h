#ifndef SRC_DEFINITIONS_H_
#define SRC_DEFINITIONS_H_


// gamepad stuff
#define GAMEPAD_3_INPUT_CHANNEL		2
#define GAMEPAD_2_INPUT_CHANNEL		1
#define GAMEPAD_1_INPUT_CHANNEL		0

#define JOYSTICK_X_CORRECTION		.75

#define GAMEPAD_1_STICK_X			0
#define GAMEPAD_1_STICK_Y			1

#define GAMEPAD_2_STICK_X			0
#define GAMEPAD_2_STICK_Y			1

#define GAMEPAD_3_LSTICK_X			0
#define GAMEPAD_3_LSTICK_Y			1

#define GAMEPAD_3_RSTICK_X			4
#define GAMEPAD_3_RSTICK_Y			5

#define DRIVE_MODE					2//1 = tank, 2 = arcade 3 = split arcade

//motor channels
#define WINCH_OUTPUT_CHANNEL		4
#define LEFT_DRIVE_OUTPUT_CHANNEL	0
#define RIGHT_DRIVE_OUTPUT_CHANNEL	1
#define CONVEYOR_OUTPUT_CHANNEL		3
#define HOPPER_OUTPUT_CHANNEL		2

#define LEFT_ENCODER_CHANNEL_A		0
#define LEFT_ENCODER_CHANNEL_B		1

#define RIGHT_ENCODER_CHANNEL_A		2
#define RIGHT_ENCODER_CHANNEL_B		3

#define HOPPER_ENCODER_CHANNEL_A	4
#define HOPPER_ENCODER_CHANNEL_B	5

#define HOPPER_LIMIT_SWITCH_CHANNEL	6
//other
#define ENCODER_VALUES_PER_INCH		329.083//experimentally confirmed
#define ROBOT_WIDTH_INCHES			23//confirmed
#define HOPPER_MAXIMUM_ENCODER		16000//experimentally confirmed

//gyro drive stuff
#define JOYSTICK_STANDARD_DRIFT     .25
#define GYRO_SCALE_FACTOR 			0.00	//was .09
#define GYRO_DRIFT_VALUE            0.01
#define GYRO_RUSH_SPEED				30

#endif /* DEBUG_SRC_DEFINITIONS_H_ */
