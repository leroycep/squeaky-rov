#include <Arduino.h>
#include "received.h"
#include "communication.h"
#include "response.h"
#include "robot.h"
#include "meta.h"

void Command::received(int command, int args[])
{
	switch(command)
	{
		// Motors
		case CMD_SET_MOTOR_PINS: Command::setMotorPins(args[0] >> 4 & 0xF, args[0] & 0xF, args[1], args[2]); break;
		case CMD_CONTROL_MOTOR: Command::controlMotor(args[0] >> 4 & 0xF, args[0] & 0xF, args[1]); break;
		case CMD_SET_PWM_BOUNDS: Command::setPWMBounds(args[0], args[1]); break;
		case CMD_SET_SAFETY_TIMEOUT: Command::setSafetyTimeout(args[0] << 8 | args[1]); break;
		// Steppers
		case CMD_SET_STEPPER_PINS: Command::setStepperPins(args[0], args[1], args[2]); break;
		case CMD_CONTROL_STEPPER: Command::controlStepper(args[0] >> 4 & 0xF); break;
		case CMD_SET_STEPPER_STATE: Command::setStepperState(args[0]); break;
		// Sensors
		case CMD_SENSOR_STATE: Command::setSensorState(args[0], args[1]); break;
		case CMD_SET_VOLTAGE_SENSOR_PIN: Command::setVoltageSensorPin(args[0]); break;
		case CMD_SET_TEMPERATURE_SENSOR_PIN: Command::setTemperatureSensorPin(args[0]); break;
		// Cameras
		case CMD_SET_CAMERA_PINS: Command::setCameraPins(args[0], args[1], args[2], args[3]); break;
		case CMD_SWITCH_CAMERA: Command::switchCamera(args[0]); break;
		// Misc
		case CMD_ECHO: Command::echo(args[0]); break;
		case CMD_VERSION: Command::version(); break;
		default: {
			Response::log_warning("Unimplemented command "+command);
		} break;
	}
}

// !!!!! MOTORS !!!!!

void Command::setMotorPins(int motorId, int pwmPin, int leftPin, int rightPin) {
	Robot::Robot::instance()->getMotor(motorId)->setPins(leftPin, rightPin, pwmPin);
	Response::log_info("Set motor "+String(motorId)+" to A:"+String(leftPin)+", B:"+String(rightPin)+", PWM:"+String(pwmPin));
}

void Command::controlMotor(int motorId, int flags, int pwm) {
	bool a = (flags & 0x1) == 0x1;
	bool b = (flags & 0x2) == 0x2;
	Robot::Robot::instance()->getMotor(motorId)->set(a, b, pwm);
}

void Command::setPWMBounds(int lower, int upper) {
	Response::log_warning("Command SET_PWM_BOUNDS is deprecated");
}

void Command::setSafetyTimeout(int timeout) {
	Response::log_warning("Command SET_SAFETY_TIMEOUT is deprecated");
}

// !!!!! STEPPERS !!!!!

void Command::setStepperPins(int dir, int step, int enabled) {
	Robot::Robot::instance()->setStepperPins(dir, step, enabled);
	Response::log_info("Set stepper direction pin to "+String(dir)+", step pin "+String(step)+", and enabled pin "+String(enabled));
}

void Command::controlStepper(int direction) {
	Robot::Robot::instance()->controlStepper(direction==1);
}

void Command::setStepperState(int enabled) {
	Robot::Robot::instance()->setStepperEnabled(enabled==1);
}


// !!!!! SENSORS !!!!!

void Command::setSensorState(int sensor, int state) {
	String stateString = state==1 ? "on" : "off";
	switch(sensor) {
		case 0x31: // Voltage Sensor
			Robot::Robot::instance()->getVoltageSensor()->setState(state==1);
			Response::log_info("Turned voltage sensor "+stateString);
			break;
		case 0x32: // Temperature Sensor
			Robot::Robot::instance()->getTemperatureSensor()->setState(state==1);
			Response::log_info("Turned temperature sensor "+stateString);
			break;
		default:
			Response::log_warning("Unknown sensor "+String(sensor));
			break;
	}
}

void Command::setVoltageSensorPin(int pin) {
	Robot::Robot::instance()->getVoltageSensor()->setPin(pin);
	Response::log_info("Set voltage sensor to pin "+String(pin));
}

void Command::setTemperatureSensorPin(int pin) {
	Robot::Robot::instance()->getTemperatureSensor()->setPin(pin);
	Response::log_info("Set temperature sensor to pin "+String(pin));
}


// !!!!! CAMERAS !!!!!

void Command::setCameraPins(int pinA, int pinB, int pinC, int pinD) {
	Response::log_warning("setCameraPins not yet implemented");
}

void Command::switchCamera(int camera) {
	Response::log_warning("switchCamera not yet implemented");
}


// !!!!! MISC !!!!!

void Command::echo(int byte) {
	Response::log_info(String((char)(byte)));
}

void Command::version() {
	Response::log_info(VERSION);
}