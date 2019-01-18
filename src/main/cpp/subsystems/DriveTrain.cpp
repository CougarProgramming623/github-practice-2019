/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/
/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/DriveTrain.h"

std::shared_ptr<frc::Joystick> DriveTrain::joystick;

DriveTrain::DriveTrain() : Subsystem("ExampleSubsystem") {
  joystick.reset(new frc::Joystick(0));
  leftFront.reset(new WPI_TalonSRX(0));
  leftBack.reset(new WPI_TalonSRX(1));
  rightFront.reset(new WPI_TalonSRX(2));
  rightBack.reset(new WPI_TalonSRX(3));
  mech.reset(new frc::MecanumDrive(*leftFront,*leftBack,*rightFront,*rightBack));
}

void DriveTrain::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());

}

void DriveTrain::drive(double y,double x,double i,double rot){
  mech->DriveCartesian(y,x,i,rot);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
