
#include <Arduino.h>
#include "sensor.h"
#include "response.h"
#include "lib/MS5837.h"

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

	/* DEPTH SENSOR */

	void Depth::setDensity(float density) {
		this->sensor.init();
		this->sensor.setFluidDensity(density);
	}

	void Depth::update() {
		if (this->state) {
			sensor.read();
			Response::sensor_depth(sensor.depth());
			this->state = false;
		}
	}
}