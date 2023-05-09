#include "Bit_math.h"
#include "Std_Types.h"
#include "DIO.h"
#include "DIO_Prv.h"
#include "Timer_0.h"
#include "G_INT.h"
#include "button.h"
#include "s_segment.h"



s8 counter = 0;
u16 temp;
u16 pre_load;
u8 p1;
u8 p2;
void test (void);


int main(void)
{
	GIE_INIT();
	DIO_enuInit();
	TMR0_vidInitPreCompile();
	//TMR0_enuSetTickTimems(1000,&temp,&pre_load);
	//TMR0_enuRegisterCallback(&test);
	
	
    /* Replace with your application code */
    while (1) 
    {
		ButtonIsPressed(0,&p1);
		ButtonIsPressed(1,&p2);
		
		if(p1 == 0)
		{
			counter+=10;
			if(counter>=100)
			{
				counter =100;
			}
		}
		
		if(p2 == 0)
		{
			counter-=10;
			if(counter<=0)
			{
				counter =0;
			}
		}
		
			TMR0_enuPWM_DutyCycle(counter);
		
    }
}

void test (void)
{
	if(counter < temp)
	{
		
		counter++;
		
	}
	else if(counter == temp)
	{
		counter = 0;
		//TCNT0 |= (u8)pre_load;
		TCNT0 |= pre_load;
		
		TOG_BIT(PORTA,0);
		
	}
	
	SET_BIT(TIFR,0);
	

}