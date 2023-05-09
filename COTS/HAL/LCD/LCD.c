#include "Std_Types.h"
#include "Bit_math.h"
#include "delay.h"
#include "DIO.h"
#include "LCD.h"
#include "LCD_Cfg.h"
#include "LCD_Prv.h"

static LCD_tenuErrorStatus WriteCommand(u8 command);


LCD_tenuErrorStatus LCD_Init()
{
	LCD_tenuErrorStatus Error_Status=LCD_enuOK;
	/*CLR_BIT(CONTROL_PORT,RS);
	CLR_BIT(CONTROL_PORT,RW);
	DATA_PORT = (0b000111011);
	*/
	WriteCommand(0b000111011); //Function Set: N=1, number of lines equal 2. F=0, 5*8 Font
	WriteCommand(0b00001100); //Display ON/OFF: D= 1, display is on. C=0, Cursor is OFF. B=0, Blinking is OFF.
	WriteCommand(0b00000001); //Display Clear
	return Error_Status;
	
}

LCD_tenuErrorStatus LCD_Clear()
{
	LCD_tenuErrorStatus Error_Status=LCD_enuOK;
	WriteCommand(0b00000001); //Clear display
	WriteCommand(0b00000010); //Return Home
	return Error_Status;
}



LCD_tenuErrorStatus LCD_writeData(u8 character)
{
	LCD_tenuErrorStatus Error_Status=LCD_enuOK;
	SET_BIT(CONTROL_PORT,RS);
	CLR_BIT(CONTROL_PORT,RW);
	DATA_PORT = character;
	SET_BIT(CONTROL_PORT,E);
	Delay_MS(2);
	CLR_BIT(CONTROL_PORT,E);
	return Error_Status;
}

LCD_tenuErrorStatus LCD_WriteString(char* string)
{
	LCD_tenuErrorStatus Error_Status=LCD_enuOK;
	u8 i;
	for(i=0;string[i]!='\0';i++)
	{
		LCD_writeData(string[i]);
	}
	
	return Error_Status;
	
}


LCD_tenuErrorStatus LCD_WriteNum(u16 num)
{
	LCD_tenuErrorStatus Error_Status=LCD_enuOK;
	char arr[5];
	itoa(num,arr,10);
	LCD_WriteString(arr);
	return Error_Status;
}

LCD_tenuErrorStatus LCD_GoToXY(u8 x, u8 y)
{
	LCD_tenuErrorStatus Error_Status=LCD_enuOK;
	u8 loc_location=0;
	if(x == 0)
	{
		loc_location = y;
	}
	else if(x == 1)
	{
		loc_location = 64+y;
	}
	WriteCommand(128+loc_location);
	
	return Error_Status;
}

LCD_tenuErrorStatus LCD_DisplaySpecialChar(u8* Pattern, u8 Block_Num, u8 x, u8 y)
{
	LCD_tenuErrorStatus Error_Status=LCD_enuOK;
	u8 loc_address = Block_Num*8;
	WriteCommand(loc_address+64);
	u8 i=0;
	for(i=0;i<8;i++)
	{
		LCD_writeData(Pattern[i]);
		
	}
	LCD_GoToXY(x,y);
	LCD_writeData(Block_Num);
	
	return Error_Status;
};



static LCD_tenuErrorStatus WriteCommand(u8 command)
{
	LCD_tenuErrorStatus Error_Status=LCD_enuOK;
	CLR_BIT(CONTROL_PORT,RS);
	CLR_BIT(CONTROL_PORT,RW);
	DATA_PORT = command;
	SET_BIT(CONTROL_PORT,E);
	Delay_MS(2);
	CLR_BIT(CONTROL_PORT,E);
	return Error_Status;
}


