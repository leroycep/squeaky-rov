
#define CONFIGURE_MAX_MOTORS 8
#define CONFIGURE_MAX_SENSORS 1

struct Motor {
	byte pinA;
	byte pinB;
	byte pinPWM;
};

struct Sensor {
	byte pin;
	bool state;
};

class Robot {
	int maximum_pwm;
	int minimum_pwm;
	int safety_timeout;
	Motor motors[CONFIGURE_MAX_MOTORS];
	Sensor sensors[CONFIGURE_MAX_SENSORS];
	byte multiplexerPins[4];

	public:
		new();
};

public Robot::new() {
	Robot robot;

	robot.maximum_pwm = 175;
	robot.minimum_pwm = 10;
	robot.safety_timeout = 2;

	return robot;
}