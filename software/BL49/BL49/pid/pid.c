/*
 * pid.c
 *
 * Created: 05.12.2021 20:49:54
 *  Author: Heinrich
 */ 

#include "pid.h"

uint16_t pid_control (uint16_t inputValue, uint16_t UR_calibration)
{
	  //Calculate error term.
	  uint16_t error = UR_calibration - inputValue;
	  
	  //Set current position.
	  uint16_t position = inputValue;
	  
	  //Calculate proportional term.
	  float pTerm = -pGain * error;
	  
	  //Calculate the integral state with appropriate limiting.
	  iState += error;
	  
	  if (iState > iMax) iState = iMax;
	  if (iState < iMin) iState = iMin;
	  
	  //Calculate the integral term.
	  float iTerm = -iGain * iState;
	  
	  //Calculate the derivative term.
	  float dTerm = -dGain * (dState - position);
	  dState = position;
	  
	  //Calculate regulation (PI).
	  uint16_t RegulationOutput = pTerm + iTerm + dTerm;
	  
	  //Set maximum heater output (full power).
	  if (RegulationOutput > 255) RegulationOutput = 255;
	  
	  //Set minimum heater value (cooling).
	  if (RegulationOutput < 0.0) RegulationOutput = 0;

	  //Return calculated PWM output.
	  return RegulationOutput;
}