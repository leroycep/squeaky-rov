
#include "sensor_voltage.h"
#include <Arduino.h>
#include "../response.h"

namespace Sensor {
	void Voltage::update(void){
		int raw = analogRead(pin);
		Response::sensor_voltage(raw);
	}
}