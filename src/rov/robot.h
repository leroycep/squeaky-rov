
#ifndef _ROBOT_H_
#define _ROBOT_H_

#include "robot.h"
#include "motor.h"
#include "sensors/sensor.h"

#define CONFIGURE_MAX_MOTORS 8
#define CONFIGURE_MAX_SENSORS 1

namespace Robot {
	class Robot {
		int maxPWM;
		int minPWM;
		int safety_timeout;
		Motor motors[CONFIGURE_MAX_MOTORS];
		Sensor::Sensor sensors[CONFIGURE_MAX_SENSORS];
		int multiplexerPins[4];

	  public:
		Robot();
		void setPWMBounds(int, int);
		void setSafetyTimeout(int);
		void setMultiplexerPins(int, int, int, int);
		Motor* getMotor(int);
		Sensor::Sensor* getSensor(int);
		void update();
	};
}

#endif