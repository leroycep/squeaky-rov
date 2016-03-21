
#include <Arduino.h>
#include "sensor.h"
#include "response.h"

namespace Sensor {
	void Sensor::setState(bool state) {
		this->state = state;
	}

	void Voltage::setPin(int pin) {
		this->pin = pin;
		pinMode(pin, INPUT);
	}

	void Voltage::update(void){
		if (state) {
			int raw = analogRead(pin);
			Response::sensor_voltage(raw);
		}
	}
}