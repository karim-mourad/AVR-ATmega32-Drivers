#include "../../MCAL/DIO/DIO.h"
#include "LED_Cfg.h"


LED_strCfg_t LED_strCfg[LED_enuNumberOfLEDS] =
{
	{DIO_enuPin2,LED_enuActiveHigh},
	{DIO_enuPin3,LED_enuActiveHigh},
	{DIO_enuPin4,LED_enuActiveHigh}
};
