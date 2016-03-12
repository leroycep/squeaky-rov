
#include <Arduino.h>
#include "sensor.h"
#include "../response.h"

namespace Sensor {
	void Sensor::setPin(int p) {
		pin = p;
		pinMode(p, INPUT);
	}

	void Sensor::setState(bool on) {
		state = on;
	}
}