/**************************************/
/*DIO Configuration File*/
/**************************************/


#ifndef DIO_CFG_H
#define DIO_CFG_H

#define DIO_DIR_INPUT 0
#define DIO_DIR_OUTPUT 1


#define DIO_INPUT_PULL_UP 0
#define DIO_INPUT_PULL_DOWN 1


	
#define PORT_A  0
#define PORT_B  1
#define PORT_C  2
#define PORT_D  3


#define PIN_0  0
#define PIN_1  1
#define PIN_2  2
#define PIN_3  3
#define PIN_4  4
#define PIN_5  5
#define PIN_6  6
#define PIN_7  7


typedef struct{
	
	u8 DIO_PinDirection;
	u8 DIO_InputStatus;
}DIO_strPinCfg_t;



#endif /*DIO_CFG_H*/