

#include "uart.h"

void UART_init(uint16_t BAUD_RATE)
{
	//Baud Rate
	UBRR_Value = lrint((F_CPU / (16L * BAUD_RATE))-1);
	UBRRL = (uint8_t) UBRR_Value;
	UBRRH = (uint8_t) (UBRR_Value>>8);
	// UCSRA RXC TXC UDRE
	// UCSRB RXCIE TXCIE UDRIE UCSZ2 RXEN TXEN
	UCSRB |= (1<<RXEN) | (1<<TXEN);
	// UCSRc UCSZ1 UCSZ0
	UCSRC |= (1<<UCSZ0) | (1<<UCSZ1);
	// UDR
}
void Send_char(char data)
{
	while(!(UCSRA & (1<<UDRE)));
	UDR = data;
}
void Send_String(char* word)
{
	while(*word > 0)
	{
		Send_char(*word);
		word++;
	}
	Send_char('\0');
}
char Recieve_char()
{
	while(!(UCSRA & (1<<RXC)));
	return UDR;
}