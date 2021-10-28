/*
 * pwm.h
 *
 * Created: 28.10.2021 08:45:38
 *  Author: Heinrich
 */ 


#ifndef PWM_H_
#define PWM_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>
#include <stdbool.h>
#include "../config.h"
#include "../helpers.h"

void pwm_init (void);
void pwm_set_duty (uint16_t duty);

#endif /* PWM_H_ */