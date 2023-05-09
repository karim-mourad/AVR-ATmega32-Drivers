#include "Bit_math.h"
#include "Std_Types.h"
#include "delay.h"

#include "G_INT.h"
#include "EXT_INT.h"
#include "EXT_INT_Cfg.h"
#include "EXT_INT_Prv.h"


EXT_INT_enuErrorStatus EXT_INT_init(void)
{
	GIE_DIS();
	u8 loc_temp;
	#if INT0_ED == ENABLE
		loc_temp = MCUCR;
		loc_temp &= ~(INT0_CLR);
		loc_temp |= INT0_MODE;
		MCUCR = loc_temp;
		SET_BIT(GICR,6);
	#else
	CLR_BIT(GICR,6);
	#endif
	
	#if INT1_ED == ENABLE
		loc_temp = MCUCR;
		loc_temp &= ~(INT1_CLR);
		loc_temp |= (INT1_MODE<<2);
		MCUCR = loc_temp;
		SET_BIT(GICR,7);
	#else
	CLR_BIT(GICR,7);
	#endif
	
	#if INT2_ED == ENABLE
		#if INT2_MODE == INT2_MODE_RISING_EDGE
		SET_BIT(MCUCSR,6);
		#else
		CLR_BIT(MCUCSR,6);
		#endif
	SET_BIT(GICR,5);
	#else
	CLR_BIT(GICR,5);
	#endif
	
	
	GIE_INIT();
	return EXT_INT_enuNOK; 
}


