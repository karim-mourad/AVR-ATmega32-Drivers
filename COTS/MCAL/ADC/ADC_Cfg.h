#ifndef ADC_CFG_H_
#define ADC_CFG_H_

/*
ADC Enable or Disable
Options:
1- Enable
2- Disable
*/
#define ADC_ED Enable

/*
ADC Enable or Disable Interrupt
Options:
1- Enable
2- Disable
*/
#define ADC_Interrupt_ED Enable


/*
ADC Enable or Disable Auto Trigger
Options:
1- Enable
2- Disable
*/
#define ADC_Auto_Trigger  Enable

#if ADC_Auto_Trigger == Enable
	#define ADC_Auto_trigger_Source	ADC_TRIGGER_FREE_RUNNING
#endif


/*
ADC choose which channel in single ended inputs
Options:
1- MUX_ADC0
2- MUX_ADC1
3- MUX_ADC2
4- MUX_ADC3
5- MUX_ADC4
6- MUX_ADC5
7- MUX_ADC6
8- MUX_ADC7
*/
#define Single_Ended_Input MUX_ADC0



/*
ADC Enable or Disable Interrupt
Options:
1- Enable
2- Disable
*/
#define ADC_Interrupt  Disable

/*
ADC Mode
Options:
1- Single_Mode		
2- Free_Running_Mode
*/
#define ADC_Mode Free_Running_Mode


/*
ADC Clk Frequency
Options:
1- Prescaler_Div_By_2	
2- Prescaler_Div_By_4	
3- Prescaler_Div_By_8	
4- Prescaler_Div_By_16	
5- Prescaler_Div_By_32	
6- Prescaler_Div_By_64	
7- Prescaler_Div_By_128
*/

#define Prescaler_Value		Prescaler_Div_By_16

/*
ADC Data Representation
Options:
1- Right_Adjusted
2- Left_Adjusted
*/
#define Data_Representation Right_Adjusted


/*
Voltage Reference
Options:
1- External		
2- Internal_5V		
3- Internal_2_56V
*/

#define V_ref Internal_5V


#endif /* ADC_CFG_H_ */