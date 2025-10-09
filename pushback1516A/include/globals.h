#pragma once

#include "api.h"
#include "lemlib/api.hpp"
#include "pros/motors.h"

namespace Robot {
    namespace Globals {

        // Controller
        extern pros::Controller controller;

        // Motor ports
        extern signed char LEFT_BACK;
        extern signed char LEFT_MID;
        extern signed char LEFT_FRONT;

        extern signed char RIGHT_BACK;
        extern signed char RIGHT_MID;
        extern signed char RIGHT_FRONT;

        // Motor groups
        extern pros::MotorGroup left;
        extern pros::MotorGroup right;

        // Drivetrain
        extern lemlib::Drivetrain drivetrain;

        // Odometry / Sensors
        extern lemlib::OdomSensors sensors;

        // PID Controllers
        extern lemlib::ControllerSettings lateralPID;
        extern lemlib::ControllerSettings angularPID;

        // Drive curve
        extern lemlib::ExpoDriveCurve throttleCurve;
        extern lemlib::ExpoDriveCurve steerCurve;

        // Chassis
        extern lemlib::Chassis chassis;
    }
}
