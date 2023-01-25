
#include "../../MCAL/DIO/DIO.h"
#include "LED.h"

LED_enuErrorStatus LED_ON(LED_tenuLEDS Cpy_enuLEDNumber)
{
	LED_enuErrorStatus currenterrorstatus = LED_enuOK;
	if(Cpy_enuLEDNumber>LED_enuNumberOfLEDS)
	{
		currenterrorstatus = LED_enuNOK;
	}
	
	if(LED_enuActiveHigh == LED_strCfg[Cpy_enuLEDNumber].LED_MODE)
	{
		DIO_enuSetPin(LED_strCfg[Cpy_enuLEDNumber].LED_PIN);
	}
	else if (LED_enuActiveLow == LED_strCfg[Cpy_enuLEDNumber].LED_MODE)
	{
		DIO_enuClearPin(LED_strCfg[Cpy_enuLEDNumber].LED_PIN);
	}
	return currenterrorstatus;
}

LED_enuErrorStatus LED_OFF(LED_tenuLEDS Cpy_enuLEDNumber)
{
	LED_enuErrorStatus currenterrorstatus = LED_enuOK;
	if(Cpy_enuLEDNumber>LED_enuNumberOfLEDS)
	{
		currenterrorstatus = LED_enuNOK;
	}
	
	if(LED_enuActiveHigh == LED_strCfg[Cpy_enuLEDNumber].LED_MODE)
	{
		DIO_enuClearPin(LED_strCfg[Cpy_enuLEDNumber].LED_PIN);
	}
	else if (LED_enuActiveLow == LED_strCfg[Cpy_enuLEDNumber].LED_MODE)
	{
		DIO_enuSetPin(LED_strCfg[Cpy_enuLEDNumber].LED_PIN);
	}
	return currenterrorstatus;
}