/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Command.h>

class AutoDrive : public frc::Command {
 public:
  AutoDrive(double distance, bool isStrafe);
  void Initialize() override;
  void Execute();
  bool IsFinished();
  void End() override;
  void Interrupted() override;
  private:
  bool isStrafing;
  int currentTicks;
  double m_distance;
};
