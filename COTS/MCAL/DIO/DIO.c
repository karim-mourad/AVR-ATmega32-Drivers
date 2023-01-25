#include "Std_Types.h"
#include "Bit_math.h"
#include "DIO.h"
#include "DIO_Prv.h"
#include "DIO_Cfg.h" 



#define DIO_PORTA 0
#define DIO_PORTB 1
#define DIO_PORTC 2
#define DIO_PORTD 3

const DIO_strPinCfg_t DIO_strPinCfg[32]=
{
	/*PORTA*//*Pin Direction*/  /*Pull up Pull Down*/
	
	/*PIN0*/{DIO_DIR_INPUT,  DIO_INPUT_PULL_UP},
	/*PIN1*/{DIO_DIR_INPUT,  DIO_INPUT_PULL_UP},
	/*PIN2*/{DIO_DIR_OUTPUT,  DIO_INPUT_PULL_DOWN},
	/*PIN3*/{DIO_DIR_OUTPUT,  DIO_INPUT_PULL_DOWN},
	/*PIN4*/{DIO_DIR_OUTPUT,  DIO_INPUT_PULL_DOWN},
	/*PIN5*/{DIO_DIR_OUTPUT,  DIO_INPUT_PULL_DOWN},
	/*PIN6*/{DIO_DIR_OUTPUT,  DIO_INPUT_PULL_DOWN},
	/*PIN7*/{DIO_DIR_OUTPUT,  DIO_INPUT_PULL_DOWN},
	
	/*PORTB*//*Pin Direction*/  /*Pull up Pull Down*/
	
	/*PIN8*/{DIO_DIR_OUTPUT,  DIO_INPUT_PULL_DOWN},
	/*PIN9*/{DIO_DIR_OUTPUT,  DIO_INPUT_PULL_DOWN},
	/*PIN10*/{DIO_DIR_OUTPUT,  DIO_INPUT_PULL_DOWN},
	/*PIN11*/{DIO_DIR_OUTPUT,  DIO_INPUT_PULL_DOWN},
	/*PIN12*/{DIO_DIR_OUTPUT,  DIO_INPUT_PULL_DOWN},
	/*PIN13*/{DIO_DIR_OUTPUT,  DIO_INPUT_PULL_DOWN},
	/*PIN14*/{DIO_DIR_OUTPUT,  DIO_INPUT_PULL_DOWN},
	/*PIN15*/{DIO_DIR_OUTPUT,  DIO_INPUT_PULL_DOWN},
	
	/*PORTC*//*Pin Direction*/  /*Pull up Pull Down*/
	
	/*PIN16*/{DIO_DIR_OUTPUT,  DIO_INPUT_PULL_DOWN},
	/*PIN17*/{DIO_DIR_OUTPUT,  DIO_INPUT_PULL_DOWN},
	/*PIN18*/{DIO_DIR_OUTPUT,  DIO_INPUT_PULL_DOWN},
	/*PIN19*/{DIO_DIR_OUTPUT,  DIO_INPUT_PULL_DOWN},
	/*PIN20*/{DIO_DIR_OUTPUT,  DIO_INPUT_PULL_DOWN},
	/*PIN21*/{DIO_DIR_OUTPUT,  DIO_INPUT_PULL_DOWN},
	/*PIN22*/{DIO_DIR_OUTPUT,  DIO_INPUT_PULL_DOWN},
	/*PIN23*/{DIO_DIR_OUTPUT,  DIO_INPUT_PULL_DOWN},
	
	/*PORTD*//*Pin Direction*/  /*Pull up Pull Down*/
	
	/*PIN24*/{DIO_DIR_OUTPUT,  DIO_INPUT_PULL_DOWN},
	/*PIN25*/{DIO_DIR_OUTPUT,  DIO_INPUT_PULL_DOWN},
	/*PIN26*/{DIO_DIR_OUTPUT,  DIO_INPUT_PULL_DOWN},
	/*PIN27*/{DIO_DIR_OUTPUT,  DIO_INPUT_PULL_DOWN},
	/*PIN28*/{DIO_DIR_OUTPUT,  DIO_INPUT_PULL_DOWN},
	/*PIN29*/{DIO_DIR_OUTPUT,  DIO_INPUT_PULL_DOWN},
	/*PIN30*/{DIO_DIR_OUTPUT,  DIO_INPUT_PULL_DOWN},
	/*PIN31*/{DIO_DIR_OUTPUT,  DIO_INPUT_PULL_DOWN}
};

