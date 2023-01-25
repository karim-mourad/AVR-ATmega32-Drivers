#ifndef BUTTON_CFG_H
#define BUTTON_CFG_H


#include "../../MCAL/DIO/DIO.h"


typedef enum
{
	
	BUTTON_enuPIN0=0,
	BUTTON_enuPIN1,
	BUTTON_enuNumberOfButtons
		
}BUTTON_tenuBUTTONS;

typedef enum
{
	BUTTON_enuPull_Up= 0,
	BUTTON_enuPull_Down
	
}BUTTON_tenuButtonMode;


typedef struct 
{
	DIO_tenuPins BUTTON_PIN;
	BUTTON_tenuButtonMode BUTTON_MODE;
}BUTTON_strCfg_t;


extern BUTTON_strCfg_t Button_strCfg[BUTTON_enuNumberOfButtons];


#endif /*BUTTON_CFG_H*/