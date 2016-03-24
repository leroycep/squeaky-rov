
#include "robot.h"

namespace Robot {
	Robot::Robot() {
		motors = new Motor*[MAX_MOTORS];
		for (int i=0; i<MAX_MOTORS; i++) {
			motors[i] = new Motor();
		}

		voltage_sensor = new Sensor::Voltage();
	}

	void Robot::setMultiplexerPins(int one, int two, int three, int four) {
		multiplexerPins[0] = one;
		multiplexerPins[1] = two;
		multiplexerPins[2] = three;
		multiplexerPins[3] = four;
	}

	void Robot::setStepperPins(int direction_pin, int step_pin) {
		stepper_dir_pin = direction_pin;
		stepper_step_pin = step_pin;
		pinMode(stepper_dir_pin, OUTPUT);
		pinMode(stepper_step_pin, OUTPUT);
	}

	void Robot::controlStepper(bool direction) {
		if (stepper_previous_direction != direction) {
			digitalWrite(stepper_dir_pin, direction);
			delay(1);
		}
		digitalWrite(stepper_step_pin, LOW);
		digitalWrite(stepper_step_pin, HIGH);
		stepper_previous_direction = direction;
	}

	Motor* Robot::getMotor(int id) {
		return motors[id];
	}

	Sensor::Voltage* Robot::getVoltageSensor() {
		return voltage_sensor;
	}

	void Robot::update() {
		for (int i=0; i<MAX_MOTORS; i++) {
			motors[i]->update();
		}
		voltage_sensor->update();
	}

	Robot* Robot::instance() {
		if(!s_instance)
			s_instance = new Robot();
		return s_instance;
	}
}