/*
 * LCD_Task2.c
 *
 * Created: 21/02/2023 14:17:30
 * Author : HP
 */ 



#include "Std_Types.h"
#include "delay.h"
#include "LCD.h"
#include "button.h"
#include "DIO.h"


#define p1 0
#define p2 1

u8 bar1[] = {
  0b10000,
  0b10000,
  0b10000,
  0b10000,
  0b10000,
  0b10000,
  0b10000,
  0b10000
};

u8 bar2[] = {
	0b00001,
	0b00001,
	0b00001,
	0b00001,
	0b00001,
	0b00001,
	0b00001,
	0b00001
};

u8 ball[] = {
	0b00000,
	0b00000,
	0b01110,
	0b01110,
	0b01110,
	0b00000,
	0b00000,
	0b00000
};
int main(void)
{
	DIO_enuInit();
	LCD_Init();
	u8 x1=0;
	u8 x2=0;
	u8 xb = 0;
	u8 yb = 7;
	u8 b1; 
	u8 b2;
	u8 flag = 0;
	u8 r_score = 0;
	u8 l_score = 0;
	LCD_DisplaySpecialChar(bar1,0,x1,0);
	LCD_DisplaySpecialChar(bar2,1,x2,15);
	LCD_DisplaySpecialChar(ball,2,0,7);

	/* Replace with your application code */
	while (1)
	{
		Delay_MS(200);
		LCD_Clear();
		LCD_GoToXY(0,2);
		LCD_WriteNum(l_score);
		LCD_GoToXY(0,13);
		LCD_WriteNum(r_score);
		LCD_DisplaySpecialChar(bar1,0,x1,0);
		LCD_DisplaySpecialChar(bar2,1,x2,15);
		LCD_DisplaySpecialChar(ball,2,xb,yb);
		
		ButtonIsPressed(p1,&b1);
		if (b1 == 0)
		{
			x1^=1;
			//Delay_MS(70);
		}
		
		ButtonIsPressed(p2,&b2);
		if (b2 == 0)
		{
			x2^=1;
			//Delay_MS(70);
		}
		
		
		
		if((yb > 0) && (yb < 15))
		{
			if (flag == 0)
			{
				yb++;
			}
			if (flag == 1)
			{
				yb--;
			}
			xb^=1;
		}
		else if(yb == 15)
		{
			flag^=1;
			yb--;
			xb^=1;
		}
		else if(yb == 0)
		{
			flag^=1;
			yb++;
			xb^=1;
		}
		if(yb == 0 && xb != x1)
		{
			r_score++;
			xb =0;
			yb = 7;
		}
		else if(yb == 15 && xb != x2)
		{
			l_score++;
			xb =0;
			yb = 7;
		}



	}
}


