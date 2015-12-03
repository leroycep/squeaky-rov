

int camera_pins[4];

void set_camera_pins(int pin1, int pin2, int pin3, int pin4)
{
	camera_pins[0] = pin1;
	camera_pins[1] = pin2;
	camera_pins[2] = pin3;
	camera_pins[3] = pin4;
	for (int i = 0; i < 4; ++i)
	{
		pinMode(camera_pins[i], OUTPUT);
	}
}

void switch_camera(int camera)
{
	digitalWrite(camera_pins[0], camera & B0001);
	digitalWrite(camera_pins[1], camera & B0010);
	digitalWrite(camera_pins[2], camera & B0100);
	digitalWrite(camera_pins[3], camera & B1000);
}