
#ifndef _RECEIVED_H_
#define _RECEIVED_H_


namespace Command {
	void received(int command, int args[]);
	void setMotorPins(int, int, int, int);
	void controlMotor(int, int, int);
	void setPWMBounds(int, int);
	void setSafetyTimeout(int);

	void setStepperPins(int, int, int);
	void controlStepper(bool, int);
	void setStepperState(int);

	void setSensorState(int, int);
	void setVoltageSensorPin(int);
	void setTemperatureSensorPin(int);
	void setDepthSensorDensity(int);

	void setCameraPins(int, int, int, int, int, int, int, int);
	void switchCamera(int, int);
	
	void echo(int);
	void version();
}

#endif