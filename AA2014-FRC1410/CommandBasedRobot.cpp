#include "WPILib.h"
#include "Commands/Command.h"
#include "CommandBase.h"
#include "Commands/Autonomous/HotFirst.h"
#include "Commands/Autonomous/NotHotFirst.h"

class CommandBasedRobot : public IterativeRobot {
private:
	//Command *autonomousCommand;
	LiveWindow *lw;
	NetworkTable *table;
	Command *hotAutoCom;
	Command *notHotAutoCom;
	
	virtual void RobotInit() {
		CommandBase::init();
		//autonomousCommand = new Command();
		hotAutoCom = new HotFirst();
		notHotAutoCom = new NotHotFirst();
		lw = LiveWindow::GetInstance();
		table = NetworkTable::GetTable("SmartDashboard");
	}
	
	virtual void AutonomousInit() {
			if(table->GetBoolean("Target", false))
			{
				if(table->GetBoolean("Hot", false))
				{
					printf("Auto Hot\n");
					hotAutoCom->Start();
				}
				else
				{
					printf("Auto Not Hot\n");
					notHotAutoCom->Start();
				}
			}
			else
			{
				printf("No Target\n");
			}
	}
	
	virtual void AutonomousPeriodic() {
		Scheduler::GetInstance()->Run();
	}
	
	virtual void TeleopInit() {
		// This makes sure that the autonomous stops running when
		// teleop starts running. If you want the autonomous to 
		// continue until interrupted by another command, remove
		// this line or comment it out.
		//autonomousCommand->Cancel();
		hotAutoCom->Cancel();
		notHotAutoCom->Cancel();
	}
	
	virtual void TeleopPeriodic() {
		Scheduler::GetInstance()->Run();
	}
	
	virtual void TestPeriodic() {
		lw->Run();
	}
};

START_ROBOT_CLASS(CommandBasedRobot);

