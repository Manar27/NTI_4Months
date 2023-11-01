/*
 ============================================================================
 Name		 : DIO_interface.h
 Author		 : Manar Hashem
 Date		 : Oct 20, 2023
 Version	 : 1.0
 Description : DIO_interfac header file
 ============================================================================
*/
#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

#include "DIO_register.h"
#include "DIO_private.h"
#include "DIO_config.h"

#define PIN_0		0
#define PIN_1		1
#define PIN_2		2
#define PIN_3		3
#define PIN_4		4
#define PIN_5		5
#define PIN_6		6
#define PIN_7		7

#define PORT_A		1
#define PORT_B		2
#define PORT_C		3
#define PORT_D		4

#define DIO_OUTPUT	1
#define DIO_INPUT	0
#define DIO_HIGH	1
#define DIO_LOW		0

#define DIO_PORT_OUTPUT		0xFF
#define DIO_PORT_INPUT		0x00
void DIO_VoidSetPortDirection(u8 Copy_u8PortID, u8 Copy_u8PortDir);
void DIO_VoidSetPortValue(u8 Copy_u8PortID, u8 Copy_u8PortVal);
void DIO_VoidSetPinDirection(u8 Copy_u8PortID, u8 Copy_u8PinNo, u8 Copy_u8PinDir);
void DIO_VoidSetPinVal(u8 Copy_u8PortID, u8 Copy_u8PinNo, u8 Copy_u8PinVal);

#endif /* DIO_INTERFACE_H_ */
