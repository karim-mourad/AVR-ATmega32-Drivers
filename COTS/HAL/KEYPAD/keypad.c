#include "DIO.h"
#include "Std_Types.h"
#include "Bit_math.h"
#include "keypad.h"
#include "keypad_Cfg.h"

keypad_enuErrorStatus keypad_get(u8* Add_Pu8pinValue)
{
	keypad_enuErrorStatus currenterrorstatus = keypad_enuOK;
	u8 loc_row = 0, loc_column = 0, loc_pinState;
	for(loc_row=0; loc_row<KEYPAD_ROWS; loc_row++)
	{
		DIO_enuClearPin(keypad_rows[loc_row]);
		for (loc_column= 0; loc_column < KEYPAD_COLUMNS; loc_column++)
		{
			
			DIO_enuGetPin(keypad_col[loc_column],&loc_pinState);
			if(loc_pinState == 0)
			{
				*Add_Pu8pinValue = values[loc_row][loc_column];
			}
			
		}
		DIO_enuSetPin(keypad_rows[loc_row]);
	}
	return currenterrorstatus;
}