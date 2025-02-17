// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

// ARM LAYOUT
// Hand Motor
// Claw Pnumatic
// Shoulder Motor

// Shoulder Encoder
// 

#include "Robot.h"

#include <iostream>

void Robot::RobotInit() {
    m_chooser.SetDefaultOption(kAutoNameDefault, kAutoNameDefault);
    m_chooser.AddOption(kAutoNameCustom, kAutoNameCustom);

    frc::SmartDashboard::PutNumber("press", 0);

    frc::SmartDashboard::PutData("Auto Modes", &m_chooser);

    front_right_motor.RestoreFactoryDefaults();
    back_right_motor.RestoreFactoryDefaults();
    front_left_motor.RestoreFactoryDefaults();
    back_left_motor.RestoreFactoryDefaults();
}

/**
 * This function is called every 20 ms, no matter the mode. Use
 * this for items like diagnostics that you want ran during disabled,
 * autonomous, teleoperated and test.
 *
 * <p> This runs after the mode specific periodic functions, but before
 * LiveWindow and SmartDashboard integrated updating.
 */
void Robot::RobotPeriodic() {}

/**
 * This autonomous (along with the chooser code above) shows how to select
 * between different autonomous modes using the dashboard. The sendable chooser
 * code works with the Java SmartDashboard. If you prefer the LabVIEW Dashboard,
 * remove all of the chooser code and uncomment the GetString line to get the
 * auto name from the text box below the Gyro.
 *
 * You can add additional auto modes by adding additional comparisons to the
 * if-else structure below with additional strings. If using the SendableChooser
 * make sure to add them to the chooser code above as well.
 */
void Robot::AutonomousInit() {
    m_autoSelected = m_chooser.GetSelected();
    m_autoSelected = frc::SmartDashboard::GetString("Auto Selector", kAutoNameDefault);

    fmt::print("Auto selected: {}\n", m_autoSelected);

    if (m_autoSelected == kAutoNameCustom) {
        // Custom Auto goes here
    } else {
        // Default Auto goes here
  }
}

void Robot::AutonomousPeriodic() {
    if (m_autoSelected == kAutoNameCustom) {
        // Custom Auto goes here
    } else {
        // Default Auto goes here
  }
}

void Robot::TeleopInit() {}

void Robot::TeleopPeriodic() {
    frc::SmartDashboard::PutNumber("press", 0);

    drive_train.DriveCartesian(drive_joystick.get_x(), drive_joystick.get_y(), drive_joystick.get_twist());

    if (button_1.is_active())
    {
        frc::SmartDashboard::PutNumber("press", 1);
        std::cout << "Active!" << std::endl;
    }

    if (button_2.is_active())
    {  
        std::cout << "B2 Active!" << std::endl;

        if (button_1.disabled)
        {
            button_1.enable();
        }
        else
        {
            button_1.disable();   
        }
    }
}

void Robot::DisabledInit() {}

void Robot::DisabledPeriodic() {}

void Robot::TestInit() {}

void Robot::TestPeriodic() {}

void Robot::SimulationInit() {}

void Robot::SimulationPeriodic() {}

#ifndef RUNNING_FRC_TESTS
int main() {
    return frc::StartRobot<Robot>();
}
#endif
