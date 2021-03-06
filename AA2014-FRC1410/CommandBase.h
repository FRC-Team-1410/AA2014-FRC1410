#ifndef COMMAND_BASE_H
#define COMMAND_BASE_H

#include "Commands/Command.h"
#include "OI.h"
#include "Subsystems/Chassis.h"
/**
#include "Subsystems/Intake.h"
#include "Subsystems/Shooter.h"
#include "Subsystems/Elevator.h"
**/
#include "Subsystems/Test/TestBedElevator.h"
#include "Subsystems/Test/TestBedIntake.h"
#include "Subsystems/Test/TestBedShooter.h"

/**
 * The base for all commands. All atomic commands should subclass CommandBase.
 * CommandBase stores creates and stores each control system. To access a
 * subsystem elsewhere in your code in your code use CommandBase.examplesubsystem
 */
class CommandBase: public Command {
public:
	CommandBase(const char *name);
	CommandBase();
	static void init();
	// Create a single static instance of all of your subsystems
	
	static Chassis *chassis;
	
	/**
	static Intake *intake;
	static Elevator *elev;
	static Shooter *shooter;
	**/
	
	static TestBedElevator *elev;
	static TestBedIntake *intake;
	static TestBedShooter *shooter;
	
	static OI *oi;
};

#endif
