
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
	Motor motors[CONFIGURE_MAX_MOTORS];
	Sensor sensors[CONFIGURE_MAX_SENSORS];
	byte multiplexerPins[4];
};

Robot rov;