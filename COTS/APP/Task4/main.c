/*
 * button_segment_2.c
 *
 * Created: 24/01/2023 22:43:34
 * Author : HP
 */ 

#include "../../MCAL/DIO/DIO.h"
#include "../../HAL/BUTTON/button.h"
#include "../../HAL/S_SEGMENT/s_segment.h"
#include "../../LIB/Std_Types.h"
#include "../../LIB/delay.h"


int main(void)
{
	DIO_enuInit();
	s8 counter = 0;
	s8 counter2 = 0;
	u8 p;
	u8 p2;
    /* Replace with your application code */
    while (1) 
    {
		SsegmentDisplayValue(S_SEGMENT_PORTB,counter);
		SsegmentDisplayValue(S_SEGMENT_PORTC,counter2);
		ButtonIsPressed(0,&p);
		ButtonIsPressed(1,&p2);
		Delay_MS(100);
		if(p == 0)
		{
			
			counter++;
			if(counter > 9)
			{
				
				counter=0;
				counter2++;
				if(counter2 > 9)
				{
					counter2=0;
				}
			}

		}
		
		if(p2 == 0)
		{
			
			counter--;
			if(counter < 0)
			{
				
				counter=9;
				counter2--;
				if(counter2 < 0)
				{
					counter2=9;
				}
			}
		}
		
    }
}

