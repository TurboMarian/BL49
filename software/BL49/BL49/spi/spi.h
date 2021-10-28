/*
 * spi.h
 *
 * Created: 16.10.2021 22:37:10
 *  Author: Heinrich
 */ 


#ifndef SPI_H_
#define SPI_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>
#include "../config.h"
#include "../helpers.h"

void spi_init (void);
uint16_t spi_read_write (uint16_t data);

#endif /* SPI_H_ */