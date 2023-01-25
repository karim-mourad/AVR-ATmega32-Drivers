/*
 * seven_segment.c
 *
 * Created: 22/01/2023 14:31:45
 * Author : HP
 */ 

#include "../../LIB/Std_Types.h"
#include "../../MCAL/DIO/DIO.h"
#include "../../LIB/delay.h"
#include "../../HAL/S_SEGEMENT/s_segment.h"

int main(void)
{
	DIO_enuInit();
	u8 counter=0;
	u8 counter2=0;
    /* Replace with your application code */
    while (1) 
    {	
			SsegmentDisplayValue(S_SEGMENT_PORTA,counter);
			SsegmentDisplayValue(S_SEGMENT_PORTB,counter2);
						
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

			Delay_MS(500);
		} 
		
		
    
}

