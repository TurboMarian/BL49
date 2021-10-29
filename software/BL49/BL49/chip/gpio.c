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
	inputs->URef = (int16_t)((uint32_t) adc_reference() * 5000UL / 1024UL);	// here should be 1225 (shunt *1000)
	inputs->UBat_OK = is_between(UBat_MIN, UBat_MAX, inputs->UBat);
	inputs->UOffset = 1225 - inputs->URef;
	inputs->USupply = (int16_t)((uint32_t)( inputs->UBat +inputs->UOffset) * 24500UL / 1024UL);
}

bool is_ubat_ok (void)
{
	inputs.UBat=adc_ad12v();
	return inputs.UBat_OK = is_between(UBat_MIN, UBat_MAX, inputs.UBat);
}

uint16_t calculate_pwm_for_voltage (uint16_t voltage)
{	
	return (uint16_t) ((float)voltage/inputs.USupply*1024.0);
}