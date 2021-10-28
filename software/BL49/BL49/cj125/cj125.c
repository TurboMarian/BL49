/*
 * cj125.c
 *
 * Created: 28.10.2021 15:46:40
 *  Author: Heinrich
 */ 

#include "cj125.h"
#include "cj125_register.h"

uint16_t cj125_read_ident (void)
{
	return spi_read_write(CJ125_IDENT_REG_REQUEST);
}

uint16_t cj125_read_diag (void)
{
	return spi_read_write(CJ125_DIAG_REG_REQUEST);
}