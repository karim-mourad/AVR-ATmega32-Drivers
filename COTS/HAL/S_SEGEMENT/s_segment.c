#include "../../LIB/Std_Types.h"
#include "../../MCAL/DIO/DIO.h"
#include "s_segment.h"
#include "s_segment_Cfg.h"



SSEGMENT_enuErrorStatus SsegmentDisplayValue(DIO_tenuPorts Cpy_PortNumber, u8 Cpy_SSegmentValue)
{
		SSEGMENT_enuErrorStatus currenterrorstatus = SSEGMENT_enuOK;
		if(Cpy_PortNumber>DIO_enuPORTD)
		{
			currenterrorstatus = SSEGMENT_enuNOK;
		}
		DIO_enuSetPortValue (Cpy_PortNumber,Ssegemnt_arr[Cpy_SSegmentValue]);
		
		
		return currenterrorstatus;
}