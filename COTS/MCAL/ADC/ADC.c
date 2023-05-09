#include "Std_Types.h"
#include "Bit_math.h"
#include "ADC.h"
#include "ADC_Cfg.h"
#include "ADC_Prv.h"
#include "G_INT.h"

void(*ptrFun)(void) = NULL;

void setCallback(void(*CBF)(void))
{
	if(CBF != NULL)
	{
		ptrFun = CBF;
	}
	
	
}

ADC_enuErrorStatus ADC_Init(void)
{
	ADC_enuErrorStatus loc_Error_Status = ADC_enuOK;
	
	#if (ADC_ED == Enable)
	SET_BIT(ADCSRA,7);
	u8 loc_temp = ADMUX;
	loc_temp &= V_ref_CLR_MASK;
	loc_temp |= V_ref;
	ADMUX = loc_temp;
	
		#if (ADC_Interrupt == Enable)
		GIE_INIT();
		SET_BIT(ADCSRA,3);
		#else
		CLR_BIT(ADCSRA,3);
		#endif
	
	
	loc_temp = ADMUX;
	CLR_BIT(loc_temp,5);
	loc_temp |= Data_Representation;
	ADMUX = loc_temp;
	
		#if ADC_Auto_Trigger == Enable
		loc_temp = ADCSRA;
		SET_BIT(loc_temp,5);
		ADCSRA = loc_temp;
		loc_temp = SFIOR;
		loc_temp &= ADC_TRIGGER_CLR_MASK;
		loc_temp |= ADC_Auto_trigger_Source;
		SFIOR = loc_temp;
		#else
		loc_temp = ADCSRA;
		CLR_BIT(loc_temp,5);
		ADCSRA = loc_temp;
		#endif
	
	loc_temp = ADCSRA;
	loc_temp &= Prescaler_CLR_MASK;
	loc_temp |= Prescaler_Value;
	ADCSRA =  loc_temp;
	#else
	CLR_BIT(ADCSRA,7);
	#endif

	
	return loc_Error_Status;
}



ADC_enuErrorStatus ADC_Read_Value(ADC_tenuChannelNumber Cpy_ChannelNumber,u16 *Add_ADC_Value)
{
	ADC_enuErrorStatus loc_Error_Status = ADC_enuOK;
	u8 loc_Buffer;
	loc_Buffer = ADMUX ;
	loc_Buffer &= MUX_CLR_MASK ;
	loc_Buffer |= Cpy_ChannelNumber ;
	ADMUX = loc_Buffer ;
	u16 loc_temp;
	u16 loc_counter = 2000;
	
	SET_BIT(ADCSRA,6);
	while((GET_BIT(ADCSRA,4) == 0) && loc_counter>0)
	{
		loc_counter--;
	}
		if (Data_Representation == Left_Adjusted)
		{
			loc_temp = (ADCL>>6)|(ADCH<<2);
		}
			
		else if (Data_Representation == Right_Adjusted)
		{
			//loc_temp = ADCL|(ADCH<<8);
			loc_temp = ADC_VAL;
		}
	SET_BIT(ADCSRA,4);
	*Add_ADC_Value = loc_temp;
	
	
	return loc_Error_Status;
	
}


MY_ISR(16)
{
	ptrFun();
}