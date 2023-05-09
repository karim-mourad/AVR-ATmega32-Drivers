/*
 * ADC_driver.c
 *
 * Created: 06/02/2023 13:52:49
 * Author : HP
 */ 

#include "Std_Types.h"
#include "DIO.h"
#include "ADC.h"
#include "s_segment.h"


int main(void)
{
	DIO_enuInit();
	ADC_Init();
	u16 key = 0;
	u16 p1;
	u16 p2;
    /* Replace with your application code */
    while (1) 
    {
		ADC_Read_Value(0,&key);
		key /= 10;
		if(key > 99)
		{
			SsegmentDisplayValue(S_SEGMENT_PORTB,9);
			SsegmentDisplayValue(S_SEGMENT_PORTC,9);
		}
		else if (key < 0)
		{
			SsegmentDisplayValue(S_SEGMENT_PORTB,0);
			SsegmentDisplayValue(S_SEGMENT_PORTC,0);
		}
		else
		{
			p1 = key%10;
			p2 = key/10;
			SsegmentDisplayValue(S_SEGMENT_PORTB,p1);
			SsegmentDisplayValue(S_SEGMENT_PORTC,p2);
		}


    }
}

