
#include <Servo.h>

Servo gripper;
bool gripper_set = false;

void set_servo_pin(int pin)
{
	if (gripper_set)
	{
		gripper.detach();
	}
	gripper.attach(pin);
	gripper_set = true;
}

void control_servo(int pwm)
{
	if (gripper_set)
	{
		gripper.write(pwm);
	}
}

void sense_servo()
{
	if(gripper_set)
	{
		response_log_debug("Sense servo "+gripper.read());
	}
}