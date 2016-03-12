#include "communication.h"

namespace Communication {
	int getCommandLength(int id) {
		switch(id) {
			case CMD_SET_MOTOR_PINS: return 3;
			case CMD_CONTROL_MOTOR: return 2;
			case CMD_SET_PWM_BOUNDS: return 2;
			case CMD_SET_SAFETY_TIMEOUT: return 2;
			case CMD_SET_GRIPPER_PIN: return 1;
			case CMD_CONTROL_GRIPPER: return 1;
			case CMD_SET_SENSOR_PIN: return 2;
			case CMD_SENSOR_STATE: return 2;
			case CMD_SET_CAMERA_PINS: return 4;
			case CMD_SWITCH_CAMERA: return 1;
			case CMD_ECHO: return 1;
			default: return 0;
		}
	}
}