#ifndef 	DELAY_H
#define 	DELAY_H


#include "Std_Types.h"


typedef enum {
	DELAY_enuNOK  = 0,
	DELAY_enuOK     
}Delay_tenuErrorStatus;

/****************************************************************/
/*    delay ms Function										*/
/*	  Input  : Time passed to halt system with [MILLIS]			*/
/*	  Output : DIO_tenuErrorStatus to Report Errors				*/
/****************************************************************/
Delay_tenuErrorStatus Delay_MS(u32 time);


/****************************************************************/
/*    delay us Function										*/
/*	  Input  : Time passed to halt system with 	[MICROS]		*/
/*	  Output : DIO_tenuErrorStatus to Report Errors				*/
/****************************************************************/
Delay_tenuErrorStatus Delay_US(u32 time);



#endif /*DELAY_H*/