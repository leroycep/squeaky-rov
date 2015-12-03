
#ifndef NUM_MOTOR_IDS
#define NUM_MOTOR_IDS 16 // possible motors
#endif

int motors_pin_a[NUM_MOTOR_IDS];
int motors_pin_b[NUM_MOTOR_IDS];
int motors_pin_pwm[NUM_MOTOR_IDS];

int motor_state_current[NUM_MOTOR_IDS]; // This will store the current motor state
unsigned long motor_state_time_set[NUM_MOTOR_IDS]; // This stores the last time the motor state was updated
unsigned long motor_state_instruction_recieved[NUM_MOTOR_IDS];
int motor_state_next[NUM_MOTOR_IDS]; // This will store what the next motor state should be

int maximum_pwm = 0;
int minimum_pwm = 0;
int safety_timeout = 2; // Just in case it isn't configured, we have a backup plan

void set_motor_pins(int id, int pin_a, int pin_b, int pin_pwm) {
	motors_pin_a[id] = pin_a;
	motors_pin_b[id] = pin_b;
	motors_pin_pwm[id] = pin_pwm;

	pinMode(pin_a, OUTPUT);
	pinMode(pin_b, OUTPUT);
	pinMode(pin_pwm, OUTPUT);
}

void set_motor(int id, bool a, bool b, int pwm) {
	if (abs(pwm) < minimum_pwm && pwm!=0)
	{
		pwm = minimum_pwm;
	}
	else if (abs(pwm) > maximum_pwm)
	{
		pwm = maximum_pwm;
	}
	if (!a && !b)
	{
		motor_state_next[id] = 0;
	}
	else if (a && b)
	{
		motor_state_next[id] = 0;
	}
	else
	{
		motor_state_next[id] = a ? (-pwm) : (pwm);
	}
	motor_state_instruction_recieved[id] = millis();
}

void set_minimum_pwm(int minimum)
{
	minimum_pwm = minimum;
}

void set_maximum_pwm(int maximum)
{
	maximum_pwm = maximum;
}

void set_safety_timeout(int timeout)
{
	safety_timeout = timeout;
}

void update_motors()
{
	for (int id = 0; id < NUM_MOTOR_IDS; ++id)
	{
		if (motor_state_current[id] == motor_state_next[id])
		{
			continue;
		}
		if (
			(motor_state_next[id] == 0) ||
			(motor_state_current[id] < 0 && motor_state_next[id] < 0) ||
			(motor_state_current[id] > 0 && motor_state_next[id] > 0)
			)
		{
			digitalWrite(motors_pin_a[id], motor_state_next[id] < 0);
			digitalWrite(motors_pin_b[id], motor_state_next[id] > 0);
			analogWrite(motors_pin_pwm[id], abs(motor_state_next[id]));
			motor_state_time_set[id] = millis();
			motor_state_current[id] = motor_state_next[id];
		}
		else
		{ 
			if (motor_state_instruction_recieved[id] > motor_state_time_set[id])
			{
				digitalWrite(motors_pin_a[id], 0);
				digitalWrite(motors_pin_b[id], 0);
				analogWrite(motors_pin_pwm[id], 0);
				motor_state_time_set[id] = millis();
			}
			else if(millis() - motor_state_time_set[id] > safety_timeout)
			{
				digitalWrite(motors_pin_a[id], motor_state_next[id] < 0);
				digitalWrite(motors_pin_b[id], motor_state_next[id] > 0);
				analogWrite(motors_pin_pwm[id], abs(motor_state_next[id]));
				motor_state_current[id] = motor_state_next[id];
			}
		}
		/*
		 * Note to self: be concerned about millis() overflowing and messing with logic
		 */
	}
}