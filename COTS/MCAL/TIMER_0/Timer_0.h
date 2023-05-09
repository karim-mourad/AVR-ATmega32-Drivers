


#ifndef TIMER_0_H_
#define TIMER_0_H_

#include "Std_Types.h"
#include "Bit_math.h"
#include <math.h>
#include "Timer_0_Cfg.h"
#include "Timer_0_Prv.h"

#define TIMER0_STOP			(0b11111000)

#define AMP 1000000
#define ms  1000

typedef void(*TMR0cbf_t)(void);


#define MODE_CLEAR_MASK					(0b10110111)
#define OUTPUT_COMPARE_CLEAR_MASK		(0b11001111)
#define PRESCALER_CLEAR_MASK			(0b11111000)

/*Mode*/           
#define Normal				(0b00000000)
#define PWM_PHASE_CORRECT	(0b01000000)
#define CTC					(0b00001000)
#define FAST_PWM			(0b01001000)

/*Compare Output Mode, non-PWM Mode(normal or CTC)*/
#define OC0_DISCONNECTED	(0b00000000)
#define OC0_TOGGLE			(0b00010000)
#define OC0_CLEAR			(0b00100000)
#define OC0_SET				(0b00110000)

/*Compare Output Mode, Fast PWM mode*/
#define OC0_DISCONNECTED				(0b00000000)
#define OC0_CLEAR_ON_COMPARE			(0b00100000)
#define OC0_SET_ON_COMPARE			(0b00110000)

/*Compare Output Mode, Phase Correct PWM Mode*/
#define OC0_DISCONNECTED							(0b00000000)
#define OC0_CLEAR_UP_COUNT_SET_DOWN_COUNT			(0b00100000)
#define OC0_SET_UP_COUNT_CLEAR_DOWN_COUNT			(0b00110000)

/*Prescaler*/
#define NO_CLK_SOURCE				(0b00000000)
#define NO_PRESACLING				(0b00000001)
#define DIV_8						(0b00000010)
#define DIV_64						(0b00000011)
#define DIV_256						(0b00000100)
#define DIV_1024					(0b00000101)
#define EXT_SRC_FALLING_EDGE		(0b00000110)
#define EXT_SRC_RISING_EDGE			(0b00000111)

#define Enable		1
#define Disable		0



typedef enum
{
	TIM0_enuOK = 0,
	TIM0_enuNOK,
	TIM0_enuNullPtrFunc
}TIM0_tenuErrorStatus;



void TMR0_vidInitPreCompile(void);
//void TMR0_vidInitPostCompile(TMR0Config_t);
TIM0_tenuErrorStatus TMR0_enuSetTickTimems(u16 Copy_u16Required_Time, u16* Copy_pu16Max_Count, u16* Copy_pu16Pre_Load); //Copy_u16Required_Time in milliseconds
TIM0_tenuErrorStatus TMR0_enuPWM_DutyCycle(u16 Copy_u16Required_Duty_Cycle); //Copy_u16Required_Duty_Cycle in percentage eg: 20,50
TIM0_tenuErrorStatus TMR0_enuStart(void);
TIM0_tenuErrorStatus TMR0_enuStop(void);
TIM0_tenuErrorStatus TMR0_enuRegisterCallback(TMR0cbf_t Cpy_TMR0Cbf);

#endif /* TIMER_0_H_ */