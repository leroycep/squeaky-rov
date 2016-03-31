
#ifndef _ROBOT_H_
#define _ROBOT_H_

#include <Arduino.h>
#include "motor.h"
#include "sensor.h"

#define MAX_MOTORS 8
#define MAX_SENSORS 1

namespace Robot {
	class Robot {
		static Robot* s_instance;
		int stepper_step_pin;
		int stepper_dir_pin;
		int stepper_enabled_pin;
		int stepper_steps;
		Motor** motors;
		Sensor::Voltage* voltage_sensor;
		Sensor::Temperature* temperature_sensor;
		Sensor::Depth* depth_sensor;
		int multiplexerPaPins[4];
		int multiplexerRePins[4];
		Robot();

	  public:
		void setMultiplexerPaPins(int, int, int, int);
		void setMultiplexerRePins(int, int, int, int);
		void controlMultiplexerPa(int);
		void controlMultiplexerRe(int);
		void setStepperPins(int, int, int);
		void controlStepper(bool, int);
		void setStepperEnabled(bool);
		Motor* getMotor(int);
		Sensor::Voltage* getVoltageSensor();
		Sensor::Temperature* getTemperatureSensor();
		Sensor::Depth* getDepthSensor();
		void update();
		static Robot* instance();
	};
}

#endif