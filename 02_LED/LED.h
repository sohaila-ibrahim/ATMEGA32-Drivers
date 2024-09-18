/*
 * LED.h
 *
 * Created: 8/4/2023 9:25:43 AM
 *  Author: Sohaila Ibrahim
 */ 


#ifndef LED_H_
#define LED_H_

void LED_vInit(u8 portname,u8 pinnumber);
void LED_vTurnOn(u8 portname,u8 pinnumber);
void LED_vTurnOff(u8 portname,u8 pinnumber);
void LED_vToggle(u8 portname,u8 pinnumber);




#endif /* LED_H_ */