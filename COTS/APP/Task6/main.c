/*
 * keypad_test.c
 *
 * Created: 31/01/2023 12:51:16
 * Author : HP
 */ 

#include "DIO.h"
#include "keypad.h"
#include "s_segment.h"
#include "Std_Types.h"
#include "delay.h"

int main(void)
{
	DIO_enuInit();
	u8 x;
    /* Replace with your application code */
    while (1) 
    {
		keypad_get(&x);
		SsegmentDisplayValue(S_SEGMENT_PORTA,x);
    }
}

