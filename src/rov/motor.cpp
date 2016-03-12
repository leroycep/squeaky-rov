
#include <Arduino.h>
#include "motor.h"

void Motor::setPins(int a, int b, int pwm) {
	pinA = a;
	pinB = b;
	pinPWM = pwm;
	pinMode(pinA, OUTPUT);
	pinMode(pinB, OUTPUT);
	pinMode(pinPWM, OUTPUT);
}

void Motor::set(bool left, bool right, int pwm) {
	digitalWrite(pinA, left);
	digitalWrite(pinB, right);
	analogWrite(pinPWM, pwm);
}

void Motor::update() {
	// Implement safer motor switching
}