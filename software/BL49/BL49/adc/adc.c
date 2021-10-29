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
	ADMUX = (1 << REFS0)|(1 << MUX3)|(1 << MUX1)|(1 << MUX0);			// select channel
	ADCSRA |= (1<<ADSC);		// start single conversion
	while(ADCSRA & (1<<ADSC));	// wait till done
	
	temp1 = ADC * (5.0/1024)*1000.0/25;	
	return temp1;
}

uint16_t adc_ad12v (void)	// adc channel 5
{
	ADMUX = (1 << REFS0)|(1 << MUX2)|(1 << MUX0);			// select channel
	ADCSRA |= (1<<ADSC);		// start single conversion
	while(ADCSRA & (1<<ADSC));	// wait till done
	return ADC;
}


uint16_t adc_reference (void)	// adc channel 3
{
	ADMUX = (1 << REFS0)|(1 << MUX1)|(1 << MUX0);			// select channel
	ADCSRA |= (1<<ADSC);		// start single conversion
	while(ADCSRA & (1<<ADSC));	// wait till done
	return ADC;
}

uint16_t adc_ua (void)	// adc channel 8
{
	ADMUX = (1 << REFS0)|(1 << MUX3);			// select channel
	ADCSRA |= (1<<ADSC);		// start single conversion
	while(ADCSRA & (1<<ADSC));	// wait till done
	return ADC;
}

uint16_t adc_ur (void)	// adc channel 9
{
	ADMUX = (1 << REFS0)|(1 << MUX3)|(1 << MUX0);			// select channel
	ADCSRA |= (1<<ADSC);		// start single conversion
	while(ADCSRA & (1<<ADSC));	// wait till done
	return ADC;
}