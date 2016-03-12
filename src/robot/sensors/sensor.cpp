
#include <Arduino.h>
#include "sensor.h"

namespace Sensor {
	void Sensor::setPin(int p) {
		pin = p;
		pinMode(p, INPUT);
	}

	void Sensor::setState(bool on) {
		state = on;
	}

	void Sensor::update() {
	}
}