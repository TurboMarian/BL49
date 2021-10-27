/*
 * dac.c
 *
 * Created: 27.10.2021 08:54:33
 *  Author: Heinrich
 */ 

#include "dac.h"

void dac_init (void)
{
	// dac output enable, dac enable, no autotrigger
	DACON = (1 << DAOE) |(1 << DAEN);
}

void dac_value (uint16_t value)
{
	// DAC = 0xff;
	DACL = (uint8_t)value;
	DACH = (uint8_t)((value >> 8) & 0x03);
}