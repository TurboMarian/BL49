/*
 * adc.h
 *
 * Created: 17.10.2021 13:42:05
 *  Author: Heinrich
 */ 


#ifndef ADC_H_
#define ADC_H_

// adc channels
#define ADC_AD5V			3	// pin pd6, channel 3
#define ADC_AD12V			5	// pin pb2, channel 5
#define ADC_UA				8	// pin pc4, channel 8
#define ADC_UR				9	// pin pc5, channel 9
#define CHIP_TEMP			11	// chip temperature, channel 11

#include <avr/io.h>
#include <stdint.h>
#include <stdbool.h>

void adc_init (void);
uint16_t adc_read (uint8_t channel);
float adc_chip_temperature (void);


#endif /* ADC_H_ */