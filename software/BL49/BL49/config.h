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
#define CPC1017			PB3
#define LED2			PB5
#define LED3			PB6
#define CPC1017_ON		(LEDS_PORT |= (1 << CPC1017))
#define CPC1017_OFF		(LEDS_PORT &= ~(1 << CPC1017))
#define LED2_ON			(LEDS_PORT |= (1 << LED2))
#define LED2_OFF		(LEDS_PORT &= ~(1 << LED2))
#define LED2_TOG		(LEDS_PORT ^= (1 << LED2))
#define LED3_ON			(LEDS_PORT |= (1 << LED3))
#define LED3_OFF		(LEDS_PORT &= ~(1 << LED3))
#define LED3_TOG		(LEDS_PORT ^= (1 << LED3))

// spi
#define SPI_MOSI		PB1
#define SPI_SCK			PB7
#define SPI_SS			PD5
#define SPI_SS_SELECT	(PORTD &= ~(1 << SPI_SS))
#define SPI_SS_DESELECT	(PORTD |= (1 << SPI_SS))

// checks for adc
#define UBat_MIN		0x01C4	// 10,8V; 0x01C4 => 452 => 10,81V
#define UBat_MAX		0x02B0	// 16,5V; 0x02B0 => 688 => 16,46V

// heater
#define	HEATER_PIN		PC1
#define HEATER_PORT		PORTC
#define HEATER_ON		(HEATER_PORT &= ~(1 << HEATER_PIN))
#define HEATER_OFF		(HEATER_PORT |= (1 << HEATER_PIN))
#define HEATER_TOG		(HEATER_PORT ^= (1 << HEATER_PIN))
#define HEATER_MAX_V	0x021F	// 13V

#endif /* CONFIG_H_ */