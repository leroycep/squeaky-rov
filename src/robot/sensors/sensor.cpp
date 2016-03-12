
#include "sensor.h"

void Sensor::setPin(byte p) {
	pin = p;
	setOutput(p, INPUT);
}

void Sensor::setState(bool on) {
	state = on;
}

void Sensor::update() {
}