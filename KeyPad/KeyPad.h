/*
 * KeyPad.h
 *
 * Created: 11/11/2018 12:04:28 AM
 *  Author: Mustafa El_Behidy
 */ 


#ifndef KEYPAD_H_
#define KEYPAD_H_
#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>

#define R0 0
#define R1 1
#define R2 2
#define R3 3
#define C0 4
#define C1 5
#define C2 6
#define C3 7

void KeyPad_INIT();
char KeyPad_GetKey();


#endif /* KEYPAD_H_ */