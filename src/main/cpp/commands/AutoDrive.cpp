/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/
#define TICKS_PER_INCH 19.33570146
#define S_TICKS_PER_INCH 27.8538459
#include "commands/AutoDrive.h"
#include "Robot.h"

AutoDrive::AutoDrive(double distance, bool isStrafe) {
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
  isStrafing = isStrafe;
  m_distance = distance;
  Requires(Robot::driveTrain.get());
  //SetTimeout(3);
  currentTicks = abs(Robot::driveTrain->GetTicks());
}

// Called just before this Command runs the first time
void AutoDrive::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void AutoDrive::Execute() {
  if(isStrafing){
  Robot::driveTrain->fodDrive(0.0, 0.5, 0.0, Robot::navx->GetYaw());
  } else {
  Robot::driveTrain->fodDrive(0.5, 0.0, 0.0, Robot::navx->GetYaw());
  }
  DriverStation::ReportError("Ticks Driven " + std::to_string(abs(Robot::driveTrain->GetTicks()-currentTicks)));
}

// Make this return true when this Command no longer needs to run execute()
bool AutoDrive::IsFinished() {
  double maxTicks;
  if(isStrafing) {
     maxTicks = S_TICKS_PER_INCH*m_distance;
  } else {
     maxTicks = TICKS_PER_INCH*m_distance;
  }
  int ticks = abs(Robot::driveTrain->GetTicks()-currentTicks);
  return ticks >= maxTicks;
  //return IsTimedOut(); 

}

// Called once after isFinished returns true
void AutoDrive::End() {
  int TicksDriven = abs(Robot::driveTrain->GetTicks()-currentTicks);
  DriverStation::ReportError("Ticks Driven: " + std::to_string(TicksDriven));
  Robot::driveTrain->fodDrive(0.0, 0.0, 0.0, Robot::navx->GetYaw());
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoDrive::Interrupted() {}
