
#ifndef _RECEIVED_H_
#define _RECEIVED_H_

void recieved_command(int command, int args[]);

namespace Command {
	void setMotorPins(int, int, int, int);
	void controlMotor(int, int, int);
	void setPWMBounds(int, int);
	void setSafetyTimeout(int);
	void setGripperPin(int);
	void controlGripper(int);
	void setSensorPin(int, int);
	void setSensorState(int, int);
	void setCameraPins(int, int, int, int);
	void switchCamera(int);
	void echo(int);
}

#endif