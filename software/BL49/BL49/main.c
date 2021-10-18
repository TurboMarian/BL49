/*
 * BL49.c
 *
 * Created: 16.10.2021 23:06:12
 * Author : Heinrich
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>
#include <stdbool.h>
#include "adc/adc.h"
#include "can/can_lib.h"
#include "timer/timer.h"

#include "config.h"

static void chip_init (void);

int main(void)
{
	chip_init();
	can_init(0);
	sei();
	

   	uint8_t pt_data[CAN_DLC];
	st_cmd_t msg;
	msg.id.ext = CAN_ID;
	msg.dlc = CAN_DLC;
	msg.cmd = CMD_TX;
	pt_data[0] = 0xF1;
	pt_data[1] = 0xF2;
	pt_data[2] = 0xF3;
	pt_data[3] = 0xF4;
	msg.pt_data = &pt_data[0];
	
    while (1) 
    {

		while(can_cmd(&msg) != CAN_CMD_ACCEPTED); // wait for MOb to configure
		while(can_get_status(&msg) == CAN_STATUS_NOT_COMPLETED); // wait for a transmit request to come in, and send a response
		LED2_TOG;
		timer_delay_ms(10);
		
    }
}

void chip_init (void)
{
	// Make sure sys clock is at least 8MHz
	/*
	CLKPR = 0x80;
	CLKPR = 0x00;
	*/
	
	// leds at pb5 (led2) and pb6 (led3), active high
	// leds are off
	LEDS |= (1 << LED2)|(1 << LED3);
	LEDS_PORT &= ~((1 << LED2)|(1 << LED3));
}
