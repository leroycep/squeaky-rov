
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
			this->total += raw;
			count++;
		}
		if (millis() >= this->nextSend) {
			Response::sensor_temperature(this->total/count);
			total = 0;
			count = 0;
			this->nextSend = millis() + 100;
		}
	}

	/* DEPTH SENSOR */

	void Depth::setDensity(float density) {
		this->sensor.init();
		this->sensor.setFluidDensity(density);
	}

	void Depth::update() {
		if (this->state) {
			this->sensor.read();
			Response::sensor_depth(this->sensor.depth());
			this->state = false;
		}
	}
}