#include "ArmDown.h"
#include "../../RobotMap.h"

ArmDown::ArmDown() {
	// Use requires() here to declare subsystem dependencies
	// eg. requires(chassis);
	Requires(intake);
	potangle = intake->PotAngle();
}

// Called just before this Command runs the first time
void ArmDown::Initialize() {
	
}

// Called repeatedly when this Command is scheduled to run
void ArmDown::Execute() {
	if(potangle > MIN_INTAKE_ANGLE){
		intake->SetSpeed(-0.5);
	}
	else{
		intake->SetSpeed(0);
	}
	
}

// Make this return true when this Command no longer needs to run execute()
bool ArmDown::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void ArmDown::End() {
	
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ArmDown::Interrupted() {
}