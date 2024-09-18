/*
 * LED.c
 *
 * Created: 8/4/2023 9:25:20 AM
 *  Author: Sohaila Ibrahim
 */ 

#include"STD_TYPES.h"
#include"BIT_MATH.h"
#include<avr/io.h>
#include"DIO.h"

void LED_vInit(u8 portname,u8 pinnumber)
{
	DIO_vsetPINDir(portname,pinnumber,1);
}
void LED_vTurnOn(u8 portname,u8 pinnumber)
{
	DIO_Write(portname,pinnumber,1);
}
void LED_vTurnOff(u8 portname,u8 pinnumber)
{
	DIO_Write(portname,pinnumber,0);
}
void LED_vToggle(u8 portname,u8 pinnumber)
{
	DIO_toggle(portname,pinnumber);
}