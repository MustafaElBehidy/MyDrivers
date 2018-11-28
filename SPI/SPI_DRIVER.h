/*
 * SPI_DRIVER.h
 *
 * Created: 11/26/2018 12:19:36 PM
 *  Author: Mustafa El_Behidy
 */ 

//#define F_CPU 1000000UL

#ifndef SPI_DRIVER_H_
#define SPI_DRIVER_H_

#define F_CPU 1000000UL
#include <avr/io.h>
#include <util/delay.h>
#include <avr/interrupt.h>


#define SS   4
#define MOSI 5
#define MISO 6
#define SCk  7

void SPI_Master_Init();
void SPI_Master_Init_With_Interrupt();
void SPI_Slave_Init();
void SPI_Slave_Init_With_Interrupt();
unsigned char SPI_MASTER_Transmit(unsigned char cData);
unsigned char SPI_SLAVE_Receive(unsigned char);


#endif /* SPI_DRIVER_H_ */