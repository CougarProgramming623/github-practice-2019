/*----------------------------------------------------------------------------*/
/* Copyright (c) 2018 FIRST. All Rights Reserved.                             */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/TimedRobot.h>
#include <frc/WPILib.h>
#include <subsystems/DriveTrain.h>
#include "AHRS.h"
#include "commands/Turn.h"

//eayfughiafewef rg eaifghwife

class Robot : public frc::TimedRobot {
 public:
  void RobotInit() override;
  void RobotPeriodic() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;

  void TeleopInit() override;
  void TeleopPeriodic() override;

  void TestInit() override;
  void TestPeriodic() override;
  static std::shared_ptr<DriveTrain> driveTrain;
  static AHRS *navx;
  std::unique_ptr<Command> autonomousCommand;
  static Joystick* joystick;
  static Joystick* buttonboard;
  private:
  JoystickButton* bb1;
  JoystickButton* bb2;
  JoystickButton* bb3;
  JoystickButton* bb4;

};