DIO_tenuErrorStatus DIO_enuInit(void)
{
	u8 i;
	u8 Loc_u8PortNumber = 0;
	u8 Loc_u8PinNumber = 0;
	for(i=0;i<DIO_enuNumberOfPins;i++)
	{
		Loc_u8PortNumber = i/8;
		Loc_u8PinNumber = i%8;
		switch(Loc_u8PortNumber)
		{
			case(DIO_PORTA):
				if(DIO_strPinCfg[i].DIO_PinDirection == DIO_DIR_OUTPUT)
				{
					SET_BIT(DDRA,Loc_u8PinNumber);
				}
				else
				{
					CLR_BIT(DDRA,Loc_u8PinNumber);
					if(DIO_strPinCfg[i].DIO_InputStatus == DIO_INPUT_PULL_UP)
					{
						SET_BIT(PORTA,Loc_u8PinNumber);
					}
				}
				break;
			case(DIO_PORTB):
				if(DIO_strPinCfg[i].DIO_PinDirection == DIO_DIR_OUTPUT)
				{
					SET_BIT(DDRB,Loc_u8PinNumber);
				}
				else
				{
					CLR_BIT(DDRA,Loc_u8PinNumber);
					if(DIO_strPinCfg[i].DIO_InputStatus == DIO_INPUT_PULL_UP)
					{
						SET_BIT(PORTB,Loc_u8PinNumber);
					}
				}
				break;
				
			case(DIO_PORTC):
				if(DIO_strPinCfg[i].DIO_PinDirection == DIO_DIR_OUTPUT)
				{
					SET_BIT(DDRC,Loc_u8PinNumber);
				}
				else
				{
					CLR_BIT(DDRA,Loc_u8PinNumber);
					if(DIO_strPinCfg[i].DIO_InputStatus == DIO_INPUT_PULL_UP)
					{
						SET_BIT(PORTC,Loc_u8PinNumber);
					}
				}
				break;
				
			case(DIO_PORTD):
				if(DIO_strPinCfg[i].DIO_PinDirection == DIO_DIR_OUTPUT)
				{
					SET_BIT(DDRD,Loc_u8PinNumber);
				}
				else
				{
					CLR_BIT(DDRA,Loc_u8PinNumber);
					if(DIO_strPinCfg[i].DIO_InputStatus == DIO_INPUT_PULL_UP)
					{
						SET_BIT(PORTD,Loc_u8PinNumber);
					}
				}
				break;
				
		}
	}
	
	return DIO_enuOK;
}


DIO_tenuErrorStatus DIO_enuSetPin(DIO_tenuPins Cpy_u8PinNumber)
{
	DIO_tenuErrorStatus currentErrorStatus = DIO_enuOK;
	u8 loc_u8PortNo = Cpy_u8PinNumber/8;
	Cpy_u8PinNumber = Cpy_u8PinNumber % 8;
	if(loc_u8PortNo>PORT_D || Cpy_u8PinNumber>PIN_7)
	{
		currentErrorStatus = DIO_enuNOK;
	}
	else
	{
		switch(loc_u8PortNo)
		{
			case PORT_A:
				SET_BIT(PORTA,Cpy_u8PinNumber);
				break;
			case PORT_B:
				SET_BIT(PORTB,Cpy_u8PinNumber);
				break;
			case PORT_C:
				SET_BIT(PORTC,Cpy_u8PinNumber);
				break;
			case PORT_D:
				SET_BIT(PORTD,Cpy_u8PinNumber);
				break;
			
		}
		
	}

	
	return currentErrorStatus;
	
	
	
}




DIO_tenuErrorStatus DIO_enuClearPin(DIO_tenuPins Cpy_u8PinNumber)
{
	DIO_tenuErrorStatus currentErrorStatus = DIO_enuOK;
	u8 loc_u8PortNo = Cpy_u8PinNumber/8;
	Cpy_u8PinNumber = Cpy_u8PinNumber % 8;
	if(loc_u8PortNo>PORT_D || Cpy_u8PinNumber>PIN_7)
	{
		currentErrorStatus = DIO_enuNOK;
	}
	else
	{
		switch(loc_u8PortNo)
		{
			case DIO_PORTA:
				CLR_BIT(PORTA,Cpy_u8PinNumber);
				break;
			case DIO_PORTB:
				CLR_BIT(PORTB,Cpy_u8PinNumber);
				break;
			case DIO_PORTC:
				CLR_BIT(PORTC,Cpy_u8PinNumber);
				break;
			case DIO_PORTD:
				CLR_BIT(PORTD,Cpy_u8PinNumber);
				break;
			
		}
		
	}

	
	return currentErrorStatus;
	
	
	
}
		
		
		
