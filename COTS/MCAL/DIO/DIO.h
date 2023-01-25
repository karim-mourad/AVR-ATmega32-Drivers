/**************************************/
/*DIO Interface File*/
/**************************************/


#ifndef DIO_H
#define DIO_H

#include "Std_Types.h"
typedef enum
{
	DIO_enuOK = 0,
	DIO_enuNOK,
	DIO_enuNullPtr
}DIO_tenuErrorStatus;


typedef enum
{
	DIO_enuPORTA=0,
	DIO_enuPORTB,
	DIO_enuPORTC,
	DIO_enuPORTD	
	
}DIO_tenuPorts;



typedef enum
{
	DIO_enuPin0 = 0,
	DIO_enuPin1,
	DIO_enuPin2,
	DIO_enuPin3,
	DIO_enuPin4,
	DIO_enuPin5,
	DIO_enuPin6,
	DIO_enuPin7,
	DIO_enuPin8,
	DIO_enuPin9,
	DIO_enuPin10,
	DIO_enuPin11,
	DIO_enuPin12,
	DIO_enuPin13,
	DIO_enuPin14,
	DIO_enuPin15,
	DIO_enuPin16,
	DIO_enuPin17,
	DIO_enuPin18,
	DIO_enuPin19,
	DIO_enuPin20,
	DIO_enuPin21,
	DIO_enuPin22,
	DIO_enuPin23,
	DIO_enuPin24,
	DIO_enuPin25,
	DIO_enuPin26,
	DIO_enuPin27,
	DIO_enuPin28,
	DIO_enuPin29,
	DIO_enuPin30,
	DIO_enuPin31,
	DIO_enuNumberOfPins
}DIO_tenuPins;

typedef enum
{
	DIO_enuLow = 0,
	DIO_enuHigh
}DIO_tenuPinValue;

/**************************************/
/*DIO Init Function
  Input: Void
  Output: DIO_tenuErrorStatus to report error*/
/**************************************/
DIO_tenuErrorStatus DIO_enuInit(void);



/**************************************/
/*DIO set pin Function
  Input: Pin number (Range from 0 - 31)
  Output: DIO_tenuErrorStatus to report error*/
/**************************************/
DIO_tenuErrorStatus DIO_enuSetPin(DIO_tenuPins Cpy_u8PinNumber);



/**************************************/
/*DIO clear pin Function
  Input: Pin number (Range from 0 - 31)
  Output: DIO_tenuErrorStatus to report error*/
/**************************************/
DIO_tenuErrorStatus DIO_enuClearPin(DIO_tenuPins Cpy_u8PinNumber);


/**************************************/
/*DIO get pin Function
  Input: Pin number (Range from 0 - 31)
  Output: DIO_tenuErrorStatus to report error*/
/**************************************/
DIO_tenuErrorStatus DIO_enuGetPin(DIO_tenuPins Cpy_u8PinNumber,u8* Add_pu8PinValue);


/**************************************/
/*DIO set port Function
  Input: Port number (Range from 0 - 4)
  Output: DIO_tenuErrorStatus to report error*/
/**************************************/
DIO_tenuErrorStatus DIO_enuSetPort(DIO_tenuPorts Cpy_u8PortNumber);


/**************************************/
/*DIO clear port Function
  Input: Port number (Range from 0 - 4)
  Output: DIO_tenuErrorStatus to report error*/
/**************************************/
DIO_tenuErrorStatus DIO_enuClearPort(DIO_tenuPorts Cpy_u8PortNumber);


/**************************************/
/*DIO set port with specific value Function
  Input: Port number (Range from 0 - 4), Port value(Range from  0 -255)
  Output: DIO_tenuErrorStatus to report error*/
/**************************************/
DIO_tenuErrorStatus DIO_enuSetPortValue (DIO_tenuPorts Cpy_u8PortNumber, u8 Cpy_u8PortValue);


#endif /*DIO_H*/