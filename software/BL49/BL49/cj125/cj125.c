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

void cj125_set_calibration_mode (void)
{
	spi_read_write(CJ125_INIT_REG1_MODE_CALIBRATE);
}

void cj125_end_calibration_mode_v8 (void)
{
	spi_read_write(CJ125_INIT_REG1_MODE_NORMAL_V8);
}

void cj125_end_calibration_mode_v17 (void)
{
	spi_read_write(CJ125_INIT_REG1_MODE_NORMAL_V17);
}