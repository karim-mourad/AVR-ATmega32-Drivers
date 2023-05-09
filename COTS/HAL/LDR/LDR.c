#include "ADC.h"
#include "LDR.h"

LDR_tenuErrorStatus LDR_ReadValue(u8 Cpy_ChannelNumber, u16* Add_Value)
{
	LDR_tenuErrorStatus Error_Status = LDR_enuOK;
	if(Cpy_ChannelNumber >= LDR_enuLDRNumber)
	{
		Error_Status = LDR_enuNOK;
	}
	ADC_Read_Value(Cpy_ChannelNumber,Add_Value);
	return Error_Status;
}