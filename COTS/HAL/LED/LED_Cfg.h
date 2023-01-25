#ifndef LED_CFG_H
#define LED_CFG_H


#include "../../MCAL/DIO/DIO.h"

typedef enum
{
	LED_enuLED0=0,
	LED_enuLED1,
	LED_enuLED2,
	LED_enuNumberOfLEDS
	
}LED_tenuLEDS;

typedef enum
{
	LED_enuActiveHigh = 0,
	LED_enuActiveLow
	
}LED_tenuLEDMode;

typedef struct
{
	
	DIO_tenuPins LED_PIN;
	LED_tenuLEDMode LED_MODE;
	
}LED_strCfg_t;



extern LED_strCfg_t LED_strCfg[LED_enuNumberOfLEDS];



#endif /*LED_CFG_H*/