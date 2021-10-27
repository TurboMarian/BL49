/*
 * config.h
 *
 * Created: 16.10.2021 15:10:09
 *  Author: Heinrich
 */ 


#ifndef CONFIG_H_
#define CONFIG_H_

#include <avr/io.h>
#include <avr/interrupt.h>

#ifndef F_CPU
#warning "F_CPU war noch nicht definiert, wird nun mit 16MHz definiert"
#define F_CPU 16000000     /* Quarz mit 16 Mhz */
#endif

#ifndef FOSC
#warning "FOSC war noch nicht definiert, wird nun mit F_CPU/1000 definiert"
#define FOSC	F_CPU/1000
#endif

#ifndef CAN_BAUDRATE
#warning "CAN_BAUDRATE war noch nicht definiert, wird nun mit 500kbit definiert"
#define CAN_BAUDRATE	500
#endif

#define CAN_ID		0x180
#define CAN_DLC		8

// leds
#define LEDS			DDRB
#define LEDS_PORT		PORTB
#define LED2			PB5
#define LED3			PB6
#define LED2_ON			(LEDS_PORT |= (1 << LED2))
#define LED2_OFF		(LEDS_PORT &= ~(1 << LED2))
#define LED2_TOG		(LEDS_PORT ^= (1 << LED2))
#define LED3_ON			(LEDS_PORT |= (1 << LED3))
#define LED3_OFF		(LEDS_PORT &= ~(1 << LED3))
#define LED3_TOG		(LEDS_PORT ^= (1 << LED3))

#endif /* CONFIG_H_ */