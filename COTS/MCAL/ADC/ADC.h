#ifndef ADC_H_
#define ADC_H_

typedef enum
{
	ADC_enuChannel0 = 0b00000,
	ADC_enuChannel1 = 0b00001,
	ADC_enuChannel2 = 0b00010,
	ADC_enuChannel3 = 0b00011,
	ADC_enuChannel4 = 0b00100,
	ADC_enuChannel5 = 0b00101,
	ADC_enuChannel6 = 0b00110,
	ADC_enuChannel7 = 0b00111
	
	
}ADC_tenuChannelNumber;



typedef enum
{
	ADC_enuNOK = 0,
	ADC_enuOK
}ADC_enuErrorStatus;

ADC_enuErrorStatus ADC_Init(void);

ADC_enuErrorStatus ADC_Read_Value(ADC_tenuChannelNumber Cpy_ChannelNumber, u16* Add_ADC_Value);








#endif /* ADC_H_ */