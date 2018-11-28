/*
 * Driver_LCD.h
 *
 * Created: 11/9/2018 2:09:26 PM
 *  Author: Mustafa El_Behidy
 */ 


#ifndef DRIVER_LCD_H_
#define DRIVER_LCD_H_

#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
#include <stdlib.h>
#include <stdio.h>

//#define LCD_PORT PORTA
//#define DATA_DIR_LCD_PORT DDRA
//#define DATA_Shift 0 // 0: 4 bit data mode | 4: 4 bit data mode
//#define LCD_control PORTB
//#define DATA_DIR_LCD_control DDRB
#define EN_Switch 3
#define ReadWrite 2
#define RS_Switch 1
#define DATA_SHIFT 0

//#define FOUR_BIT_MODE
#define EIGHT_BIT_MODE
#define LCD_FUNCTION_8BIT_2LINES 0X38
#define LCD_CONTROL PORTB
#define DataDir_LCD_CONTROL DDRB

void LCD_lcd_init(void);
void LCD_check_lcd_isbusy(void);
void LCD_lcd_kick(void);
void LCD_Send_A_Command(unsigned char command);
void LCD_Send_A_Character(unsigned char character);
void LCD_Send_A_String(char* string);
void LCD_clear_screen(void);
void LCD_GotoXY(unsigned char line, unsigned char position);
void LCD_display_number(int number);
void LCD_display_real_number(double number);


#endif /* DRIVER_LCD_H_ */