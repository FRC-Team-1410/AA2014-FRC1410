#include "CommandBase.h"
#include "Commands/Scheduler.h"
#include "Subsystems/Chassis.h"
/**
#include "Subsystems/Intake.h"
#include "Subsystems/Shooter.h"
#include "Subsystems/Elevator.h"
**/
CommandBase::CommandBase(const char *name) : Command(name) {
}

CommandBase::CommandBase() : Command() {
}

// Initialize a single static instance of all of your subsystems to NULL

OI* CommandBase::oi = NULL;
Chassis* CommandBase::chassis = NULL;
TestBedElevator* CommandBase::elev = NULL;
TestBedIntake* CommandBase::intake = NULL;
TestBedShooter* CommandBase::shooter = NULL;

void CommandBase::init() {
    // Create a single static instance of all of your subsystems. The following
	// line should be repeated for each subsystem in the project.
	
	oi = new OI();
	chassis = new Chassis();
	elev = new TestBedElevator();
	intake = new TestBedIntake();
	shooter = new TestBedShooter();
}
