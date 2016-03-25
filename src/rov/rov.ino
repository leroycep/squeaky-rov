#include "communication.h"
#include "received.h"
#include "robot.h"
#include "meta.h"

int command_state = 0;
int command = -1;
int bytes_left = 0;
int command_buffer[4];
int buffer_pos = 0;

Robot::Robot* Robot::Robot::s_instance = 0;

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
	if(command_state==1) { // Read command byte
		if (Serial.available() > 0)
		{
			command = Serial.read();
			bytes_left = Communication::getCommandLength(command);
			command_state = 2;
		}
	}
	if(command_state==2) {// Read bytes into the buffer
		while (Serial.available() > 0 && bytes_left>0)
		{
			command_buffer[buffer_pos] = Serial.read();
			buffer_pos++;
			bytes_left--;
		}
		if (bytes_left<=0)
		{
			command_state = 3;
		}
	}
	if(command_state==3) { // Parse the command
		Command::received(command, command_buffer);
		command_state=0;
	}
}

void update() {
	Robot::Robot::instance()->update();
}


// Increases the frequency of the arduino mega.
// This is needed to prevent the motor drivers from blowing up.
void change_pwm_frequency() {
	/* Each timer can be accessed by the variable TCCRnB, where n is the timer
	   number. For example, TCCR0B is the variable for timer 0.
			|Timer|Pins   |
			|-----|-------|
			|0    |13, 4  |
			|1    |12, 11 |
			|2    |10, 9  |
			|3    |5, 3, 2|
			|4    |8, 7, 6|
	*/

	// Erase first three bits of timer number
	// 7, because 7 = 0b11100000
	int my_eraser = 7;
	TCCR0B &= ~my_eraser;
	TCCR1B &= ~my_eraser;
	TCCR2B &= ~my_eraser;
	TCCR3B &= ~my_eraser;
	TCCR4B &= ~my_eraser;

	/* The third column is for timer 0, which has a different set of frequencies.
	|prescalar|frequency|frequency|
	|---------|---------|---------|
	|1        |31000    |62000    |
	|2        |4000     |7800     |
	|3        |490      |980      |
	|4        |120      |250      |
	|5        |30       |60       |
	|6        |<20      |<20      |
	*/
	int my_prescalar = 2;
	TCCR0B |= my_prescalar;
	TCCR1B |= my_prescalar;
	TCCR2B |= my_prescalar;
	TCCR3B |= my_prescalar;
	TCCR4B |= my_prescalar;
}