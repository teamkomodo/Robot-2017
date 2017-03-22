#include "AutonomousLeft.h"
#include "WPIlib.h"
#include "definitions.h"
#include "DriveForwardDistance.h"
#include "TurnLeftDegrees.h"
#include "ReverseDistance.h"
#include "WaitForDuration.h"

AutonomousLeft::AutonomousLeft() {
	// Add Commands here:
	// e.g. AddSequential(new Command1());
	//      AddSequential(new Command2());
	AddSequential(new DriveForwardDistance(DISTANCE_BEFORE_TURN+2));
	AddSequential(new TurnLeftDegrees(60));
	AddSequential(new DriveForwardDistance(DISTANCE_AFTER_TURN-6));
	AddSequential(new WaitForDuration(3));
	AddSequential(new ReverseDistance(10));
	// these will run in order.

	// To run multiple commands at the same time,
	// use AddParallel()
	// e.g. AddParallel(new Command1());
	//      AddSequential(new Command2());
	// Command1 and Command2 will run in parallel.

	// A command group will require all of the subsystems that each member
	// would require.
	// e.g. if Command1 requires chassis, and Command2 requires arm,
	// a CommandGroup containing them would require both the chassis and the
	// arm.
}
