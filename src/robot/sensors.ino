
int sensor_pin[16];
int sensor_state[16];
int last_update[16];

void update_sensors()
{
	if (sensor_state[SENSOR_VOLTAGE]>0)
	{
		sense_voltage();
		if (sensor_state[SENSOR_VOLTAGE]==2) sensor_state[SENSOR_VOLTAGE] = 0;
	}
	if (sensor_state[5]>0 && (millis() - last_update[5])>100) // servo
	{
		sense_servo();
		if (sensor_state[5]==2) sensor_state[5] = 0;
	}
}

void set_sensor_pin(int sensor, int pin)
{
	sensor_pin[sensor] = pin;
}

void set_sensor_state(int sensor, int state)
{
	sensor_state[sensor] = state;
}

void sense_voltage()
{
	int raw = analogRead(sensor_pin[SENSOR_VOLTAGE]);
	response_sensor_voltage(raw);
}