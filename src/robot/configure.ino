
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

struct Robot {
	int maximum_pwm;
	int minimum_pwm;
	int safety_timeout;
	Motor motors[CONFIGURE_MAX_MOTORS];
	Sensor sensors[CONFIGURE_MAX_SENSORS];
	byte multiplexerPins[4];
};

Robot configure_new_robot() {
	Robot robot;

	robot.maximum_pwm = 175;
	robot.minimum_pwm = 10;
	robot.safety_timeout = 2;

	return robot;
}

Robot rov = configure_new_robot();