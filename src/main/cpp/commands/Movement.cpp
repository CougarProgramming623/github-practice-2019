/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Robot.h"
#include "commands/Turn.h"
#include "commands/AutoDrive.h"
#include "commands/Strafe.h"
#include "commands/Movement.h"

Movement::Movement() {
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
  AddSequential(new AutoDrive(1));
  AddSequential(new Turn(Robot::navx->GetYaw() + 90.0));
  AddSequential(new Strafe(1));
}

// Called just before this Command runs the first time
void Movement::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void Movement::Execute() {}

// Make this return true when this Command no longer needs to run execute()
bool Movement::IsFinished() { return false; }

// Called once after isFinished returns true
void Movement::End() {
  Robot::driveTrain->fodDrive(0.0, 0.0, 0.0, 0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Movement::Interrupted() {}
