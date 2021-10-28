/*
 * gpio.h
 *
 * Created: 28.10.2021 13:42:27
 *  Author: Heinrich
 */ 


#ifndef GPIO_H_
#define GPIO_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdbool.h>
#include "../helpers.h"
#include "../config.h"

typedef struct
{
	uint16_t UA;
	uint16_t UR;
	uint16_t UBat;
	uint16_t URef;
	bool UBat_OK;
} typeInputs;

extern typeInputs inputs;

void gpio_init (void);
void gpio_read_inputs (typeInputs *inputs);

#endif /* GPIO_H_ */