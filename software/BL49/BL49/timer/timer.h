/*
 * timer.h
 *
 * Created: 16.10.2021 21:58:27
 *  Author: Heinrich
 */ 


#ifndef TIMER_H_
#define TIMER_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>
#include "../config.h"
#include "../can/can_lib.h"


// timer0: 8-bit
// timer1: 16-bit

void timer0_init (void);
void timer_delay_ms (uint16_t delay);


#endif /* TIMER_H_ */