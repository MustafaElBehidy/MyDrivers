/*
 * KeyPad.c
 *
 * Created: 11/11/2018 12:04:48 AM
 *  Author: Mustafa El_Behidy
 */ 


#include "KeyPad.h"

int KeyPad_ROWS[] = { R0, R1, R2, R3 };
int KeyPad_COLS[] = { C0, C1, C2, C3 };
	
void KeyPad_INIT()
{
	DDRD &= ~((1<<R0) | (1<<R1) | (1<<R2) | (1<<R3));    // rows as input then pull up
	DDRD |= (1<<C0) | (1<<C1) | (1<<C2) | (1<<C3);      // columns as output
	PORTD = 0xFF;
}
char KeyPad_GetKey()
{
	int i, j;
	
	for (i = 0; i < 4; i++)
	{
		PORTD |= ( (1<<C0) | (1<<C1) | (1<<C2) | (1<<C3) );
		PORTD &= ~(1<<KeyPad_COLS[i]);
		
		for (j = 0; j < 4; j++)
		{
			if (!(PIND & (1<<KeyPad_ROWS[j])))
			{
				while (!(PIND & (KeyPad_ROWS[j])));
				switch(i)
				{
					case (0):
					{
						if (j == 0) return '7';
						else if (j == 1) return '4';
						else if (j == 2) return '1';
						else if (j == 3) return '?';
						break;
					}
					case (1):
					{
						if (j == 0) return '8';
						else if (j == 1) return '5';
						else if (j == 2) return '2';
						else if (j == 3) return '0';
						break;
					}
					case (2):
					{
						if (j == 0) return '9';
						else if (j == 1) return '6';
						else if (j == 2) return '3';
						else if (j == 3) return '=';
						break;
					}
					case (3):
					{
						if (j == 0) return '/';
						else if (j == 1) return '*';
						else if (j == 2) return '+';
						else if (j == 3) return '-';
						break;
					}
				}
				
			}
		}
	}
	return 'A';
}