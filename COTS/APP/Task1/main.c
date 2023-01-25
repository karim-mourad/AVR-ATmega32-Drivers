/*
 * TASK1.c
 *
 * Created: 18/01/2023 13:35:49
 * Author : HP
 */ 

#include "../../MCAL/DIO/DIO.h"
#include "../../HAL/LED/LED.h"
#include "../../LIB/delay.h"
#include "../../LIB/Std_Types.h"



int main(void)
{
	DIO_enuInit();
	/* Replace with your application code */
	while (1)
	{
		u8 i;
		for(i=0;i<8;i++)
			{
				LED_ON(i);
				Delay_MS(350);
				LED_OFF(i);
				Delay_MS(350);
			}
		
	}
}

