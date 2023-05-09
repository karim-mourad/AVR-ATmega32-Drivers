#ifndef LCD_H_
#define LCD_H_

#include "Std_Types.h"

typedef enum
{
	LCD_enuNOK = 0,
	LCD_enuOK
	
}LCD_tenuErrorStatus;


LCD_tenuErrorStatus LCD_Init();
LCD_tenuErrorStatus LCD_writeData(u8 character);
LCD_tenuErrorStatus LCD_GoToXY(u8 x, u8 y);
LCD_tenuErrorStatus LCD_DisplaySpecialChar(u8* Pattern, u8 Block_Num, u8 x, u8 y);
LCD_tenuErrorStatus LCD_WriteString(char * string);
LCD_tenuErrorStatus LCD_WriteNum(u16 num);
LCD_tenuErrorStatus LCD_Clear();




#endif /* LCD_H_ */