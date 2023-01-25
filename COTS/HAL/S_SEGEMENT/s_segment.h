#ifndef S_SEGMENT_H
#define S_SEGMENT_H



#define S_SEGMENT_PORTA 0
#define S_SEGMENT_PORTB 1
#define S_SEGMENT_PORTC 2
#define S_SEGMENT_PORTD 3


typedef enum
{
	SSEGMENT_enuOK=0,
	SSEGMENT_enuNOK
}SSEGMENT_enuErrorStatus;


SSEGMENT_enuErrorStatus SsegmentDisplayValue(DIO_tenuPorts Cpy_PortNumber, u8 Cpy_SSegmentValue);

#endif /*S_SEGMENT_H*/