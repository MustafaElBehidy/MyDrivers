
/*
	UART Driver V1.0
	Mustafa El Behidy
	22/5/2018
	this is is UART driver for atmega16 and atmega32
*/


#ifndef __UART_H__
#define __UART_H__

#define F_CPU 16000000UL
#include <avr/io.h>
#include <math.h>


uint16_t UBRR_Value;
void UART_init(uint16_t BAUD_RATE);
void Send_char(char data);
void Send_String(char* word);
char Recieve_char();

#endif
