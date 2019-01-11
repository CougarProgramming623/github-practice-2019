/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/DriveTrain.h"

DriveTrain::DriveTrain() : Subsystem("DriveTrain") {
  mLeftFrontMC.reset(new WPI_TalonSRX(1));
  mRightFrontMC.reset(new WPI_TalonSRX(2));
  mLeftRearMC.reset(new WPI_TalonSRX(3));
  mRightRearMC.reset(new WPI_TalonSRX(4));
  mMecanumDrive.reset(new frc::MecanumDrive(*mLeftFrontMC, *mRightFrontMC,
    *mLeftRearMC, *mRightRearMC));
  try {
    navx.reset(new AHRS(SPI::Port::kMXP));
  } catch (std::exception &ex) {
    std::string err = "Error instantiating navX MXP: ";
    err += ex.what();
    DriverStation::ReportError(err.c_str());
  }
}

void DriveTrain::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
