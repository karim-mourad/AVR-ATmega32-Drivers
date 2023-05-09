/*
 * LDR_Driver.c
 *
 * Created: 09/02/2023 10:19:58
 * Author : HP
 */ 

#include "Std_Types.h"
#include "delay.h"
#include "DIO.h"
#include "ADC.h"
#include "LED.h"
#include "LDR.h"
#include "s_segment.h"


int main(void)
{
	DIO_enuInit();
	ADC_Init();
	u16 val;
    /* Replace with your application code */
    while (1) 
    {
		LDR_ReadValue(0,&val);
		val /= 10;
		SsegmentDisplayValue(2,val);
		if(val <0 || val < 10)
		{
			LED_ON(0);
			LED_ON(1);
			LED_ON(2);
			LED_ON(3);
			LED_ON(4);
			LED_ON(5);
			LED_ON(6);
			LED_ON(7);
		}
		else if (val>10 && val<20)
		{
			LED_ON(0);
			LED_ON(1);
			LED_ON(2);
			LED_ON(3);
			LED_ON(4);
			LED_ON(5);
			LED_ON(6);
			LED_OFF(7);
		}
		else if (val>20 && val<30)
		{
			LED_ON(0);
			LED_ON(1);
			LED_ON(2);
			LED_ON(3);
			LED_ON(4);
			LED_ON(5);
			LED_OFF(6);
			LED_OFF(7);
		}
		else if (val>30 && val<40)
		{
			LED_ON(0);
			LED_ON(1);
			LED_ON(2);
			LED_ON(3);
			LED_ON(4);
			LED_OFF(5);
			LED_OFF(6);
			LED_OFF(7);
		}
		else if (val>40 && val<50)
		{
			LED_ON(0);
			LED_ON(1);
			LED_ON(2);
			LED_ON(3);
			LED_OFF(4);
			LED_OFF(5);
			LED_OFF(6);
			LED_OFF(7);
		}
		else if (val>50 && val<60)
		{
			LED_ON(0);
			LED_ON(1);
			LED_ON(2);
			LED_OFF(3);
			LED_OFF(4);
			LED_OFF(5);
			LED_OFF(6);
			LED_OFF(7);
		}
		else if (val>60 && val<70)
		{
			LED_ON(0);
			LED_ON(1);
			LED_OFF(2);
			LED_OFF(3);
			LED_OFF(4);
			LED_OFF(5);
			LED_OFF(6);
			LED_OFF(7);
		}
		else if (val>70 && val<80)
		{
			LED_ON(0);
			LED_OFF(1);
			LED_OFF(2);
			LED_OFF(3);
			LED_OFF(4);
			LED_OFF(5);
			LED_OFF(6);
			LED_OFF(7);
		}
		else if (val>80)
		{
			LED_OFF(0);
			LED_OFF(1);
			LED_OFF(2);
			LED_OFF(3);
			LED_OFF(4);
			LED_OFF(5);
			LED_OFF(6);
			LED_OFF(7);
		}
		
		
		
    }
}

