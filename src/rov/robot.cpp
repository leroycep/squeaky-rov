
#include "robot.h"
#include "response.h"

namespace Robot {
	Robot::Robot() {
		motors = new Motor*[MAX_MOTORS];
		for (int i=0; i<MAX_MOTORS; i++) {
			motors[i] = new Motor();
		}

		voltage_sensor = new Sensor::Voltage();
		temperature_sensor = new Sensor::Temperature();
		depth_sensor = new Sensor::Depth();
	}

	void Robot::setMultiplexerPaPins(int pa, int re, int ci, int vo) {
		multiplexerPaPins[0] = pa;
		multiplexerPaPins[1] = re;
		multiplexerPaPins[2] = ci;
		multiplexerPaPins[3] = vo;
		pinMode(multiplexerPaPins[0], OUTPUT);
		pinMode(multiplexerPaPins[1], OUTPUT);
		pinMode(multiplexerPaPins[2], OUTPUT);
		pinMode(multiplexerPaPins[3], OUTPUT);
	}

	void Robot::setMultiplexerRePins(int pa, int re, int ci, int vo) {
		multiplexerRePins[0] = pa;
		multiplexerRePins[1] = re;
		multiplexerRePins[2] = ci;
		multiplexerRePins[3] = vo;
		pinMode(multiplexerRePins[0], OUTPUT);
		pinMode(multiplexerRePins[1], OUTPUT);
		pinMode(multiplexerRePins[2], OUTPUT);
		pinMode(multiplexerRePins[3], OUTPUT);
	}

	void Robot::controlMultiplexerPa(int camera) {
		digitalWrite(multiplexerPaPins[0], (camera & 0x1) == 0x1);
		digitalWrite(multiplexerPaPins[1], (camera & 0x2) == 0x2);
		digitalWrite(multiplexerPaPins[2], (camera & 0x4) == 0x4);
		digitalWrite(multiplexerPaPins[3], (camera & 0x8) == 0x8);
	}

	void Robot::controlMultiplexerRe(int camera) {
		digitalWrite(multiplexerRePins[0], (camera & 0x1) == 0x1);
		digitalWrite(multiplexerRePins[1], (camera & 0x2) == 0x2);
		digitalWrite(multiplexerRePins[2], (camera & 0x4) == 0x4);
		digitalWrite(multiplexerRePins[3], (camera & 0x8) == 0x8);
	}

	void Robot::setStepperPins(int direction_pin, int step_pin, int enable_pin) {
		stepper_dir_pin = direction_pin;
		stepper_step_pin = step_pin;
		stepper_enabled_pin = enable_pin;
		pinMode(stepper_dir_pin, OUTPUT);
		pinMode(stepper_step_pin, OUTPUT);
		pinMode(stepper_enabled_pin, OUTPUT);
	}

	void Robot::controlStepper(bool direction, bool running) {
		digitalWrite(stepper_dir_pin, direction);
		analogWrite(stepper_step_pin, running ? 0xFF : 0x00);
	}

	void Robot::setStepperEnabled(bool enabled) {
		digitalWrite(stepper_enabled_pin, !enabled);
	}

	Motor* Robot::getMotor(int id) {
		if (id >= MAX_MOTORS) {
			Response::log_warning("Invalid motor id "+String(id));
		}
		return motors[id];
	}

	Sensor::Voltage* Robot::getVoltageSensor() {
		return voltage_sensor;
	}

	Sensor::Temperature* Robot::getTemperatureSensor() {
		return temperature_sensor;
	}

	Sensor::Depth* Robot::getDepthSensor() {
		return depth_sensor;
	}

	void Robot::update() {
		for (int i=0; i<MAX_MOTORS; i++) {
			motors[i]->update();
		}
		voltage_sensor->update();
		temperature_sensor->update();
		depth_sensor->update();
	}

	Robot* Robot::instance() {
		if(!s_instance)
			s_instance = new Robot();
		return s_instance;
	}
}