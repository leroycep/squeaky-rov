
#define CONFIGURE_MAX_MOTORS 8
#define CONFIGURE_MAX_SENSORS 1

class Motor {
	byte pinA;
	byte pinB;
	byte pinPWM;
};

class Sensor {
	byte pin;
	bool state;
};

class Robot {
	byte maximum_pwm;
	byte minimum_pwm;
	int safety_timeout;
	Motor motors[CONFIGURE_MAX_MOTORS];
	Sensor sensors[CONFIGURE_MAX_SENSORS];
	byte multiplexerPins[4];

  public:
	Robot();
	void setPWMBounds(byte, byte);
	void setSafetyTimeout(int);
	void setMultiplexerPins(byte, byte, byte, byte);
	Motor getMotor(int);
	Sensor getSensor(int);
};

Robot::Robot() {
	maximum_pwm = 175;
	minimum_pwm = 10;
	safety_timeout = 2;

	for (int i=0; i<CONFIGURE_MAX_MOTORS; i++) {
		motors[i] = Motor{};
	}

	for (int i=0; i<CONFIGURE_MAX_SENSORS; i++) {
		sensors[i] = Sensor{};
	}
}

void Robot::setPWMBounds(byte low, byte high) {
	minimum_pwm = low;
	maximum_pwm = high;
}

void Robot::setSafetyTimeout(int timeout) {
	safety_timeout = timeout;
}

void Robot::setMultiplexerPins(byte one, byte two, byte three, byte four) {
	multiplexerPins[0] = one;
	multiplexerPins[1] = two;
	multiplexerPins[2] = three;
	multiplexerPins[3] = four;
}

Motor Robot::getMotor(int id) {
	return motors[id];
}

Sensor Robot::getSensor(int id) {
	return sensors[id];
}