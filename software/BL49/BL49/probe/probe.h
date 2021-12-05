/*
 * probe.h
 *
 * Created: 31.10.2021 13:18:51
 *  Author: Heinrich
 */ 


#ifndef PROBE_H_
#define PROBE_H_

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>
#include <stdbool.h>
#include "../helpers.h"
#include "../config.h"

typedef enum
{
	INIT
	, NO_PROBE
	, WAIT_FOR_START
	, CONDENSATE
	, PREHEATING
	, CALIBRATE
	, RUNNING
	, ERROR
} probeState;

extern probeState state;



#endif /* PROBE_H_ */