/*
 * timer0.c
 *
 *  Created on: Aug 20, 2023
 *      Author: hamada
 */
#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include <avr/interrupt.h>
#include "timer0.h"
#include <avr/io.h>
#include "GIE.h"


static void (*TIMER0_PF_OVF) (void);
static void (*TIMER0_PF_CTC) (void);

u16 Global_u16Time_ms = 0;

void TIMER0_Timer0InitOVF_Vid(void)
{
	/* Normal Mode */
	CLR_BIT(TCCR0, WGM00);
	CLR_BIT(TCCR0, WGM01);

	/* OVF Interrupt */
	SET_BIT(TIMSK, TOIE0);

	TCNT0 = 192;

	/* CLK/8 */
	CLR_BIT(TCCR0, CS00);
	SET_BIT(TCCR0, CS01);
	CLR_BIT(TCCR0, CS02);

}

void TIMER0_VidTimer0FPWMInit(void)
{
	/*Fast PWM*/
	SET_BIT(TCCR0,WGM00);
	SET_BIT(TCCR0,WGM01);

	/*Clear OC0 on compare match . set OC0 ay TOP*/
	CLR_BIT(TCCR0,COM00);
	SET_BIT(TCCR0,COM01);

	OCR0 = 99;

	/* CLK/8 */
	CLR_BIT(TCCR0, CS00);
	SET_BIT(TCCR0, CS01);
	CLR_BIT(TCCR0, CS02);

}



void TIMER0_Timer0SetCallBackOVF(void (*Copy_u8TimerOVF) (void))
{
	TIMER0_PF_OVF = Copy_u8TimerOVF;
}


ISR(TIMER0_OVF_vect)
{
	static u16 Local_u16CtrOVF = 0;
	Local_u16CtrOVF++;
	if(Local_u16CtrOVF == 3907)
	{
		TIMER0_PF_OVF();
		Local_u16CtrOVF = 0;
		TCNT0 = 192;
	}

}


void TIMER0_Timer0InitCTC_Vid(u16 Copy_u8Time_ms)
{
	Global_u16Time_ms = Copy_u8Time_ms;

	/* CTC Mode */
	CLR_BIT(TCCR0, WGM00);
	SET_BIT(TCCR0, WGM01);

	/* OVF Interrupt */
	SET_BIT(TIMSK, OCIE0);

	OCR0 = 250;/* need 1milliSecond /// AssumePreScalar=8 --> TickTime=10e-6 /// AssumeNumberOfTicks=250 --> NumberOfFlagSetted=4*/

	/* CLK/8 */
	CLR_BIT(TCCR0, CS00);
	SET_BIT(TCCR0, CS01);
	CLR_BIT(TCCR0, CS02);
}

void TIMER0_Timer0SetCallBackCTC(void (*Copy_u8TimerCTC) (void))
{
	TIMER0_PF_CTC = Copy_u8TimerCTC;
}

ISR(TIMER0_COMP_vect)
{
	static u16 Local_u16CtrCTC = 0;
	Local_u16CtrCTC++;
	if(Local_u16CtrCTC == (4 * Global_u16Time_ms))
	{
		TIMER0_PF_CTC();
		Local_u16CtrCTC = 0;
	}
}
