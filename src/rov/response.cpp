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
		Serial.write((byte)voltage>>24);
		Serial.write((byte)voltage>>16);
		Serial.write((byte)voltage>>8);
		Serial.write((byte)voltage);
	}

	void sensor_temperature(int temperature) {
		Serial.write(RESPONSE_SENSOR_TEMPERATURE); // Response id 'sensor_temperature'
		Serial.write((byte)temperature>>24);
		Serial.write((byte)temperature>>16);
		Serial.write((byte)temperature>>8);
		Serial.write((byte)temperature);
	}
}