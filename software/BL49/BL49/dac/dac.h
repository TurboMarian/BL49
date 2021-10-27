/*
 * dac.h
 *
 * Created: 27.10.2021 08:54:59
 *  Author: Heinrich
 */ 


#ifndef DAC_H_
#define DAC_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>
#include <stdbool.h>

void dac_init (void);
void dac_value (uint16_t value);


#endif /* DAC_H_ */