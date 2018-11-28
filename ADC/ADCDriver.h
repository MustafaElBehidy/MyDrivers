
/*  ADC Driver
	22/5/2018
	*/

#ifndef __ADCDRIVER_H__
#define __ADCDRIVER_H__
#define F_CPU 1000000UL
#include <avr/io.h>

volatile uint8_t ADC_Value;
void ADC_init();
uint8_t ADC_Converted_Value();

#endif