#ifndef BUTTON_H
#define BUTTON_H

#include "button_Cfg.h"


typedef enum
{
	BUTTON_enuOK=0,
	BUTTON_enuNOK
	
}BUTTON_enuErrorStatus;


BUTTON_enuErrorStatus ButtonIsPressed(BUTTON_tenuBUTTONS Cpy_enuPinNNumber,u8* Add_Pu8pinValue);



#endif /*BUTTON_H*/