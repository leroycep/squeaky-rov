#include "communication.h"

int command_state = 0;
int command = -1;
int bytes_left = 0;
int buffer[4];
int buffer_pos = 0;

void setup()
{
	Serial.begin(9600);
	change_pwm_frequency();
}

void loop()
{
	check_for_commands(); // Read commands from the controller
	update(); // Move
}

void check_for_commands() /// State machine!
{
	if(command_state==0) { // Reset the state machine
		command_state = 1;
		command = -1;
		bytes_left = 0;
		buffer_pos = 0;
	}
	if(command_state==1) // Read command byte
	{
		if (Serial.available() > 0)
		{
			command = Serial.read();
			CommunicationCommand communication_command = static_cast<CommunicationCommand>(command);
			bytes_left = communication_command_get_command_length(communication_command);
			command_state = 2;
		}
	}
	if(command_state==2) // Read bytes into the buffer
	{
		while (Serial.available() > 0 && bytes_left>0)
		{
			buffer[buffer_pos] = Serial.read();
			buffer_pos++;
			bytes_left--;
		}
		if (bytes_left<=0)
		{
			command_state = 3;
		}
	}
	if(command_state==3) // Parse the command
	{
		CommunicationCommand communication_command = static_cast<CommunicationCommand>(command);
		recieved_command(communication_command, buffer);
		command_state=0;
	}
}

void update()
{
	update_motors();
	update_sensors();
}


void change_pwm_frequency()
{
	int my_eraser = 7;
	TCCR0B &= ~my_eraser;
	TCCR1B &= ~my_eraser;
	TCCR2B &= ~my_eraser;
	TCCR3B &= ~my_eraser;
	TCCR4B &= ~my_eraser;

	int my_prescalar = 2;
	TCCR0B |= 5;
	TCCR1B |= my_prescalar;
	TCCR2B |= my_prescalar;
	TCCR3B |= my_prescalar;
	TCCR4B |= my_prescalar;
}