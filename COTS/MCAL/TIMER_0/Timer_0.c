#include "Timer_0.h"

u32 Max_count = 0;
TMR0cbf_t CallBackPtr = NULL;

void TMR0_vidInitPreCompile(void)
{
	u8 loc_buffer1 = TCCR0; //MODE
	u8 loc_buffer2 = TCCR0; //COMPARE_OUT_MODE
	u8 loc_buffer3 = TCCR0; //PRESCALER
	loc_buffer1 &= MODE_CLEAR_MASK;
	loc_buffer2 &= OUTPUT_COMPARE_CLEAR_MASK;
	loc_buffer3 &= PRESCALER_CLEAR_MASK;
	#if MODE == Normal
	loc_buffer1 |= Normal;
	#elif MODE == PWM_PHASE_CORRECT
	loc_buffer1 |= PWM_PHASE_CORRECT;
	#elif MODE == CTC
	loc_buffer1 |= CTC;
	#elif MODE == FAST_PWM
	loc_buffer1 |= FAST_PWM;	
	#endif
	
	
	#if COMPARE_OUT_MODE == OC0_DISCONNECTED
	loc_buffer2 |= OC0_DISCONNECTED;
	#elif COMPARE_OUT_MODE == OC0_TOGGLE
	loc_buffer2 |= OC0_TOGGLE;
	#elif COMPARE_OUT_MODE == OC0_CLEAR
	loc_buffer2 |= OC0_CLEAR;
	#elif COMPARE_OUT_MODE == OC0_SET
	loc_buffer2 |= OC0_SET;
	#elif COMPARE_OUT_MODE == OC0_DISCONNECTED
	loc_buffer2 |= OC0_DISCONNECTED;
	#elif COMPARE_OUT_MODE == OC0_CLEAR_ON_COMPARE
	loc_buffer2 |= OC0_CLEAR_ON_COMPARE;
	#elif COMPARE_OUT_MODE == OC0_SET_ON_COMPARE
	loc_buffer2 |= OC0_SET_ON_COMPARE;
	#elif COMPARE_OUT_MODE == OC0_CLEAR_UP_COUNT_SET_DOWN_COUNT
	loc_buffer2 |= OC0_CLEAR_UP_COUNT_SET_DOWN_COUNT;
	#elif COMPARE_OUT_MODE == OC0_SET_UP_COUNT_CLEAR_DOWN_COUNT
	loc_buffer2 |= OC0_SET_UP_COUNT_CLEAR_DOWN_COUNT;
	#endif
	
	#if PRESCALER == NO_CLK_SOURCE
	loc_buffer3 |= NO_CLK_SOURCE;
	#elif PRESCALER == NO_PRESACLING
	loc_buffer3 |= NO_PRESACLING;
	#elif PRESCALER == DIV_8
	loc_buffer3 |= DIV_8;
	#elif PRESCALER == DIV_64
	loc_buffer3 |= DIV_64;
	#elif PRESCALER == DIV_256
	loc_buffer3 |= DIV_256;
	#elif PRESCALER == DIV_1024
	loc_buffer3 |= DIV_1024;
	#elif PRESCALER == EXT_SRC_FALLING_EDGE
	loc_buffer3 |= EXT_SRC_FALLING_EDGE;
	#elif PRESCALER == EXT_SRC_RISING_EDGE
	loc_buffer3 |= EXT_SRC_RISING_EDGE;
	#endif
	
	#if INTERRUPT_OVERFLOW == Enable
	SET_BIT(TIMSK,0);
	#elif INTERRUPT_OVERFLOW == Disable
	CLR_BIT(TIMSK,0);
	#endif
	
	#if INTERRUPT_COMPARE_MATCH == Enable
	SET_BIT(TIMSK,1);
	#elif INTERRUPT_COMPARE_MATCH == Disable
	CLR_BIT(TIMSK,1);
	#endif
	
	TCCR0 |= loc_buffer1;
	TCCR0 |= loc_buffer2;
	TCCR0 |= loc_buffer3;
	
}

 
 
 TIM0_tenuErrorStatus TMR0_enuSetTickTimems(u16 Copy_u16Required_Time, u16* Copy_pu16Max_Count, u16* Copy_pu16Pre_Load)
 {
	 TIM0_tenuErrorStatus loc_Error_Status = TIM0_enuOK;
	 	 f64 Loc_Tick_Time = 0;
	 	 f64 Loc_OV_Time = 0;
	 	 f64 Loc_No_of_OV = 0;
	 	u8 Loc_PreLoad_value = 0;
	 	 f64 Loc_Decimal_Part = 0;
		u16 Loc_prescaler = 0;
		 f64 loc_buff_1;
		 f64 loc_buff_2;
		 f64 loc_buff_3;
		 f64 loc_buff_4;
		switch(PRESCALER)
		{
			case NO_PRESACLING:
				Loc_prescaler=1;
				break;
			
			case DIV_8:
				Loc_prescaler=8;
				break;
			
			case DIV_64:
				Loc_prescaler=64;
				break;
				
			case DIV_256:
				Loc_prescaler=256;
				break;
				
			case DIV_1024:
				Loc_prescaler=1024;
				break;
				
			default:
				Loc_prescaler = 1;
				break;
		}
		if (MODE == Normal)
		{
			Loc_Tick_Time = (f64)(1/(SYSTEM_FREQUENCY/Loc_prescaler));
			Loc_OV_Time = (f64)(Loc_Tick_Time*OVERFLOW);
			loc_buff_1 = (f64)(Copy_u16Required_Time)/ms;
			loc_buff_2 = (f64)(loc_buff_1 * AMP);
			loc_buff_3 = (f64)(loc_buff_2/Loc_OV_Time);
			//Loc_No_of_OV = (((f64)Copy_u16Required_Time/ms)*AMP)/Loc_OV_Time;
			//Loc_No_of_OV = 1953.125;
			Max_count = ceil(loc_buff_3);
			*Copy_pu16Max_Count = Max_count;
			Loc_Decimal_Part = loc_buff_3 - ((u64)loc_buff_3);
			Loc_PreLoad_value = OVERFLOW*(1 - Loc_Decimal_Part);
			*Copy_pu16Pre_Load = Loc_PreLoad_value;
			TCNT0 = Loc_PreLoad_value;
			//TCNT0 = 255;
			
		}
		
		else if (MODE == CTC)
		{
			OCR0 = COMPARE_MATCH_VALUE;
			Loc_Tick_Time = (f64)(1/(SYSTEM_FREQUENCY/Loc_prescaler));
			Loc_OV_Time = (f64)(Loc_Tick_Time*COMPARE_MATCH_VALUE);
			loc_buff_1 = (f64)(Copy_u16Required_Time)/ms;
			loc_buff_2 = (f64)(loc_buff_1 * AMP);
			loc_buff_3 = (f64)(loc_buff_2/Loc_OV_Time);
			Max_count = ceil(loc_buff_3);
			*Copy_pu16Max_Count = Max_count;
			Loc_Decimal_Part = loc_buff_3 - ((u64)loc_buff_3);
			Loc_PreLoad_value =  COMPARE_MATCH_VALUE*(1 - Loc_Decimal_Part);
			*Copy_pu16Pre_Load = Loc_PreLoad_value;
			TCNT0 = Loc_PreLoad_value;
			//Max_count = Copy_u16Count;
		}
	 
	 
	 return loc_Error_Status;
	 
	 
 }
 
 
 TIM0_tenuErrorStatus TMR0_enuPWM_DutyCycle(u16 Copy_u16Required_Duty_Cycle)
 {
	 TIM0_tenuErrorStatus loc_Error_Status = TIM0_enuOK;
	 u8 Loc_comp_Time = 0;
	 volatile u32 Loc_buff_1 = 0;
	 
	 if(MODE == FAST_PWM)
	 {
		 if(COMPARE_OUT_MODE == OC0_SET_ON_COMPARE)
		 {
			 Loc_buff_1 = (Copy_u16Required_Duty_Cycle * OVERFLOW)/100;
			 Loc_comp_Time = OVERFLOW - Loc_buff_1;
			 OCR0 = Loc_comp_Time;
			 
		 }
		 
		 else if(COMPARE_OUT_MODE == OC0_CLEAR_ON_COMPARE)
		 {
			 Loc_buff_1 = (Copy_u16Required_Duty_Cycle * OVERFLOW)/100;
			 Loc_comp_Time = Loc_buff_1;
			 OCR0 = Loc_comp_Time;
		 }
		 
	 }
	 
	 else if (MODE == PWM_PHASE_CORRECT)
	 {
		 if (COMPARE_OUT_MODE == OC0_CLEAR_UP_COUNT_SET_DOWN_COUNT)
		 {
			 Loc_buff_1 = (Copy_u16Required_Duty_Cycle * OVERFLOW)/100;
			 Loc_comp_Time = Loc_buff_1;
			 OCR0 = Loc_comp_Time;
		 }
		 
		 else if(COMPARE_OUT_MODE == OC0_SET_UP_COUNT_CLEAR_DOWN_COUNT)
		 {
			 Loc_buff_1 = (Copy_u16Required_Duty_Cycle * OVERFLOW)/100;
			 Loc_comp_Time = OVERFLOW - Loc_buff_1;
			 OCR0 = Loc_comp_Time;
		 }
		 
	 }
	 return loc_Error_Status;
 }
 
 
 
 
 TIM0_tenuErrorStatus TMR0_enuStart(void)
 {
	TIM0_tenuErrorStatus loc_Error_Status = TIM0_enuOK;
	
	TCCR0 |= PRESCALER;
	
	
	return loc_Error_Status;
 }
 
 
 
 TIM0_tenuErrorStatus TMR0_enuStop(void)
 {
	 TIM0_tenuErrorStatus loc_Error_Status = TIM0_enuOK;
	 
	 TCCR0 &= TIMER0_STOP;
	 
	 
	 return loc_Error_Status;
 }
 
 
 
 
 
 TIM0_tenuErrorStatus TMR0_enuRegisterCallback(TMR0cbf_t Cpy_TMR0Cbf)  
 {
	  TIM0_tenuErrorStatus loc_Error_Status = TIM0_enuOK;
	  if(Cpy_TMR0Cbf == NULL)
	  {
		  loc_Error_Status = TIM0_enuNullPtrFunc;
	  }
	  
	  else
	  {
		  CallBackPtr = Cpy_TMR0Cbf;
	  }
	 return loc_Error_Status;
 }
 
 
 
 void __vector_10(void)  __attribute__((signal));  //TIMER0 COMP Interrupt
 void __vector_10(void)
 {
	 if(CallBackPtr != NULL)
	 {
		 CallBackPtr();
	 }
	 else
	 {
		 /*DO NOTHING*/
	 }
	 

 }
 
 
  void __vector_11(void)  __attribute__((signal));  //TIMER0 OVF Interrupt
  void __vector_11(void)
  {
	  if(CallBackPtr != NULL)
	  {
		  CallBackPtr();
	  }
	  else
	  {
		  /*DO NOTHING*/
	  }
	  

  }