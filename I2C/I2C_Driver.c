/*
 * I2C_Driver.c
 *
 * Created: 11/27/2018 2:42:22 PM
 *  Author: Mustafa El_Behidy
 */ 


#include "I2C_Driver.h"

void I2C_Init(unsigned long SCL_Clock)
{
	TWBR = (unsigned char) (((F_CPU / SCL_Clock) - 16) / (2 * Prescaler) );
	if (Prescaler == 1)
		TWSR = 0;
	else if (Prescaler == 4)
		TWSR = 1;
	else if (Prescaler == 16)
		TWSR = 2;
	else if (Prescaler == 64)
		TWSR = 3;
}

void I2C_Start(void)
{
	TWCR |= (1<<TWINT) | (1<<TWEN) | (1<<TWSTA);
	while ( (TWCR & (1<<7)) == 0);  //wait to finish
	while (TWSR != 0x08);             // start condition has been sent
}
void I2C_Write(unsigned char cByte)
{
	TWDR = cByte;
	TWCR |= (1<<TWINT) | (1<<TWEN);
	while (TWSR != 0x08);            //wait to finish    
}
void I2C_Stop()
{
	TWCR |= (1<<TWINT) | (1<<TWEN) | (1<<TWSTO);
}
void I2C_Set_Address(unsigned char address)
{
	TWAR = address;
}
unsigned char I2C_Read(unsigned char ack)
{
	//unsigned char x = 0;
	TWCR |= (1<<TWINT) | (1<<TWEN) | (1<<TWEA);
	while ((TWCR & 1<<7) == 0);
	while ((TWSR) != 0x60);
		//x = TWSR;
	TWCR |= (1<<TWINT) | (1<<TWEN) | (1<<TWEA);
	while ((TWCR & 1<<7) == 0);
	while ((TWSR) != 0x80);
		//x = TWSR;
	return TWDR;
}