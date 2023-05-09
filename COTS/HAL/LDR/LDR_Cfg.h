#ifndef LDR_CFG_H_
#define LDR_CFG_H_

#include "DIO.h"


typedef enum
{
	LDR_enuLDR0 = 0,
	LDR_enuLDRNumber
	
}LDR_tenuLDRs;




typedef enum
{
	LDR_enuNOK = 0,
	LDR_enuOK
	
}LDR_tenuErrorStatus;


typedef struct 
{
	DIO_tenuPins LDR_Pin;
}LDR_strCfg_t;

extern LDR_strCfg_t LDR_strCfg[LDR_enuLDRNumber];



#endif /* LDR_CFG_H_ */