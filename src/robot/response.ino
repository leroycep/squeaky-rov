

void respond_log_error(String message) {
	Serial.write(0x10); // Response id 'log_error'
	Serial.write(message.length()); // Write the number of bytes in the message
	Serial.write(message); // Write the message
}

void respond_log_warning(String message) {
	Serial.write(0x11); // Response id 'log_warning'
	Serial.write(message.length()); // Write the number of bytes in the message
	Serial.write(message); // Write the message
}

void respond_log_info(String message) {
	Serial.write(0x12); // Response id 'log_info'
	Serial.write(message.length()); // Write the number of bytes in the message
	Serial.write(message); // Write the message
}

void respond_log_debug(String message) {
	Serial.write(0x13); // Response id 'log_debug'
	Serial.write(message.length()); // Write the number of bytes in the message
	Serial.write(message); // Write the message
}