/*
 * timer.c
 *
 * Created: 16.10.2021 21:58:38
 *  Author: Heinrich
 */ 

#include "timer.h"

void timer0_init (void)
{
	//100ms timer, preload 178, prescalter 1024
	TIFR0 = (1<<TOV0);
	TCNT0 = 178;
	TCCR0B = (1 << CS00)|(1 << CS02);
	TIMSK0 |= (1 << TOIE0);
	
}

void timer_delay_ms (uint16_t delay)
{
	do
	{
		TCNT0 = 6;
		TCCR0B |= (1 << CS01)|(1 << CS00);
		while ((TIFR0 & (1 << TOV0)) == 0);
		TIFR0 |= (1 << TOV0);
		delay--;
	} while (delay > 0);
}

/*
ISR(TIMER0_OVF_vect)
{
	TCNT0 = 178;
	LED2_TOG;
	LED3_TOG;
}
*/