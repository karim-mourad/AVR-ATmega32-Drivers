#include "keypad_Cfg.h"




DIO_tenuPins keypad_rows[KEYPAD_ROWS] = 
{	
	DIO_enuPin16,
	DIO_enuPin17,
	DIO_enuPin18,
	DIO_enuPin19
	
};





DIO_tenuPins keypad_col[KEYPAD_COLUMNS] =
{
	DIO_enuPin20,
	DIO_enuPin21,
	DIO_enuPin22
};


keypad_enuValues values[KEYPAD_ROWS][KEYPAD_COLUMNS] =
{
	[KEYPAD_ROW_0][KEYPAD_COLUMN_0] = Keypad_enuone,
	[KEYPAD_ROW_0][KEYPAD_COLUMN_1] = Keypad_enutwo,
	[KEYPAD_ROW_0][KEYPAD_COLUMN_2] = Keypad_enuthree,
	[KEYPAD_ROW_1][KEYPAD_COLUMN_0] = Keypad_enufour,
	[KEYPAD_ROW_1][KEYPAD_COLUMN_1] = Keypad_enufive,
	[KEYPAD_ROW_1][KEYPAD_COLUMN_2] = Keypad_enusix,
	[KEYPAD_ROW_2][KEYPAD_COLUMN_0] = Keypad_enuseven,
	[KEYPAD_ROW_2][KEYPAD_COLUMN_1] = Keypad_enueight,
	[KEYPAD_ROW_2][KEYPAD_COLUMN_2] = Keypad_enunine,
	[KEYPAD_ROW_3][KEYPAD_COLUMN_0] = Keypad_enuten,
	[KEYPAD_ROW_3][KEYPAD_COLUMN_1] = Keypad_enuzero,
	[KEYPAD_ROW_3][KEYPAD_COLUMN_2] = Keypad_enueleven
	
};