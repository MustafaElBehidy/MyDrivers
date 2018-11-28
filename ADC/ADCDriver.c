

#include "ADCDriver.h"

void ADC_init()
{
	ADCSRA |= (1<<ADEN);   //Enable
	ADCSRA |= (1<<ADPS0) | (1<<ADPS1);  // prescalar register
	ADMUX |= (1<<MUX1);  // PA1 channel
	ADMUX |= (1<<ADLAR); //8 bit ADC
}
uint8_t ADC_Converted_Value()
{
	ADCSRA |= (1<<ADSC);
	while(ADCSRA & (1<<ADSC));
	ADC_Value = ADCH;
	return ADC_Value;
}