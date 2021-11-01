/*
 * BL49.c
 *
 * Created: 16.10.2021 23:06:12
 * Author : Heinrich
 */ 

#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>
#include <stdbool.h>
#include "adc/adc.h"
#include "dac/dac.h"
#include "can/can_lib.h"
#include "timer/timer.h"
#include "spi/spi.h"
#include "pwm/pwm.h"
#include "chip/chip.h"
#include "chip/gpio.h"
#include "cj125/cj125.h"
#include "cj125/cj125_register.h"
#include "probe/probe.h"

#include "config.h"
#include "helpers.h"

int main(void)
{
	chip_init();
	can_init(1);
	timer_delay_ms(50);
	adc_init();
	dac_init();
	spi_init();
	pwm_init();
	sei();
	
	uint16_t cj125_diag;
	uint16_t pwm_duty = 0;
	uint16_t timer_value = 0;
	uint16_t heater_voltage = 0;
	int counter = 0;
	
   	uint8_t pt_data[CAN_DLC];
	st_cmd_t msg;
	msg.id.ext = CAN_ID;
	msg.dlc = CAN_DLC;
	msg.cmd = CMD_TX_DATA;
	
	// check cj125 diag register after start, if all clear go to INIT:
	switch (cj125_diag = cj125_read_diag())
	{
		case CJ125_DIAG_REG_STATUS_OK:
			state = INIT;
		break;
		
		case CJ125_DIAG_REG_STATUS_NOSENSOR:
			state = NO_PROBE;
		break;
		
		case CJ125_DIAG_REG_STATUS_NOPOWER:
			state = ERROR;
		break;
	}
			
    while (1) 
    {
		gpio_read_inputs(&inputs);
		
		switch (state)
		{
			case INIT:
				state = CALIBRATE;
			break;
			
			case CALIBRATE:
				counter = 0;
				cj125_set_calibration_mode();
				while (counter < CJ125_CALIBRATION_SAMPLE_COUNT)
				{
					inputs.UA_opt += (adc_ua() + inputs.UOffset);
					inputs.UR_opt += (adc_ur() + inputs.UOffset);
					timer_delay_ms(10);
					counter++;
				}
				
				inputs.UA_opt /= CJ125_CALIBRATION_SAMPLE_COUNT;
				inputs.UR_opt /= CJ125_CALIBRATION_SAMPLE_COUNT;
				
				// go to normal mode, ampl. 8x
				cj125_end_calibration_mode_v8();
				
				state = CONDENSATE;
				
			break;
			
			case CONDENSATE:
				// heating the probe on 1.5v for 5 seconds
				heater_voltage = 1500;
				pwm_duty = calculate_pwm_for_voltage(heater_voltage);
				pwm_set_duty(pwm_duty);
				pt_data[4] = (uint8_t)((uint32_t)(inputs.UBat + inputs.UOffset)* 245UL / 1024UL);
				pt_data[5] = 15;
				pt_data[6] = (1 << 1);	// bosch lsu4.9
				pt_data[7] = 0xf;	// evap startup
				
				// stay for 5 seconds in this case and send every 10ms a can message
				for (int i = 0; i <= 500; i++)
				{
					while(can_cmd(&msg) != CAN_CMD_ACCEPTED); // wait for MOb to configure
					while(can_get_status(&msg) == CAN_STATUS_NOT_COMPLETED); // wait for a transmit request to come in, and send a response
					timer_delay_ms(10);					
				}
				
				state = PREHEATING;
				
			break;
			
			case PREHEATING:
				// bring the probe on temperature, start at 8v and go up to 13v with 0.4v/sec
				heater_voltage = 8000;
				gpio_read_inputs(&inputs);
				pwm_duty = calculate_pwm_for_voltage(heater_voltage);
				// pwm_set_duty(pwm_duty);
			
				pt_data[4] = (uint8_t)((uint32_t)(inputs.UBat + inputs.UOffset)* 245UL / 1024UL);
				pt_data[6] = (1 << 1);	// bosch lsu4.9
				pt_data[7] = 0x1;	// warm up
				
				while (heater_voltage < 13000)
				{
					
					// increate heater voltage every second
					if (timer_value != 0 && timer_value % 1000 == 0)
					{
						heater_voltage += 400;
						gpio_read_inputs(&inputs);
						// limit heater voltage to 13v
						if (heater_voltage > 13000) heater_voltage = 13000;
						pwm_duty = calculate_pwm_for_voltage(heater_voltage);
						// pwm_set_duty(pwm_duty);
					}
					
					pt_data[5] = (uint8_t)((float) heater_voltage *0.01f);
					timer_delay_ms(10);
					timer_value += 10;
					
					while(can_cmd(&msg) != CAN_CMD_ACCEPTED); // wait for MOb to configure
					while(can_get_status(&msg) == CAN_STATUS_NOT_COMPLETED); // wait for a transmit request to come in, and send a response
				}
				
				// preheating done, go to run
				state = RUNNING;
			
			break;
			
			case RUNNING:
			// TODO: PID
			
			break;
			
			
			case ERROR:
			case NO_PROBE:
			
				pwm_duty = 10;
			
			break;
			
		}
		/*
		while(can_cmd(&msg) != CAN_CMD_ACCEPTED); // wait for MOb to configure
		while(can_get_status(&msg) == CAN_STATUS_NOT_COMPLETED); // wait for a transmit request to come in, and send a response
		dac_value(1080);
		LED2_TOG;
		timer_delay_ms(10);
		*/
		
		// LED2_TOG;
		/*
		retVal = cj125_read_ident();
		
		retVal = cj125_read_diag();
		
		power_ok = is_ubat_ok();
		
		timer_delay_ms(200);
		*/
	}
   
}
