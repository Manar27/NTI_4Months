/*
 ============================================================================
 Name		 : DIO_program.c
 Author		 : Manar Hashem
 Date		 : Oct 20, 2023
 Version	 : 1.0
 Description : DIO_program source file
 ============================================================================
*/

#include "../../LIB/STD_types.h"
#include "../../LIB/Bit_math.h"

#include "DIO_interface.h"

void DIO_VoidSetPortDirection(u8 Copy_u8PortID, u8 Copy_u8PortDir)
{
	switch (Copy_u8PortID) {
	case PORT_A:
		DIO_DDRA = Copy_u8PortDir;
		break;
	case PORT_B:
		DIO_DDRB = Copy_u8PortDir;
		break;
	case PORT_C:
		DIO_DDRC = Copy_u8PortDir;
		break;
	case PORT_D:
		DIO_DDRD = Copy_u8PortDir;
		break;
	}
}
void DIO_VoidSetPortValue(u8 Copy_u8PortID, u8 Copy_u8PortVal)
{
	switch (Copy_u8PortID) {
	case PORT_A:
		DIO_PORTA = Copy_u8PortVal;
		break;
	case PORT_B:
		DIO_PORTB = Copy_u8PortVal;
		break;
	case PORT_C:
		DIO_PORTC = Copy_u8PortVal;
		break;
	case PORT_D:
		DIO_PORTD = Copy_u8PortVal;
		break;
	}
}
void DIO_VoidSetPinDirection(u8 Copy_u8PortID, u8 Copy_u8PinNo, u8 Copy_u8PinDir)
{
	if(Copy_u8PortID <= PORT_D && Copy_u8PinNo <= PIN_7)
	{
		if(Copy_u8PinDir == DIO_INPUT)
		{
			switch (Copy_u8PortID) {
			case PORT_A:
				CLR_BIT(DIO_DDRA,Copy_u8PinNo);
				break;
			case PORT_B:
				CLR_BIT(DIO_DDRB,Copy_u8PinNo);
				break;
			case PORT_C:
				CLR_BIT(DIO_DDRC,Copy_u8PinNo);
				break;
			case PORT_D:
				CLR_BIT(DIO_DDRD,Copy_u8PinNo);
				break;
			}
		}
		else if(Copy_u8PinDir == DIO_OUTPUT)
		{
			switch (Copy_u8PortID) {
			case PORT_A:
				SET_BIT(DIO_DDRA,Copy_u8PinNo);
				break;
			case PORT_B:
				SET_BIT(DIO_DDRB,Copy_u8PinNo);
				break;
			case PORT_C:
				SET_BIT(DIO_DDRC,Copy_u8PinNo);
				break;
			case PORT_D:
				SET_BIT(DIO_DDRD,Copy_u8PinNo);
				break;
			}
		}
	}
}
void DIO_VoidSetPinVal(u8 Copy_u8PortID, u8 Copy_u8PinNo, u8 Copy_u8PinVal)
{
	if(Copy_u8PortID <= PORT_D && Copy_u8PinNo <= PIN_7)
	{
		if(Copy_u8PinVal == DIO_LOW)
		{
			switch (Copy_u8PortID) {
			case PORT_A:
				CLR_BIT(DIO_PORTA,Copy_u8PinNo);
				break;
			case PORT_B:
				CLR_BIT(DIO_PORTB,Copy_u8PinNo);
				break;
			case PORT_C:
				CLR_BIT(DIO_PORTC,Copy_u8PinNo);
				break;
			case PORT_D:
				CLR_BIT(DIO_PORTD,Copy_u8PinNo);
				break;
			}
		}
		else if(Copy_u8PinVal == DIO_HIGH)
		{
			switch (Copy_u8PortID) {
			case PORT_A:
				SET_BIT(DIO_PORTA,Copy_u8PinNo);
				break;
			case PORT_B:
				SET_BIT(DIO_PORTB,Copy_u8PinNo);
				break;
			case PORT_C:
				SET_BIT(DIO_PORTC,Copy_u8PinNo);
				break;
			case PORT_D:
				SET_BIT(DIO_PORTD,Copy_u8PinNo);
				break;
			}
		}
	}
}
u8 DIO_u8SetPortValue(u8 Copy_u8PortID, u8 Copy_u8PinNo)
{
	u8 Local_PinVal = 0;
	switch (Copy_u8PortID) {
	case PORT_A:
		Local_PinVal = GET_BIT(DIO_PORTA,Copy_u8PinNo);
		break;
	case PORT_B:
		Local_PinVal = GET_BIT(DIO_PORTB,Copy_u8PinNo);
		break;
	case PORT_C:
		Local_PinVal = GET_BIT(DIO_PORTC,Copy_u8PinNo);
		break;
	case PORT_D:
		Local_PinVal = GET_BIT(DIO_PORTD,Copy_u8PinNo);
		break;
	}
	return Local_PinVal;
}
void DIO_VoidTogPin(u8 Copy_u8PortID, u8 Copy_u8PinNo)
{
	switch (Copy_u8PortID) {
	case PORT_A:
		TOG_BIT(DIO_PORTA,Copy_u8PinNo);
		break;
	case PORT_B:
		TOG_BIT(DIO_PORTB,Copy_u8PinNo);
		break;
	case PORT_C:
		TOG_BIT(DIO_PORTC,Copy_u8PinNo);
		break;
	case PORT_D:
		TOG_BIT(DIO_PORTD,Copy_u8PinNo);
		break;
	}
}

