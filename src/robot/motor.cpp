
#include "motor.h"

void Motor::setPins(byte a, byte b, byte pwm) {
	pinA = a;
	pinB = b;
	pinPwm = pwm;
	pinMode(pinA, OUTPUT);
	pinMode(pinB, OUTPUT);
	pinMode(pinPWM, OUTPUT);
}

void Motor::set(bool left, bool right, byte pwm) {
	digitalWrite(pinA, left);
	setOutput(pinB, right);
	setOutput(pinPWM, pwm);
}