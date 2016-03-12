
#ifndef _MOTOR_H_
#define _MOTOR_H_

class Motor {
	byte pinA;
	byte pinB;
	byte pinPWM;

  public:
  	void setPins(byte, byte, byte);
  	void set(bool, bool, byte); // left, right, pwm
};

#endif