
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
		bool stepper_previous_direction;
		Motor** motors;
		Sensor::Voltage* voltage_sensor;
		Sensor::Temperature* temperature_sensor;
		int multiplexerPins[4];
		Robot();

	  public:
		void setMultiplexerPins(int, int, int, int);
		void setStepperPins(int, int, int);
		void controlStepper(bool);
		void setStepperEnabled(bool);
		Motor* getMotor(int);
		Sensor::Voltage* getVoltageSensor();
		Sensor::Temperature* getTemperatureSensor();
		void update();
		static Robot* instance();
	};
}

#endif