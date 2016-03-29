
#include <Arduino.h>
#include "sensor.h"
#include "response.h"

namespace Sensor {
	void Sensor::setState(bool state) {
		this->state = state;
	}


	/* VOLTAGE SENSOR */

	void Voltage::setPin(int pin) {
		this->pin = pin;
		pinMode(pin, INPUT);
	}

	void Voltage::update() {
		if (this->state) {
			int raw = analogRead(this->pin);
			Response::sensor_voltage(raw);
		}
	}

	/* TEMPERATURE SENSOR */

	void Temperature::setPin(int pin) {
		this->pin = pin;
		pinMode(pin, INPUT);
	}

	void Temperature::update() {
		if (this->state) {
			int raw = analogRead(this->pin);
			Response::sensor_temperature(raw);
		}
	}
}