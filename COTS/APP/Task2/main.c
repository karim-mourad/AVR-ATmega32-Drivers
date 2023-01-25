/*
 * deif.c
 *
 * Created: 19/01/2023 16:52:50
 * Author : HP
 */ 

#include "../../MCAL/LIB"DIO.h"
#include "../../HAL/LED/LED.h"
#include "../../LIB/Std_Types.h"
#include "../../LIB/delay.h"


int main(void)
{
	DIO_enuInit();
	u8 p1;
	u8 p2;
	u8 counter=2;
    /* Replace with your application code */
    while (1) 
    {
		SWITCH_IsPressed(0,&p1);
		Delay_MS(120);
		if (p1==1 && counter<6)
		{
			LED_ON(counter);
			counter++;
		}
		SWITCH_IsPressed(1,&p2);
		Delay_MS(120);
		if (p2==1 && counter>0)
		{
			LED_OFF(counter);
			counter--;
		}
		
    }
}

