/*
 * timer.c
 *
 * Created: 16.10.2021 21:58:38
 *  Author: Heinrich
 */ 

#include "timer.h"

st_cmd_t msg;

void timer0_init (void)
{
	//100ms timer, preload 6, prescalter 64
	TCNT0 = 6;
	TIMSK0 |= (1 << TOIE0);
	TCCR0A = 0x0;
	TCCR0B = (1 << CS00)|(1 << CS01);
	
}

ISR(TIMER0_OVF_vect)
{
	TCNT0 = 6;
	/*
		msg.id.std = CAN_ID;
		msg.dlc = CAN_DLC;
		msg.cmd = CMD_NONE;
	
		while(can_cmd(&msg) != CAN_CMD_ACCEPTED); // wait for MOb to configure
		while(can_get_status(&msg) == CAN_STATUS_NOT_COMPLETED); // wait for a transmit request to come in, and send a response
	*/
	LED2_TOG;
}