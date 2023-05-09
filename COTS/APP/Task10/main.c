/*
 * LCD_Driver.c
 *
 * Created: 10/02/2023 14:23:31
 * Author : HP
 */ 

#include "delay.h"
#include "DIO.h"
#include "LCD.h"
u8  heart[] = {
	0b01010,
	0b10101,
	0b10001,
	0b01010,
	0b00100,
	0b00000,
	0b00000,
	0b00000
};
u8 heart2[] = {
	0b01010,
	0b11111,
	0b11111,
	0b01110,
	0b00100,
	0b00000,
	0b00000,
	0b00000
};
u8 pattern1[] = {
	0b00100,
	0b01010,
	0b00100,
	0b01111,
	0b10100,
	0b00100,
	0b01010,
	0b10001
};
u8 pattern2[] = {
	0b00100,
	0b01010,
	0b00101,
	0b01110,
	0b10100,
	0b00100,
	0b01010,
	0b10001
};
u8 up_left[] = {
	0b00001,
	0b00001,
	0b00010,
	0b00100,
	0b11000,
	0b01000,
	0b11000,
	0b00100
};
u8 up_right[] = {
	0b10000,
	0b10000,
	0b01000,
	0b00100,
	0b00011,
	0b00010,
	0b00011,
	0b00100
};
u8 down_right[] = {
	0b00100,
	0b10000,
	0b10011,
	0b11110,
	0b11000,
	0b00000,
	0b00000,
	0b00000
};
u8 down_left[] = {
	0b00100,
	0b00001,
	0b11001,
	0b01111,
	0b00011,
	0b00000,
	0b00000,
	0b00000
};
int main(void)
{
	DIO_enuInit();
	LCD_Init();
	//LCD_WriteString("Karim was here");
	//Delay_MS(500);
	//LCD_Clear();
	//LCD_WriteNum(11111);
	//LCD_GoToXY(1,7);
	LCD_WriteString("May your <3 be");
	LCD_GoToXY(1,0);
	LCD_WriteString("your guiding key");
	Delay_MS(3000);
	LCD_Clear();
    while (1) 
    {
		LCD_DisplaySpecialChar(heart,0,0,0);
		Delay_MS(1000);
		LCD_Clear();
		LCD_DisplaySpecialChar(heart2,0,0,0);
		Delay_MS(1000);
		LCD_Clear();
		//Delay_MS(1000);
    }
}

