/*
 * button_last.c
 *
 * Created: 27/01/2023 09:33:57
 * Author : HP
 */ 

#include "../../MCAL/DIO/DIO.h"
#include "../../HAL/LED/LED.h"
#include "../../HAL/BUTTON/button.h"
#include "../../LIB/delay.h"
#include "../../LIB/Std_types.h"


int main(void)
{
	DIO_enuInit();
	u8 p1;
	u8 p2;
	s8 counter=0;
    /* Replace with your application code */
    while (1) 
    {
		ButtonIsPressed(0,&p1);
		ButtonIsPressed(1,&p2);
		Delay_MS(200);
		if(p1 == 0)
		{
			LED_ON(counter);
			counter++;
			if(counter > 2)
			{
				counter = 2;
			}
		}
		if(p2 == 0)
		{
			LED_OFF(counter);
			counter--;
			if(counter < 0)
			{
				counter = 0;
			}
		}
		
    }
}

