/*
 * SPI_DRIVER.c
 *
 * Created: 11/26/2018 12:19:16 PM
 *  Author: Mustafa El_Behidy
 */ 

#include "SPI_DRIVER.h"

void SPI_Master_Init()
{
	DDRB |= ( 1<<SS ) | ( 1<<MOSI ) | ( 1<<SCk );
	DDRB &= ~(1<<MISO);
	SPCR |= ( 1<<SPE ) | ( 1<<MSTR ) | ( 1<<SPR0 );
}
void SPI_Master_Init_With_Interrupt()
{
	DDRB |= ( 1<<SS ) | ( 1<<MOSI ) | ( 1<<SCk );
	DDRB &= ~(1<<MISO);
	SPCR |= ( 1<<SPE ) | ( 1<<MSTR ) | ( 1<<SPR0 ) | ( 1<<SPIE );
	sei();
}
void SPI_Slave_Init()
{
	DDRB &= ~( ( 1<<SS ) | ( 1<<MOSI ) | (1<<SCk ) );
	DDRB |= ( 1<<MISO );
	SPCR |= ( 1<<SPE );
}
void SPI_Slave_Init_With_Interrupt()
{
	DDRB &= ~( ( 1<<SS ) | ( 1<<MOSI ) | (1<<SCk ) );
	DDRB |= ( 1<<MISO );
	SPCR |= ( 1<<SPE ) | ( 1<<SPIE );
	sei();
}
unsigned char SPI_MASTER_Transmit(unsigned char cData)
{
	SPDR = cData;               //start transmission
	while(!(SPSR & (1<<SPIF))); //wait for transmission complete
	return SPDR;                // return Received Data
}
unsigned char SPI_SLAVE_Receive(unsigned char cData)
{
	SPDR = cData;                 // Send data to master
	while(!(SPSR & (1<<SPIF)));   // wait for reception complete
	return SPDR;                  // return received data
}