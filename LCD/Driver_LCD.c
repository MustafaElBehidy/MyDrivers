/*
 * Driver_LCD.c
 *
 * Created: 11/9/2018 2:09:11 PM
 *  Author: Mustafa El_Behidy
 */ 

#include "Driver_LCD.h"

void LCD_lcd_init()
{
	_delay_ms(20);
	DataDir_LCD_CONTROL |= ( 1<<RS_Switch | 1<<EN_Switch | 1<<ReadWrite );   //DataDir_LCD_CONTROL AS OUTPUT
	LCD_CONTROL &= ~( 1<<RS_Switch | 1<<EN_Switch | 1<<ReadWrite ); //LCD_CONTROL
	
	DDRA = 0xFF;   //LCD_PORT AS OUTPUT
	_delay_ms(15);
	LCD_clear_screen();
	
#ifdef EIGHT_BIT_MODE
	LCD_Send_A_Command(LCD_FUNCTION_8BIT_2LINES);  //LCD_FUNCTION_8BIT_2LINES
#endif
#ifdef FOUR_BIT_MODE
	
	LCD_Send_A_Command(0x02);
	LCD_Send_A_Command(0x28);  //LCD_FUNCTION_4BIT_2LINES

#endif
	LCD_Send_A_Command(0x06);  //LCD_ENTRY_MODE
	LCD_Send_A_Command(0x80);  //LCD_BEGIN_AT_FIRST_RAW
	LCD_Send_A_Command(0x0F);  //LCD_DISP_ON_CURSOR_BLINK
}

void LCD_check_lcd_isbusy(void)
{
	DDRA &= ~(0xFF<<DATA_SHIFT); //PORTA as INPUT
	// LCD CONTROL BY DEFAULT OUTPUT FROM INIT
	PORTB |= (1<<ReadWrite);  // LCD READ MODE
	PORTB |= (1<<RS_Switch);  //  LCD COMMAND MODE
	while (!(PINA & (1<<PA7)))
	{
		LCD_lcd_kick();
		//_delay_ms(50);
	}
	DDRA |= 0xFF;
	PORTB &= ~(1<<ReadWrite);  //WRITE
}
void LCD_lcd_kick(void)   //disable then enable 
{
	PORTB &= ~(1<<EN_Switch);
	asm volatile ("nop");
	asm volatile ("nop");
	_delay_ms(50);
	PORTB |= (1<<EN_Switch);
}
void LCD_Send_A_Command(unsigned char command)
{
#ifdef EIGHT_BIT_MODE
	LCD_check_lcd_isbusy();
	PORTA = command;
	PORTB &= ~((1<<RS_Switch) | (1<<ReadWrite));  // write and command mode
	LCD_lcd_kick();
#endif
#ifdef FOUR_BIT_MODE
	LCD_check_lcd_isbusy();
	PORTA = (PORTA & 0xF0) | (command & 0xF0);
	PORTB &= ~((1<<ReadWrite) | (1<<RS_Switch));
	LCD_lcd_kick();
	
	PORTA = (PORTA & 0xF0) | (command << 4);
	PORTB &= ~((1<<ReadWrite) | (1<<RS_Switch));
	LCD_lcd_kick();
#endif
}
void LCD_Send_A_Character(unsigned char character)
{
#ifdef EIGHT_BIT_MODE
	LCD_check_lcd_isbusy();
	
	PORTB &= ~(1<<ReadWrite);
	PORTB |= (1<<RS_Switch);
	PORTA = character;
	LCD_lcd_kick();
#endif
#ifdef FOUR_BIT_MODE
	LCD_check_lcd_isbusy();
	
	PORTB &= ~(ReadWrite);
	PORTB |= (1<<RS_Switch);
	PORTA = (PORTA & 0x0F) | (character & 0xF0);
	LCD_lcd_kick();
	
	PORTB &= ~(ReadWrite);
	PORTB |= (1<<RS_Switch);
	PORTA = (PORTA & 0xF0) | (character << 4);
	LCD_lcd_kick();
#endif
}
void LCD_clear_screen(void)
{
	LCD_Send_A_Command(0x01);    //LCD_CLEAR_SCREEN
}
void LCD_Send_A_String(char* string)
{
	int count = 0;
	while (*string > 0)
	{
		count++;
		LCD_Send_A_Character(*string++);
		if (count == 16)
		{
			LCD_GotoXY(1, 0);
		}
		else if (count == 32)
		{
			LCD_clear_screen();
			LCD_GotoXY(0, 0);
			count = 0;
		}
	}
}
void LCD_GotoXY(unsigned char line, unsigned char position)
{
	if (line == 0)
	{
		if ((position < 16) & (position >= 0))
		{
			LCD_Send_A_Command(0x80 + position);
		}
	}
	else if (line == 1)
	{
		if ((position < 16) & (position >= 0))
		{
			LCD_Send_A_Command(0xC0 + position);
		}
	}
}
void LCD_display_number(int number);
void LCD_display_real_number(double number);