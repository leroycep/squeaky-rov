
#ifndef _COMMUNICATION_H_
#define _COMMUNICATION_H_
#ifdef __cplusplus
extern "C" {
#endif

typedef enum  {
	CMD_NULL = 0x00,
	//Motors
	CMD_SET_MOTOR_PINS = 0x10,
	CMD_CONTROL_MOTOR = 0x11,
	CMD_SET_PWM_BOUNDS = 0x12,
	CMD_SET_SAFETY_TIMEOUT = 0x13,
	//Gripper
	CMD_SET_GRIPPER_PIN = 0x20,
	CMD_CONTROL_GRIPPER = 0x21,
	//Stepper
	CMD_SET_STEPPER_PINS = 0x22,
	CMD_STEP_STEPPER = 0x23,
	//Sensors
	CMD_SET_SENSOR_PIN = 0x30,
	CMD_SENSOR_STATE = 0x31,
	//Cameras
	CMD_SET_CAMERA_PINS = 0x40,
	CMD_SWITCH_CAMERA = 0x41,
	//Misc
	CMD_ECHO = 0xF0
} CommunicationCommand;

int communication_command_get_command_length (CommunicationCommand self);
char* communication_command_get_command_name (CommunicationCommand self);


typedef enum CommunicationSensor
{
	SENSOR_VOLTAGE=0x01
} CommunicationSensor;

typedef enum CommunicationResponse
{
	RESPONSE_ECHO=0x00,
	RESPONSE_SENSOR=0x01
} CommunicationResponse;

#ifdef __cplusplus
}
#endif
#endif
