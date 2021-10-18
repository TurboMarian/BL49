/*
 * adc.c
 *
 * Created: 17.10.2021 13:42:55
 *  Author: Heinrich
 */ 

#include "adc.h"

void adc_init (void)
{
	// avcc with cap on aref
	ADCSRB |= (1 << AREFEN);
	ADMUX = (1 << REFS0);
	
	// enable adc, prescalee 128
	ADCSRA |= (1 << ADEN)|(1 << ADPS2)|(1 << ADPS1)|(1 << ADPS0);
}

uint16_t adc_read (uint8_t channel) 
{
	ADMUX = (1 << REFS0)|channel;			// select channel
	ADCSRA |= (1<<ADSC);		// start single conversion
	while(ADCSRA & (1<<ADSC));	// wait till done
	return ADC;
	
}

float adc_chip_temperature (void)
{
	float temp1 = 0;
	float temp2 = 0;
	ADMUX = (1 << REFS0)|(1 << MUX3)|(1 << MUX1)|(1 << MUX0);			// select channel
	ADCSRA |= (1<<ADSC);		// start single conversion
	while(ADCSRA & (1<<ADSC));	// wait till done
	
	temp1 = ADC * (5.0/1024)*1000.0/25;
	
	
	int i = 10;
	
	return temp1;
}