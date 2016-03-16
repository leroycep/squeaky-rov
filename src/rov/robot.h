
#ifndef _ROBOT_H_
#define _ROBOT_H_

#include "motor.h"
#include "sensors/sensor.h"

#define CONFIGURE_MAX_MOTORS 8
#define CONFIGURE_MAX_SENSORS 1

namespace Robot {
	class Robot {
		static Robot* s_instance;
		int maxPWM;
		int minPWM;
		int safety_timeout;
		Motor** motors;
		Sensor::Sensor** sensors;
		int multiplexerPins[4];
		Robot();

	  public:
		void setPWMBounds(int, int);
		void setSafetyTimeout(int);
		void setMultiplexerPins(int, int, int, int);
		Motor* getMotor(int);
		Sensor::Sensor* getSensor(int);
		void update();
		static Robot* instance();
	};
}

#endif