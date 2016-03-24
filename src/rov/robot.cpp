
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