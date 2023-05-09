#ifndef ADC_PRV_H_
#define ADC_PRV_H_

#define		ADC_VAL				*((volatile u16*) 0x24)


#define 	ADMUX				*((volatile u8*) 0x27)

#define 	ADCSRA				*((volatile u8*) 0x26)

#define 	ADCH				*((volatile u8*) 0x25)
#define 	ADCL				*((volatile u8*) 0x24)

#define 	SFIOR				*((volatile u8*) 0x50)

#define  Disable	0
#define  Enable		1

#define Single_Mode			0
#define Free_Running_Mode	1

#define Start_Conversion 0b01000000

#define MUX_CLR_MASK	0b11100000
#define MUX_ADC0		0b00000000
#define MUX_ADC1		0b00000001
#define MUX_ADC2		0b00000010
#define MUX_ADC3		0b00000011
#define MUX_ADC4		0b00000100
#define MUX_ADC5		0b00000101
#define MUX_ADC6		0b00000110
#define MUX_ADC7		0b00000111

#define Prescaler_CLR_MASK		0b11111000
#define Prescaler_Div_By_2		0b00000001
#define Prescaler_Div_By_4		0b00000010
#define Prescaler_Div_By_8		0b00000011
#define Prescaler_Div_By_16		0b00000100
#define Prescaler_Div_By_32		0b00000101
#define Prescaler_Div_By_64		0b00000110
#define Prescaler_Div_By_128	0b00000111

#define Right_Adjusted	0b00000000
#define Left_Adjusted	0b00100000

#define V_ref_CLR_MASK	0b00111111
#define	External		0b00000000
#define	Internal_5V		0b01000000
#define	Internal_2_56V	0b11000000



#define ADC_TRIGGER_CLR_MASK		0b00011111
#define ADC_TRIGGER_FREE_RUNNING	0b00000000
#define ADC_TRIGGER_ANALOG_COMPA	0b00100000
#define ADC_TRIGGER_EXTI0			0b01000000
#define ADC_TRIGGER_TIM0_COMP		0b01100000
#define ADC_TRIGGER_TIM0_OVF		0b10000000
#define ADC_TRIGGER_TIM1_COMPB		0b10100000
#define ADC_TRIGGER_TIM1_OVF		0b11000000
#define ADC_TRIGGER_TIM1_CAP_EVENT	0b11100000


#endif /* ADC_PRV_H_ */