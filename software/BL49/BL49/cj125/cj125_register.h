/*
 * cj125_register.h
 *
 * Created: 28.10.2021 15:47:56
 *  Author: Heinrich
 */ 


#ifndef CJ125_REGISTER_H_
#define CJ125_REGISTER_H_

// cj125 registers

#define CJ125_IDENT_REG_REQUEST         0x4800	/* Identify request, gives revision of the chip. */
#define CJ125_DIAG_REG_REQUEST          0x7800	/* Dignostic request, gives the current status. */
#define CJ125_INIT_REG1_REQUEST         0x6C00 	/* Requests the first init register. */
#define CJ125_INIT_REG2_REQUEST         0x7E00  /* Requests the second init register. */
#define CJ125_INIT_REG1_MODE_CALIBRATE	0x569D  /* Sets the first init register in calibration mode. */
#define CJ125_INIT_REG1_MODE_NORMAL_V8  0x5688  /* Sets the first init register in operation mode. V=8 amplification. */
#define CJ125_INIT_REG1_MODE_NORMAL_V17 0x5689  /* Sets the first init register in operation mode. V=17 amplification. */
#define CJ125_INIT_REG1_STATUS_0        0x2888  /* The response of the init register when V=8 amplification is in use. */
#define CJ125_INIT_REG1_STATUS_1        0x2889	/* The response of the init register when V=17 amplification is in use. */

// diag register status:
#define CJ125_DIAG_REG_STATUS_OK        0x28FF  /* The response of the diagnostic register when everything is ok. */
#define CJ125_DIAG_REG_STATUS_NOPOWER   0x2855  /* The response of the diagnostic register when power is low. */
#define CJ125_DIAG_REG_STATUS_NOSENSOR  0x287F  /* The response of the diagnostic register when no sensor is connected. */

// some config:
#define CJ125_CALIBRATION_SAMPLE_COUNT	10
#define CJ125_PUMP_FACTOR				1000
#define CJ125_PUMP_RES_SHUNT			61.9


#endif /* CJ125_REGISTER_H_ */