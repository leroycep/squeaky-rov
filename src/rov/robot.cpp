
#include "robot.h"
#include "sensors/sensor_voltage.h"

namespace Robot {
	Robot::Robot() {
		maxPWM = 175;
		minPWM = 10;
		safety_timeout = 2;

		motors = new Motor*[CONFIGURE_MAX_MOTORS];
		for (int i=0; i<CONFIGURE_MAX_MOTORS; i++) {
			motors[i] = new Motor();
		}

		sensors = new Sensor::Sensor*[CONFIGURE_MAX_SENSORS];
		sensors[0] = new Sensor::Voltage();
	}

	void Robot::setPWMBounds(int low, int high) {
		minPWM = low;
		maxPWM = high;
	}

	void Robot::setSafetyTimeout(int timeout) {
		safety_timeout = timeout;
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

	Sensor::Sensor* Robot::getSensor(int id) {
		return sensors[id];
	}

	void Robot::update() {
		for (int i=0; i<CONFIGURE_MAX_MOTORS; i++) {
			motors[i]->update();
		}
		// TODO: Implement sensor updating later
	}
}