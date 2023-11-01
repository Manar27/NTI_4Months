/*
 ============================================================================
 Name        : main.c
 Author      : Manar Hashem
 Date		 : Oct 20, 2023
 Version     : 1.0
 Description : Ping-pong LEDs effect
 ============================================================================
 */

#define F_CPU	12000000UL
#include <util/delay.h>
#include "../LIB/STD_types.h"
#include "../MCAL/DIO/DIO_interface.h"

int main(void)
{
	DIO_VoidSetPinDirection(PORT_A,PIN_6,DIO_OUTPUT);
	DIO_VoidSetPinDirection(PORT_A,PIN_5,DIO_OUTPUT);
	DIO_VoidSetPinDirection(PORT_A,PIN_4,DIO_OUTPUT);
	DIO_VoidSetPinDirection(PORT_B,PIN_7,DIO_OUTPUT);

	while (1)
	{

		DIO_VoidSetPinVal(PORT_A, PIN_6, DIO_LOW);
		DIO_VoidSetPinVal(PORT_A, PIN_5, DIO_LOW);
		DIO_VoidSetPinVal(PORT_A, PIN_4, DIO_LOW);
		DIO_VoidSetPinVal(PORT_B, PIN_7, DIO_HIGH);
		_delay_ms(250);

		DIO_VoidSetPinVal(PORT_A, PIN_6, DIO_LOW);
		DIO_VoidSetPinVal(PORT_A, PIN_5, DIO_LOW);
		DIO_VoidSetPinVal(PORT_A, PIN_4, DIO_HIGH);
		DIO_VoidSetPinVal(PORT_B, PIN_7, DIO_LOW);
		_delay_ms(250);

		DIO_VoidSetPinVal(PORT_A, PIN_6, DIO_LOW);
		DIO_VoidSetPinVal(PORT_A, PIN_5, DIO_HIGH);
		DIO_VoidSetPinVal(PORT_A, PIN_4, DIO_LOW);
		DIO_VoidSetPinVal(PORT_B, PIN_7, DIO_LOW);
		_delay_ms(250);

		DIO_VoidSetPinVal(PORT_A, PIN_6, DIO_HIGH);
		DIO_VoidSetPinVal(PORT_A, PIN_5, DIO_LOW);
		DIO_VoidSetPinVal(PORT_A, PIN_4, DIO_LOW);
		DIO_VoidSetPinVal(PORT_B, PIN_7, DIO_LOW);
		_delay_ms(250);

	}
}
