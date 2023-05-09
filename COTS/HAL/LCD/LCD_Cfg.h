#ifndef LCD_CFG_H_
#define LCD_CFG_H_

#include "DIO_Prv.h"
#include "LCD_Prv.h"
/*
Choose which port the data pins are connected to
	OPTIONS:
	1-	PORTA
	2-	PORTB
	3-	PORTC
	4-	PORTD
*/
#define DATA_PORT PORTA


/*
Choose which pins are connected to the RS,RW & E pins of the LCDs


*/
#define CONTROL_PORT PORTC
#define RS 0
#define RW 1
#define E  2



#endif /* LCD_CFG_H_ */