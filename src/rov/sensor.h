
#ifndef _SENSOR_H_
#define _SENSOR_H_

#include "lib/MS5837.h"

namespace Sensor {
	class Sensor {
	  protected:
		bool state;

	  public:
	  	void setState(bool);
	};

	class Voltage: public Sensor {
		int pin;

	  public:
	  	void setPin(int);
	  	void update();
	};

	class Temperature: public Sensor {
		int pin;

	  public:
	  	void setPin(int);
	  	void update();
	};

	class Depth: public Sensor {
		MS5837 sensor;

	  public:
	  	void setDensity(float);
	  	void update();
	};
}

#endif