#include "Bit_math.h"
#include "Std_Types.h"
#include "DIO.h"
#include "DIO_Prv.h"
#include "Timer_0.h"
#include "G_INT.h"
#include "delay.h"
u16 counter = 0;
u16 temp;
u16 pre_load;
void test (void);


int main(void)
{
	GIE_INIT();
	DIO_enuInit();
	TMR0_vidInitPreCompile();
	TMR0_enuSetTickTimems(1000,&temp,&pre_load);
	TMR0_enuRegisterCallback(&test);
	
    /* Replace with your application code */
    while (1) 
    {
		
		
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
		
		TOG_BIT(PORTA,7);
	}
	
	SET_BIT(TIFR,0);
	

}