/*
 * spi.c
 *
 * Created: 16.10.2021 22:37:01
 *  Author: Heinrich
 */ 

#include "spi.h"

void spi_init (void)
{
	// enable spi, 2MHz (div 8), master, mode1 (cpol 0, cpha 1)
	SPCR |= (1 << SPE)|(0 << DORD)|(1 << MSTR)|(0 << CPOL)|(1 << CPHA)|(1 << SPR0);
}

uint16_t spi_read_write (uint16_t data)
{
	SPI_SS_SELECT;
	uint8_t byte1, byte2;
	
	SPDR = (data >> 8);
	while(!(SPSR & (1<<SPIF)));
	byte1 = SPDR;
	SPDR = (data & 0xFF);
	while(!(SPSR & (1<<SPIF)));
	byte2 = SPDR;
	
	SPI_SS_DESELECT;
	
	return make_u16t (byte1, byte2);
}