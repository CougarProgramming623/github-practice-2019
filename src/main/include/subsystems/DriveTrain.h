/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Subsystem.h>
#include <frc/WPILib.h>
#include <ctre/Phoenix.h>
// #include <MecanumDrive.h>


class DriveTrain : public frc::Subsystem {
 private:
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities
  std::shared_ptr<WPI_TalonSRX> leftFront;
  std::shared_ptr<WPI_TalonSRX> rightFront;
  std::shared_ptr<WPI_TalonSRX> leftBack;
  std::shared_ptr<WPI_TalonSRX> rightBack;
  std::shared_ptr<frc::MecanumDrive> mech;
  
 public:
  DriveTrain();
  void InitDefaultCommand() override;
  void drive(double,double,double,double);
  static std::shared_ptr<frc::Joystick> joystick;
};
