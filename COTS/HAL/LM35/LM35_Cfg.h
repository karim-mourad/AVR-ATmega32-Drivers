#ifndef LM35_CFG_H_
#define LM35_CFG_H_

#include "DIO.h"


typedef enum
{
	LM35_enuLDR0 = 0,
	LM35_enuLDRNumber
	
}LM35_tenuLDRs;

typedef enum
{
	LM35_enuNOK = 0,
	LM35_enuOK
	
}LM35_tenuErrorStatus;


typedef struct
{
	DIO_tenuPins LM35_Pin;
}LM35_strCfg_t;

extern LM35_strCfg_t LM35_strCfg[LM35_enuLDRNumber];





#endif /* LM35_CFG_H_ */