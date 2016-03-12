#include "communication.h"

typedef struct {
	CommunicationCommand cmd;
	int length;
	char *name;
} Command;

Command communication_command_commands[] = {
	// Motors
	{CMD_SET_MOTOR_PINS, 3, "CMD_SET_MOTOR_PINS"},
	{CMD_CONTROL_MOTOR, 2, "CMD_CONTROL_MOTOR"},
	{CMD_SET_PWM_BOUNDS, 2, "CMD_SET_PWM_BOUNDS"},
	{CMD_SET_SAFETY_TIMEOUT, 2, "CMD_SET_SAFETY_TIMEOUT"},
	// Steppers
	{CMD_SET_GRIPPER_PIN, 1, "set_gripper_pins"},
	{CMD_CONTROL_GRIPPER, 1, "control_gripper"},
	// Sensors
	{CMD_SET_SENSOR_PIN, 2, "CMD_SET_SENSOR_PIN"},
	{CMD_SENSOR_STATE, 2, "CMD_SENSOR_STATE"},
	// Cameras
	{CMD_SET_CAMERA_PINS, 4, "set_camera_pins"},
	{CMD_SWITCH_CAMERA, 1, "switch_camera"},
	// Misc
	{CMD_ECHO, 1, "CMD_ECHO"}
};

int communication_command_get_command_length (CommunicationCommand self)
{
	int i;
	for (i = 0; i < sizeof(communication_command_commands)/sizeof(Command); i++) {
		if(self == communication_command_commands[i].cmd) {
			return communication_command_commands[i].length;
		}
	}
	return 0;
}

char* communication_command_get_command_name (CommunicationCommand self)
{
	int i;
	for (i = 0; i < sizeof(communication_command_commands)/sizeof(Command); i++) {
		if(self == communication_command_commands[i].cmd) {
			return communication_command_commands[i].name;
		}
	}
	return "null";
}