#include <Arduino.h>
#include "received.h"
#include "communication.h"
#include "response.h"

void recieved_command(int command, int args[])
{
	switch(command)
	{
		// Motors
		case CMD_SET_MOTOR_PINS: Command::setMotorPins(args[0] >> 4 & 0xF, args[0] & 0xF, args[1], args[2]); break;
		case CMD_CONTROL_MOTOR: Command::controlMotor(args[0] >> 4 & 0xF, args[0] & 0xF, args[1]); break;
		case CMD_SET_PWM_BOUNDS: Command::setPWMBounds(args[0], args[1]); break;
		case CMD_SET_SAFETY_TIMEOUT: Command::setSafetyTimeout(args[0] << 8 | args[1]); break;
		// Steppers
		case CMD_SET_GRIPPER_PIN: Command::setGripperPin(args[0]); break;
		case CMD_CONTROL_GRIPPER: Command::controlGripper(args[0]); break;
		// Sensors
		case CMD_SET_SENSOR_PIN: Command::setSensorPin(args[0], args[1]); break;
		case CMD_SENSOR_STATE: Command::setSensorState(args[0], args[1]); break;
		// Cameras
		case CMD_SET_CAMERA_PINS: Command::setCameraPins(args[0], args[1], args[2], args[3]); break;
		case CMD_SWITCH_CAMERA: Command::switchCamera(args[0]); break;
		// Misc
		case CMD_ECHO: Command::echo(args[0]); break;
		default: {
			Response::log_warning("Unimplemented command "+command);
		} break;
	}
}

void Command::setMotorPins(int motorId, int pwmPin, int leftPin, int rightPin) {
	Response::log_info("Set motor "+String(motorId)+" to A:"+String(leftPin)+", B:"+String(rightPin)+", PWM:"+String(pwmPin));
	Response::log_warning("SetMotorPin not yet implemented.");
}

void Command::controlMotor(int motorId, int flags, int pwm) {
	bool a = flags & 0x1 == 0x01;
	bool b = flags & 0x2 == 0x02;
	Response::log_warning("controlMotor not yet implemented");
}

void Command::setPWMBounds(int lower, int upper) {
	Response::log_info("Set pwm bounds to ["+String(lower)+","+String(upper)+"]");
	Response::log_warning("setPWMBounds not yet implemented");
}

void Command::setSafetyTimeout(int timeout) {
	Response::log_info("Set safety timeout to "+String(timeout)+" milliseconds");
	Response::log_warning("setSafetyTimeout not yet implemented");
}

void Command::setGripperPin(int pin) {
	Response::log_info("Set grippper to pin "+String(pin));
	Response::log_warning("setGripperPin not yet implemented");
}

void Command::controlGripper(int pwm) {
	Response::log_warning("controlGripper not yet implemented");
}

void Command::setSensorPin(int sensor, int pin) {
	Response::log_warning("setSensorPin not yet implemented");
}

void Command::setSensorState(int sensor, int state) {
	Response::log_warning("setSensorState not yet implemented");
}

void Command::setCameraPins(int pinA, int pinB, int pinC, int pinD) {
	Response::log_warning("setCameraPins not yet implemented");
}

void Command::switchCamera(int camera) {
	Response::log_warning("switchCamera not yet implemented");
}

void Command::echo(int byte) {
	Response::log_info(String(byte));
}