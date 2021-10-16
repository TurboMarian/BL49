/*
 * BL49.c
 *
 * Created: 16.10.2021 23:06:12
 * Author : Heinrich
 */ 

#include <avr/io.h>
#include <stdint.h>
#include <stdbool.h>
#include "can/can_lib.h"
#include "timer/timer.h"

#include "config.h"

static void chip_init (void);

int main(void)
{
	chip_init();
	sei();
	can_init(0);
	timer0_init();

    /* Replace with your application code */
    while (1) 
    {
    }
}

void chip_init (void)
{
	// Make sure sys clock is at least 8MHz
	CLKPR = 0x80;
	CLKPR = 0x00;
	
	// leds an pb5 (led2) und pb6 (led3), active high
	// leds sind aus
	LEDS |= (1 << LED2)|(1 << LED3);
	LEDS_PORT &= ~((1 << LED2)|(1 << LED3));
}
