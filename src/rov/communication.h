
#ifndef _COMMUNICATION_H_
#define _COMMUNICATION_H_

//Motors
#define CMD_SET_MOTOR_PINS 0x10
#define CMD_CONTROL_MOTOR 0x11
#define CMD_SET_PWM_BOUNDS 0x12
#define CMD_SET_SAFETY_TIMEOUT 0x13

//Gripper
#define CMD_SET_GRIPPER_PIN 0x20
#define CMD_CONTROL_GRIPPER 0x21

//Sensors
#define CMD_SET_SENSOR_PIN 0x30
#define CMD_SENSOR_STATE 0x31

//Cameras
#define CMD_SET_CAMERA_PINS 0x40
#define CMD_SWITCH_CAMERA 0x41

//Misc
#define CMD_ECHO 0xF0

namespace Communication {
	int getCommandLength(int);
}

#endif