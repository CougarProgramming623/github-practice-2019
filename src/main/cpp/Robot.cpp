/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/
/* clown crew
*/
#include "Robot.h"
#include <frc/DriverStation.h>


std::shared_ptr<DriveTrain> Robot::driveTrain;
AHRS *Robot::navx;
void Robot::RobotInit() {
    driveTrain.reset(new DriveTrain());
	  try {
      navx = new AHRS(SPI::Port::kMXP);
    } catch (std::exception &ex) {
      std::string err = "Error instantiating navX MXP: ";
      err += ex.what();
      DriverStation::ReportError(err.c_str());
  }
	navx->ZeroYaw();
}
//hello

void Robot::RobotPeriodic()
{
    DriverStation::ReportError(std::to_string(navx->GetYaw()));
}

//This is a very important comment! This will be merges into master soon!
void Robot::AutonomousInit() {
  Robot::navx->ZeroYaw();
  autonomousCommand.reset(new Turn(90.0f));
  if (autonomousCommand)
		autonomousCommand->Start();
}
void Robot::AutonomousPeriodic() {
  DriverStation::ReportError(std::to_string(navx->GetYaw()));
  frc::Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit() {}
void Robot::TeleopPeriodic() {
  DriverStation::ReportError(std::to_string(navx->GetYaw()));
	DriverStation::ReportError("TeleopPeriodic");
	frc::Scheduler::GetInstance()->Run();
}

void Robot::TestInit() {}
void Robot::TestPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
