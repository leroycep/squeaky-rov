
#ifndef _SENSOR_H_
#define _SENSOR_H_

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
}

#endif