#ifndef LED_H
#define LED_H

#include "LED_Cfg.h"

typedef enum
{
	LED_enuOK=0,
	LED_enuNOK
}LED_enuErrorStatus;


LED_enuErrorStatus LED_ON(LED_tenuLEDS Cpy_enuLEDNumber);
LED_enuErrorStatus LED_OFF(LED_tenuLEDS Cpy_enuLEDNumber);


#endif /*LED_H*/