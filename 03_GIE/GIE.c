/*
 * GIE.c
 *
 *  Created on: Aug 20, 2023
 *      Author: Hesham
 */

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include <avr/interrupt.h>
#include "GIE.h"


void GIE_Enable(void)
{
	SET_BIT(SREG,7);
}

void GIE_Disable(void)
{
	CLR_BIT(SREG,7);
}
