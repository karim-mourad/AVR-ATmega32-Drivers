#ifndef KEYPAD_CFG_H_
#define KEYPAD_CFG_H_

#include "DIO.h"

#define KEYPAD_ROW_0	0
#define KEYPAD_ROW_1	1	
#define KEYPAD_ROW_2	2	
#define KEYPAD_ROW_3	3

#define KEYPAD_COLUMN_0	0
#define KEYPAD_COLUMN_1	1
#define KEYPAD_COLUMN_2	2

#define KEYPAD_ROWS		4
#define KEYPAD_COLUMNS	3

typedef enum
{
	Keypad_enuzero =0,
	Keypad_enuone,
	Keypad_enutwo,
	Keypad_enuthree,
	Keypad_enufour,
	Keypad_enufive,
	Keypad_enusix,
	Keypad_enuseven,
	Keypad_enueight,
	Keypad_enunine,
	Keypad_enuten,
	Keypad_enueleven
}keypad_enuValues;

extern DIO_tenuPins keypad_rows[KEYPAD_ROWS];
extern DIO_tenuPins keypad_col[KEYPAD_COLUMNS];
extern keypad_enuValues values[KEYPAD_ROWS][KEYPAD_COLUMNS];




#endif /* KEYPAD_CFG_H_ */