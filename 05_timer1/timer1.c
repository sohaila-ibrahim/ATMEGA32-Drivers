
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <avr/interrupt.h>

#include "timer1.h"
#include "stdio.h"


static void(*TIMER1_PFICU)(void);


void Timer1_vidtimer1Normal(void)//timer1 input capture unit
{
	/* fast PWM */
	CLR_BIT(TCCR1A, WGM10);
	CLR_BIT(TCCR1A, WGM11);
	CLR_BIT(TCCR1B, WGM12);
	CLR_BIT(TCCR1B, WGM13);

	/* CLK/8 */
	CLR_BIT(TCCR1B, CS10);//preScalar = 8
	SET_BIT(TCCR1B, CS11);
	CLR_BIT(TCCR1B, CS12);
}
void TMR1_Timer1FPWM_Vid(void)//timer1 fast PWM
{
	/* fast PWM */
	CLR_BIT(TCCR1A, WGM10);
	SET_BIT(TCCR1A, WGM11);
	SET_BIT(TCCR1B, WGM12);
	SET_BIT(TCCR1B, WGM13);

	/* clear OCR1A */
	CLR_BIT(TCCR1A, COM1A0);
	SET_BIT(TCCR1A, COM1A1);

	/*Time OVF*/
	ICR1 = 19999;//time overflow = 20ms --> 20000us

	/* CLK/8 */
	CLR_BIT(TCCR1B, CS10);//preScalar = 8
	SET_BIT(TCCR1B, CS11);
	CLR_BIT(TCCR1B, CS12);

}

void ICU_VidInit(void)
{
	SET_BIT(TCCR1B, ICES1);//rising edge
	SET_BIT(TIMSK, TICIE1);//ICU_INT Enable
}

void ICU_VidEdgeSelect(u8 Copy_u8EdgeSelect)
{
	switch(Copy_u8EdgeSelect)
	{
		case 0 : CLR_BIT(TCCR1B, ICES1);break;
		case 1 : SET_BIT(TCCR1B, ICES1);break;
	}
}

u16 ICU_u16ReadICR(void)
{
	return ICR1;
}

void ICU_VidINT_Disable(void)
{
	CLR_BIT(TIMSK, TICIE1);
}

void ICU_VidSetCallBack(void(*Copy_PFCallBack)(void))
{
	TIMER1_PFICU = Copy_PFCallBack;
}

ISR(TIMER1_CAPT_vect)
{
	if(TIMER1_PFICU != NULL)
	{
		TIMER1_PFICU();
	}
}
