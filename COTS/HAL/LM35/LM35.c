#include "Std_Types.h"
#include "ADC.h"
#include "LM35.h"


LM35_tenuErrorStatus LM35_ReadValue(u8 Cpy_ChannelNumber, u16* Add_Value)
{
	LM35_tenuErrorStatus Error_Status = LM35_enuOK;
	u16 ADC_reading;
	if(Cpy_ChannelNumber >= LM35_enuLDRNumber)
	{
		Error_Status = LM35_enuNOK;
	}
	ADC_Read_Value(Cpy_ChannelNumber,&ADC_reading);
	*Add_Value = (5*ADC_reading*100)/1023;
	//*Add_Value = 15;
	return Error_Status;
}