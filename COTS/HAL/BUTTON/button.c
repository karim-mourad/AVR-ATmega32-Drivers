
#include "../../LIB/delay.h"
#include "../../LIB/Std_Types.h"
#include "button.h"


BUTTON_enuErrorStatus ButtonIsPressed(BUTTON_tenuBUTTONS Cpy_enuPinNNumber,u8* Add_Pu8pinValue)
{
	BUTTON_enuErrorStatus loc_currentErrorStatus = BUTTON_enuOK;
	u8 loc_check=0;
	u8 loc_iterator=0;
	
		if(Cpy_enuPinNNumber>BUTTON_enuNumberOfButtons)
		{
			loc_currentErrorStatus = BUTTON_enuNOK;
		}
		
		switch(Button_strCfg[Cpy_enuPinNNumber].BUTTON_MODE)
		{
			
			case BUTTON_enuPull_Up:
				
				for(loc_iterator=0;loc_iterator<5;loc_iterator++)
				{
					loc_currentErrorStatus = DIO_enuGetPin(Cpy_enuPinNNumber,Add_Pu8pinValue);
					Delay_MS(5);
					if(*Add_Pu8pinValue==0)
					{
						loc_check++;
					}
				}
				if (loc_check>=3)
				{
					*Add_Pu8pinValue=0;
				}
				else
				{
					*Add_Pu8pinValue=1;
					
				}
				break;
				
			case BUTTON_enuPull_Down:
				
				for(loc_iterator=0;loc_iterator<5;loc_iterator++)
				{
					loc_currentErrorStatus = DIO_enuGetPin(Cpy_enuPinNNumber,Add_Pu8pinValue);
					Delay_MS(5);
					if(*Add_Pu8pinValue==1)
					{
						loc_check++;
					}
				}
				if (loc_check>=3)
				{
					*Add_Pu8pinValue=1;
				}
				else
				{
					*Add_Pu8pinValue=0;
				}
				break;
			
		}
		return loc_currentErrorStatus;
	
}