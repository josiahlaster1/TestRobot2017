// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#include "Drivecommand.h"

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

Drivecommand::Drivecommand(): Command() {
    // Use requires() here to declare subsystem dependencies
    // eg. requires(Robot::chassis.get());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	Requires(Robot::drivebasesub.get());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=REQUIRES
	XAxis = 0;
	YAxis = 0;
	RotAxis =0;
}
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTRUCTOR

// Called just before this Command runs the first time
void Drivecommand::Initialize() {
	XAxis = 0;
	YAxis = 0;
	RotAxis =0;
}

// Called repeatedly when this Command is scheduled to run
void Drivecommand::Execute() {
	XAxis = Robot::oi->getdriverJoystick()->GetRawAxis(0);
	YAxis = Robot::oi->getdriverJoystick()->GetRawAxis(1);
	RotAxis = Robot::oi->getdriverJoystick()->GetRawAxis(4);

	if(XAxis > -0.20 && XAxis < 0.20)
	{
		XAxis =0;
	}
	else
	{
		XAxis = XAxis * fabs(XAxis);
	}

	if(YAxis > -0.20 && YAxis < 0.20)
	{
		YAxis = 0;
	}
	else
	{
		YAxis =YAxis * fabs(YAxis);
	}

	if(RotAxis > -0.20 && RotAxis <0.20)
	{
		RotAxis = 0;
	}
	else
	{
		RotAxis = RotAxis * fabs(RotAxis);
	}

	Robot::drivebasesub->MecanumDrive(XAxis, YAxis, RotAxis, 0);
}

// Make this return true when this Command no longer needs to run execute()
bool Drivecommand::IsFinished() {
    return false;
}

// Called once after isFinished returns true
void Drivecommand::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Drivecommand::Interrupted() {

}
