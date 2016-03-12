
#ifndef _MOTOR_H_
#define _MOTOR_H_

class Motor {
	int pinA;
	int pinB;
	int pinPWM;

  public:
  	void setPins(int, int, int);
  	void set(bool, bool, int); // left, right, pwm
  	void update();
};

#endif