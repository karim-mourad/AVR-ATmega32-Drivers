#include "Bit_math.h"
#include "G_INT.h"
#include "G_INT_Prv.h"



G_INT_enuErrorStatus GIE_INIT(void)
{
	
	SET_BIT(SREG,GIE);
	return G_INT_enuOK;
}

G_INT_enuErrorStatus GIE_DIS(void)
{
	
	CLR_BIT(SREG,GIE);
	return G_INT_enuOK;
}