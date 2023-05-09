#ifndef LM35_H_
#define LM35_H_


#include "Std_Types.h"
#include "Bit_math.h"
#include "LM35_Cfg.h"

LM35_tenuErrorStatus LM35_ReadValue(u8 Cpy_ChannelNumber, u16* Add_Value);


#endif /* LM35_H_ */