#ifndef EXT_INT_CFG_H_
#define EXT_INT_CFG_H_

#include "EXT_INT_Prv.h"




#define ENABLE	1
#define DISABLE 0

#define MODE_FALLING_EDGE	0b10
#define MODE_RISING_EDGE	0b11
#define MODE_LOGIC_CHANGE	0b01
#define MODE_LOW_LEVEL		0b00


#define INT2_MODE_FALLING_EDGE	0
#define INT2_MODE_RISING_EDGE	1

#define INT0_ED ENABLE
#define INT1_ED ENABLE
#define INT2_ED ENABLE

#define INT0_MODE	MODE_RISING_EDGE
#define INT1_MODE	MODE_RISING_EDGE
#define INT2_MODE	INT2_MODE_RISING_EDGE




#endif /* EXT_INT_CFG_H_ */