#include "STD_TYPES.h"
#include"BIT_MATH.h"

#include <avr/interrupt.h>
#include"Servo.h"

void Timer1_VidTimer1FPWM(void)
{
	//FAST PWM
	CLR_BIT(TCCR1A,WGM10);
	SET_BIT(TCCR1A,WGM11);
	SET_BIT(TCCR1B,WGM12);
	SET_BIT(TCCR1B,WGM13);


	//Clear OCR1A
	CLR_BIT(TCCR1A,COM1A0);
	SET_BIT(TCCR1A,COM1A1);

	//Timer OVF
	ICR1=19999;

	//CLK  /8
	CLR_BIT(TCCR1B,CS10);
	SET_BIT(TCCR1B,CS11);
	CLR_BIT(TCCR1B,CS12);

}
void Servo_VidServoAngel(u8 Copy_U8Angel)
{
	if(Copy_U8Angel==0)
	{
		OCR1A=999;
	}
	if(Copy_U8Angel==90)
		{
			OCR1A=1499;
		}
	if(Copy_U8Angel==180)
		{
			OCR1A=2000;
		}
}
