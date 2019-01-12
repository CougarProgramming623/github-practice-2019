/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/Drive.h"

Drive::Drive() {
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
  Requires(Robot::driveTrain.get());
  joystick.reset(new Joystick(0));
}

// Called just before this Command runs the first time
void Drive::Initialize() {
  y = x = rot = angle = 0;
}

// Called repeatedly when this Command is scheduled to run
void Drive::Execute() {
  y = joystick->GetY();
  x = joystick->GetX();
  rot = joystick->GetX();
  angle = Robot::driveTrain->getNavx().get()->GetAngle();

  Robot::driveTrain->fodDrive(y, x, rot, angle);
}

// Make this return true when this Command no longer needs to run execute()
bool Drive::IsFinished() { return false; }

// Called once after isFinished returns true
void Drive::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Drive::Interrupted() {}
