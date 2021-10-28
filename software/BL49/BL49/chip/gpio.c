/*
 * gpio.c
 *
 * Created: 28.10.2021 13:42:17
 *  Author: Heinrich
 */ 

#include "gpio.h"
#include "../adc/adc.h"

typeInputs inputs;

static inline bool is_between (uint16_t left, uint16_t right, uint16_t value)
{
	if (value > left && value < right)
	{
		return true;
	}
	return false;
}

void gpio_init (void)
{
	memset((void*)&inputs, 0, sizeof(inputs));
}

void gpio_read_inputs (typeInputs *inputs)
{
	inputs->UA = adc_ua();
	inputs->UR = adc_ur();
	inputs->UBat = adc_ad12v();
	inputs->URef = adc_ad5v();
	inputs->UBat_OK = is_between(UBat_MIN, UBat_MAX, inputs->UBat);
}