DIO_tenuErrorStatus DIO_enuGetPin(DIO_tenuPins Cpy_u8PinNumber, u8 *Add_Pu8pinValue)
{
	DIO_tenuErrorStatus currentErrorStatus = DIO_enuOK;
	u8 loc_u8PortNo = Cpy_u8PinNumber/8;
	u8 Loc_u8PinNumber = Cpy_u8PinNumber % 8;
	if(loc_u8PortNo>PORT_D || Cpy_u8PinNumber>PIN_7)
	{
		currentErrorStatus = DIO_enuNOK;
	}
	else
	{
		switch(loc_u8PortNo)
		{
			case PORT_A:
				*Add_Pu8pinValue=GET_BIT(PINA,Loc_u8PinNumber);
				break;                       
			case PORT_B:                     
				*Add_Pu8pinValue=GET_BIT(PINB,Loc_u8PinNumber);
				break;                       
			case PORT_C:                     
				*Add_Pu8pinValue=GET_BIT(PINC,Loc_u8PinNumber);
				break;                       
			case PORT_D:                     
				*Add_Pu8pinValue=GET_BIT(PIND,Loc_u8PinNumber);
				break;
			
		}
		
	}

	
	return currentErrorStatus;
	
	
	
}


DIO_tenuErrorStatus DIO_enuSetPort(DIO_tenuPorts Cpy_u8PortNumber)
{
	DIO_tenuErrorStatus currentErrorStatus = DIO_enuOK;
	if(Cpy_u8PortNumber>DIO_enuPORTD)
	{
		currentErrorStatus = DIO_enuNOK;
	}
	else
	{
		switch(Cpy_u8PortNumber)
		{
			case DIO_enuPORTA:
				SET_REG(PORTA);
				break;                       
			case DIO_enuPORTB:                     
				SET_REG(PORTB);
				break;                       
			case DIO_enuPORTC:                     
				SET_REG(PORTC);
				break;                       
			case DIO_enuPORTD:                     
				SET_REG(PORTD);
				break;
			
		}
		
	}
	
	return currentErrorStatus;
	
}



DIO_tenuErrorStatus DIO_enuClearPort(DIO_tenuPorts Cpy_u8PortNumber)
{
	DIO_tenuErrorStatus currentErrorStatus = DIO_enuOK;
	if(Cpy_u8PortNumber>DIO_enuPORTD)
	{
		currentErrorStatus = DIO_enuNOK;
	}
	else
	{
		switch(Cpy_u8PortNumber)
		{
			case DIO_enuPORTA:
				CLR_REG(PORTA);
				break;                       
			case DIO_enuPORTB:                     
				CLR_REG(PORTB);
				break;                       
			case DIO_enuPORTC:                     
				CLR_REG(PORTC);
				break;                       
			case DIO_enuPORTD:                     
				CLR_REG(PORTD);
				break;
			
		}
		
	}
	
	return currentErrorStatus;
	
}


DIO_tenuErrorStatus DIO_enuSetPortValue (DIO_tenuPorts Cpy_u8PortNumber, u8 Cpy_u8PortValue)
{
	DIO_tenuErrorStatus currentErrorStatus = DIO_enuOK;
	if(Cpy_u8PortNumber>DIO_enuPORTD)
	{
		currentErrorStatus = DIO_enuNOK;
	}
	else
	{
		switch(Cpy_u8PortNumber)
		{
			case DIO_enuPORTA:
			PORTA = Cpy_u8PortValue;
			break;
			case DIO_enuPORTB:
			PORTB = Cpy_u8PortValue;
			break;
			case DIO_enuPORTC:
			PORTC = Cpy_u8PortValue;
			break;
			case DIO_enuPORTD:
			PORTD = Cpy_u8PortValue;
			break;
			
		}
	}
	
	return currentErrorStatus;
	
}