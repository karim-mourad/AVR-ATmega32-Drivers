#ifndef KEYPAD_H_
#define KEYPAD_H_

typedef enum
{
	keypad_enuNOK = 0,
	keypad_enuOK	
	
}keypad_enuErrorStatus;


keypad_enuErrorStatus keypad_get(u8* Add_Pu8pinValue);




#endif /* KEYPAD_H_ */