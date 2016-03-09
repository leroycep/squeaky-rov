// Constants

#define RESPONSE_LOG_ERROR 0x10
#define RESPONSE_LOG_WARNING 0x11
#define RESPONSE_LOG_INFO 0x12
#define RESPONSE_LOG_DEBUG 0x13
#define RESPONSE_SENSOR_VOLTAGE 0x20

/// !!! LOGGING !!!

void response_log_error(String message) {
	Serial.write(RESPONSE_LOG_ERROR); // Response id 'log_error'
	Serial.write(message.length()); // Write the number of bytes in the message
	Serial.write(message.length()); // Write the message
}

void response_log_warning(String message) {
	Serial.write(RESPONSE_LOG_WARNING); // Response id 'log_warning'
	Serial.write(message.length()); // Write the number of bytes in the message
	Serial.write(message.length()); // Write the message
}

void response_log_info(String message) {
	Serial.write(RESPONSE_LOG_INFO); // Response id 'log_info'
	Serial.write(message.length()); // Write the number of bytes in the message
	Serial.write(message.length()); // Write the message
}

void response_log_debug(String message) {
	Serial.write(RESPONSE_LOG_DEBUG); // Response id 'log_debug'
	Serial.write(message.length()); // Write the number of bytes in the message
	Serial.write(message.length()); // Write the message
}

/// !!! SENSORS !!!

void response_sensor_voltage(int voltage) {
	Serial.write(RESPONSE_SENSOR_VOLTAGE); // Response id 'sensor_voltage'
	Serial.write((byte)voltage>>24);
	Serial.write((byte)voltage>>16);
	Serial.write((byte)voltage>>8);
	Serial.write((byte)voltage);
}