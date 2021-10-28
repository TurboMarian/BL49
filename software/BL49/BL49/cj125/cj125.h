/*
 * cj125.h
 *
 * Created: 28.10.2021 15:47:45
 *  Author: Heinrich
 */ 


#ifndef CJ125_H_
#define CJ125_H_

#include "../spi/spi.h"
#include "../config.h"

uint16_t cj125_read_ident (void);
uint16_t cj125_read_diag (void);

#endif /* CJ125_H_ */