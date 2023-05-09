/*
 * LCD_Task1.c
 *
 * Created: 18/02/2023 20:28:20
 * Author : HP
 */ 

#include "Std_Types.h"
#include "delay.h"
#include "LCD.h"
#include "button.h"
#include "DIO.h"

#define right 0
#define left  1
#define down    2
#define up  3

u8 k[] = {
  0b00111,
  0b00100,
  0b00100,
  0b11100,
  0b00000,
  0b00000,
  0b00000,
  0b00000
};

u8 rr[] = {
	0b00000,
	0b00000,
	0b00000,
	0b00001,
	0b00001,
	0b00010,
	0b00100,
	0b11000
};

u8 i[] = {
	0b00000,
	0b00000,
	0b00001,
	0b00001,
	0b11111,
	0b00000,
	0b01010,
	0b00000
};

u8 m[] = {
	0b00000,
	0b00111,
	0b00101,
	0b11111,
	0b10000,
	0b10000,
	0b10000,
	0b10000
};


int main(void)
{
	DIO_enuInit();
	LCD_Init();
	u8 x=0;
	u8 y=0;
	u8 r;
	u8 l;
	u8 u;
	u8 d;
	LCD_DisplaySpecialChar(k,0,0,3);
	LCD_DisplaySpecialChar(rr,1,0,2);
	LCD_DisplaySpecialChar(i,2,0,1);
	LCD_DisplaySpecialChar(m,3,0,0);
    /* Replace with your application code */
    while (1) 
    {
		
		ButtonIsPressed(left,&l);
		if( l == 0)
		{
			
			if(y > 0)
			{
				y--;
				LCD_Clear();
				LCD_DisplaySpecialChar(k,0,x,(y+3));
				LCD_DisplaySpecialChar(rr,1,x,(y+2));
				LCD_DisplaySpecialChar(i,2,x,(y+1));
				LCD_DisplaySpecialChar(m,3,x,(y));
			}
			
		}
		ButtonIsPressed(right,&r);
		if( r == 0)
		{
			
			if(y <= 11)
			{
				y++;
				LCD_Clear();
				LCD_DisplaySpecialChar(k,0,x,(y+3));
				LCD_DisplaySpecialChar(rr,1,x,(y+2));
				LCD_DisplaySpecialChar(i,2,x,(y+1));
				LCD_DisplaySpecialChar(m,3,x,y);
			}
			
		}
		ButtonIsPressed(down,&d);
		if( d == 0)
		{
			
			if(x == 0)
			{
				x++;
				LCD_Clear();
				LCD_DisplaySpecialChar(k,0,x,(y+3));
				LCD_DisplaySpecialChar(rr,1,x,(y+2));
				LCD_DisplaySpecialChar(i,2,x,(y+1));
				LCD_DisplaySpecialChar(m,3,x,y);
			}
			
		}
		
		ButtonIsPressed(up,&u);
		if( u == 0)
		{
			
			if(x == 1)
			{
				x--;
				LCD_Clear();
				LCD_DisplaySpecialChar(k,0,x,(y+3));
				LCD_DisplaySpecialChar(rr,1,x,(y+2));
				LCD_DisplaySpecialChar(i,2,x,(y+1));
				LCD_DisplaySpecialChar(m,3,x,y);
			}
			
		}
		
    }
}

