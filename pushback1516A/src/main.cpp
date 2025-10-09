#include "main.h"
#include "globals.h"
#include "lemlib/api.hpp"
#include "pros/motors.h"

using namespace Robot::Globals;
using namespace Robot;

/**
 * A callback function for LLEMU's center button.
 *
 * When this callback is fired, it will toggle line 2 of the LCD text between
 * "I was pressed!" and nothing.
 */
void on_center_button() {
	static bool pressed = false;
	pressed = !pressed;
	if (pressed) {
		pros::lcd::set_text(2, "I was pressed!");
	} else {
		pros::lcd::clear_line(2);
	}
}

/**
 * Runs initialization code. This occurs as soon as the program is started.
 *
 * All other competition modes are blocked by initialize; it is recommended
 * to keep execution time for this mode under a few seconds.
 */
void initialize() {
	//Basic intitialization of the screen
	pros::lcd::initialize();

	pros::lcd::print(1, "Calibrating IMU...");
    sensors.imu->reset(); // start calibration

    while (sensors.imu->is_calibrating()) {
        pros::delay(20);
    }

	pros::lcd::set_text(1, "Team 1516A");
	//Add button to screen
	pros::lcd::register_btn1_cb(on_center_button);

	chassis.calibrate();
	chassis.setPose({0, 0, 0});

}

/**
 * Runs while the robot is in the disabled state of Field Management System or
 * the VEX Competition Switch, following either autonomous or opcontrol. When
 * the robot is enabled, this task will exit.
 */
void disabled() {}

/**
 * Runs after initialize(), and before autonomous when connected to the Field
 * Management System or the VEX Competition Switch. This is intended for
 * competition-specific initialization routines, such as an autonomous selector
 * on the LCD.
 *
 * This task will exit when the robot is enabled and autonomous or opcontrol
 * starts.
 */
void competition_initialize() {}

/**
 * Runs the user autonomous code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the autonomous
 * mode. Alternatively, this function may be called in initialize or opcontrol
 * for non-competition testing purposes.
 *
 * If the robot is disabled or communications is lost, the autonomous task
 * will be stopped. Re-enabling the robot will restart the task, not re-start it
 * from where it left off.
 */
void autonomous() {}

/**
 * Runs the operator control code. This function will be started in its own task
 * with the default priority and stack size whenever the robot is enabled via
 * the Field Management System or the VEX Competition Switch in the operator
 * control mode.
 *
 * If no competition control is connected, this function will run immediately
 * following initialize().
 *
 * If the robot is disabled or communications is lost, the
 * operator control task will be stopped. Re-enabling the robot will restart the
 * task, not resume it from where it left off.
 */
void opcontrol() {
	double heading = sensors.imu->get_heading();         // 0–360 degrees             // side tilt
	while (true) {
		//Drivetrain Block
		heading = sensors.imu->get_heading();         // 0–360 degrees             // side tilt
		chassis.arcade(controller.get_analog(ANALOG_LEFT_Y), -controller.get_analog(ANALOG_RIGHT_X));

		// // Print out the sensor values to the controller screen
        pros::lcd::print(0, "Head: %.2f", heading);

		pros::delay(10);                          // Run for 10 ms then update
		// pros::lcd::clear();
	}
}