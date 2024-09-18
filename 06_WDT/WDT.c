#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "WDT.h"
#include <avr/interrupt.h>


void WDH_VidInit(void)
{
	SET_BIT(WDTCR,WDE);
}
void WDT_VidWDSleeep(u8 Copy_u8Sleep)
{
	CLR_BIT(WDTCR,WDP0);
	CLR_BIT(WDTCR,WDP1);
	CLR_BIT(WDTCR,WDP2);
	WDTCR |=Copy_u8Sleep;
}
void WDT_Disable(void)
{
	WDTCR=(1<<WDE)|(1<<WDTOE);
	CLR_BIT(WDTCR,WDTOE);
}
