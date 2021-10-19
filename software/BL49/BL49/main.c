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
	adc_init();
	sei();
	
   	uint8_t pt_data[CAN_DLC];
	st_cmd_t msg;
	msg.id.ext = CAN_ID;
	msg.dlc = CAN_DLC;
	msg.cmd = CMD_TX;
	
	uint16_t lambda = 10000;
	lambda = bswap_16(lambda);
		
	pt_data[0] = lambda;
	pt_data[1] = (uint8_t)(lambda >> 8);
	
	float oxygen = 0.1f * 1000.0f;
	uint16_t oxy = bswap_16((uint16_t)oxygen);
	
	pt_data[2] = oxy;
	pt_data[3] = (uint8_t)(oxy >> 8);
	
	pt_data[4] = (uint8_t)((uint32_t) adc_ad12v() * 24500UL / 1023UL/ 100UL );
	pt_data[5] = (uint8_t)((float) pt_data[4] *0.85f);
	
	pt_data[6] = (1 << 7)|(1 << 4)|(1 << 1);	// bosch lsu4.9, heater pid locked, lambda valid
	pt_data[7] = 0x06;
	
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
