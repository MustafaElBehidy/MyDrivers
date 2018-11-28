/*
 * I2C_Driver.h
 *
 * Created: 11/27/2018 2:42:35 PM
 *  Author: Mustafa El_Behidy
 */ 


#ifndef I2C_DRIVER_H_
#define I2C_DRIVER_H_
#undef F_CPU
#define F_CPU 8000000UL
#define Prescaler 1
#include <avr/io.h>
#include <util/delay.h>

void I2C_Init(unsigned long SCL_Clock);
void I2C_Start(void);
void I2C_Write(unsigned char cByte);
void I2C_Stop(void);
void I2C_Set_Address(unsigned char address);
unsigned char I2C_Read(unsigned char ack);



#endif /* I2C_DRIVER_H_ */