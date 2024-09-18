/*
 * timer1.h
 *
 *  Created on: Aug 22, 2023
 *      Author: hamada
 */

#ifndef MCAL_TIMER1_TIMER1_H_
#define MCAL_TIMER1_TIMER1_H_

#include "STD_TYPES.h"

void Timer1_vidtimer1Normal(void);
void TMR1_Timer1FPWM_Vid(void);
void ICU_VidInit(void);
void ICU_VidEdgeSelect(u8 Copy_u8EdgeSelect);
u16 ICU_u16ReadICR(void);
void ICU_VidINT_Disable(void);
void ICU_VidSetCallBack(void(*Copy_PFCallBack)(void));

#endif /* MCAL_TIMER1_TIMER1_H_ */
