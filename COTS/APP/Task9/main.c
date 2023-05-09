/*
 * LM35_Driver.c
 *
 * Created: 09/02/2023 19:35:49
 * Author : HP
 */ 

#include "Std_Types.h"
#include "DIO.h"
#include "ADC.h"
#include "LM35.h"
#include "s_segment.h"

int main(void)
{
	DIO_enuInit();
	ADC_Init();
	u16 val;
	u16 p1;
	u16 p2;
    /* Replace with your application code */
    while (1) 
    {
		LM35_ReadValue(0, &val);
		p1 = val%10;
		p2 = val/10;
		SsegmentDisplayValue(DIO_enuPORTC,p2);
		SsegmentDisplayValue(DIO_enuPORTD,p1);
    }
}

