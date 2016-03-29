// Constants
#include <Arduino.h>
#include "response.h"

namespace Response {
	/// !!! LOGGING !!!
	void log_error(String message) {
		Serial.write(RESPONSE_LOG_ERROR); // Response id 'log_error'
		Serial.write(message.length()); // Write the number of bytes in the message
		Serial.print(message); // Write the message
	}

	void log_warning(String message) {
		Serial.write(RESPONSE_LOG_WARNING); // Response id 'log_warning'
		Serial.write(message.length()); // Write the number of bytes in the message
		Serial.print(message); // Write the message
	}

	void log_info(String message) {
		Serial.write(RESPONSE_LOG_INFO); // Response id 'log_info'
		Serial.write(message.length()); // Write the number of bytes in the message
		Serial.print(message); // Write the message
	}

	void log_debug(String message) {
		Serial.write(RESPONSE_LOG_DEBUG); // Response id 'log_debug'
		Serial.write(message.length()); // Write the number of bytes in the message
		Serial.print(message); // Write the message
	}

	/// !!! SENSORS !!!
	void sensor_voltage(int voltage) {
		Serial.write(RESPONSE_SENSOR_VOLTAGE); // Response id 'sensor_voltage'
		Serial.write((voltage>>24) & 0xFF);
		Serial.write((voltage>>16) & 0xFF);
		Serial.write((voltage>>8) & 0xFF);
		Serial.write((voltage) & 0xFF);
	}

	void sensor_temperature(int temperature) {
		Serial.write(RESPONSE_SENSOR_TEMPERATURE); // Response id 'sensor_temperature'
		Serial.write((temperature>>24) & 0xFF);
		Serial.write((temperature>>16) & 0xFF);
		Serial.write((temperature>>8) & 0xFF);
		Serial.write((temperature) & 0xFF);
	}
}