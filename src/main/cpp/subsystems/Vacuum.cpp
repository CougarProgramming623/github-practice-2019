/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Vacuum.h"

Vacuum::Vacuum() : Subsystem("Vacuum") {
victor.reset(new WPI_VictorSPX(15));


}

void Vacuum::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}
void Vacuum::SetVacuumSpeed( double speed) {
victor->Set(speed);
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
