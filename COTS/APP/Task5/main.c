/*
 * External_Interrupt.c
 *
 * Created: 27/01/2023 11:01:35
 * Author : HP
 */ 

#include "Std_Types.h"
#include "DIO.h"
#include "LED.h"
#include "button.h"
#include "delay.h"
#include "EXT_INT.h"
#include "s_segment.h"
#include <avr/interrupt.h>

s8 count=0;

ISR (INT0_vect)          //External interrupt_zero ISR
{
	
	count++;
	if(count > 9) count=0;
	
}

ISR (INT1_vect)          //External interrupt_one ISR
{
	
	count--;
	if(count < 0) count=9;
	
}


int main(void)
{
	DIO_enuInit();
	EXT_INT_init();
	
    /* Replace with your application code */
    while (1) 
    {
		SsegmentDisplayValue(0,count);
    }
}

