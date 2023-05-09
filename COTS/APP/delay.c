#include "delay.h"
#include "../LIB/Std_Types.h"
#define F_CPU 8000000UL
#define amp 91.7

Delay_tenuErrorStatus Delay_MS(u32 time){

	Delay_tenuErrorStatus loc_ErrorStatus = DELAY_enuOK;
	u32 counter =0;
	u32 TIME;
	TIME = (u32)((float)time *amp*((float)F_CPU/1000000.0));
	if (TIME!=(time/1000)){
		loc_ErrorStatus = DELAY_enuNOK;
	}
	while(counter < TIME)
	{
		asm("NOP"); //processor do nothing
		counter++;
	}

	return loc_ErrorStatus;
}


Delay_tenuErrorStatus Delay_US(u32 time){

	Delay_tenuErrorStatus loc_ErrorStatus = DELAY_enuOK;
	u32 counter =0;
	u32 TIME;
	TIME = (u32)((float)time *amp*((float)F_CPU/1000000000.0));
	if (TIME!=(time/1000000)){
		loc_ErrorStatus = DELAY_enuNOK;
	}
	while(counter < TIME)
	{
		asm("NOP"); //processor do nothing
		counter++;
	}

	return loc_ErrorStatus;
}
