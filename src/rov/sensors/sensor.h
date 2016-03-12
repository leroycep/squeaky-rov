
#ifndef _SENSOR_H_
#define _SENSOR_H_

namespace Sensor {
	class Sensor {
	  protected:
		int pin;
		bool state;

	  public:
	  	void setPin(int);
	  	void setState(bool);
	};
}

#endif