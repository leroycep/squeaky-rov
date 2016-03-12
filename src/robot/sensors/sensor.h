
#ifndef _SENSOR_H_
#define _SENSOR_H_

namespace Sensor {
	class Sensor {
		byte pin;
		bool state;

	  public:
	  	void setPin(byte);
	  	void setState(bool);
	  	void update();
	};
}

#endif