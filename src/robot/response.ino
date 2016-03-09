
/// !!! LOGGING !!!

void response_log_error(String message) {
	Serial.write(0x10); // Response id 'log_error'
	Serial.write(message.length()); // Write the number of bytes in the message
	Serial.write(message); // Write the message
}

void response_log_warning(String message) {
	Serial.write(0x11); // Response id 'log_warning'
	Serial.write(message.length()); // Write the number of bytes in the message
	Serial.write(message); // Write the message
}

void response_log_info(String message) {
	Serial.write(0x12); // Response id 'log_info'
	Serial.write(message.length()); // Write the number of bytes in the message
	Serial.write(message); // Write the message
}

void response_log_debug(String message) {
	Serial.write(0x13); // Response id 'log_debug'
	Serial.write(message.length()); // Write the number of bytes in the message
	Serial.write(message); // Write the message
}

/// !!! SENSORS !!!

void response_sensor_voltage(int voltage) {
	Serial.write(0x20); // Response id 'sensor_voltage'
	Serial.write((byte)voltage>>24);
	Serial.write((byte)voltage>>16);
	Serial.write((byte)voltage>>8);
	Serial.write((byte)voltage);
}