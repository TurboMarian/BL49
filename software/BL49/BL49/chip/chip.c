/*
 * chip.c
 *
 * Created: 28.10.2021 15:42:21
 *  Author: Heinrich
 */ 

#include "chip.h"

void chip_init (void)
{
	CLKPR = 0x80;
	CLKPR = 0x00;
	
	// leds at pb5 (led2) and pb6 (led3), active high
	// leds are off
	LEDS |= (1 << CPC1017)|(1 << LED2)|(1 << LED3);
	
	LED2_OFF;
	LED3_OFF;
	CPC1017_OFF;
	
	// spi
	LEDS |= (1 << SPI_MOSI)|(1 << SPI_SCK);
	// spi ss
	DDRD |= (1 << SPI_SS);
	SPI_SS_DESELECT;
	
	// probe heater, output
	DDRC |= (1 << HEATER_PIN);
}