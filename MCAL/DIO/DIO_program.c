/*
 ============================================================================
 Name		 : DIO_program.c
 Author		 : Manar Hashem
 Date		 : Oct 25, 2023
 Version	 : 2.0 (Struct Configuration)
 Description : DIO_program source file
 ============================================================================
 */

#include "../../LIB/STD_types.h"
#include "../../LIB/Bit_math.h"

#include "DIO_interface.h"

DIO_ERROR_RETURN DIO_VoidSetPortDirection(PORT_SELECT_TYPE Copy_u8PortID, PORT_DIRECTION Copy_u8PortDir)
{
	DIO_ERROR_RETURN Local_Error = DIO_OK;

	switch (Copy_u8PortID) {
	case PORT_A:
		DIO_DDRA->Byte = Copy_u8PortDir;
		break;
	case PORT_B:
		DIO_DDRB->Byte = Copy_u8PortDir;
		break;
	case PORT_C:
		DIO_DDRC->Byte = Copy_u8PortDir;
		break;
	case PORT_D:
		DIO_DDRD->Byte = Copy_u8PortDir;
		break;
	default:
		Local_Error = PORT_OUT_OF_RANGE;
		break;
	}
	return Local_Error;
}

DIO_ERROR_RETURN DIO_VoidSetPortValue(PORT_SELECT_TYPE Copy_u8PortID, PORT_VALUE Copy_u8PortVal)
{
	DIO_ERROR_RETURN Local_Error = DIO_OK;

	switch (Copy_u8PortID) {
	case PORT_A:
		DIO_PORTA->Byte = Copy_u8PortVal;
		break;
	case PORT_B:
		DIO_PORTB->Byte = Copy_u8PortVal;
		break;
	case PORT_C:
		DIO_PORTC->Byte = Copy_u8PortVal;
		break;
	case PORT_D:
		DIO_PORTD->Byte = Copy_u8PortVal;
		break;
	default:
		Local_Error = PORT_OUT_OF_RANGE;
		break;
	}
	return Local_Error;
}

DIO_ERROR_RETURN DIO_VoidSetPinDirection(PORT_SELECT_TYPE Copy_u8PortID, PIN_SELECT_TYPE Copy_u8PinNo, PIN_DIRECTION Copy_u8PinDir)
{
	DIO_ERROR_RETURN Local_Error = DIO_OK;

	if( (Copy_u8PinNo >= 0 ) && (Copy_u8PinNo <= PIN_7) )
	{
		if(Copy_u8PinDir == DIO_INPUT)
		{
			switch (Copy_u8PortID) {
			case PORT_A:
				CLR_BIT(DIO_DDRA->Byte, Copy_u8PinNo);
				break;
			case PORT_B:
				CLR_BIT(DIO_DDRB->Byte,Copy_u8PinNo);
				break;
			case PORT_C:
				CLR_BIT(DIO_DDRC->Byte,Copy_u8PinNo);
				break;
			case PORT_D:
				CLR_BIT(DIO_DDRD->Byte,Copy_u8PinNo);
				break;
			default:
				Local_Error = PORT_OUT_OF_RANGE;
				break;
			}
		}
		else if(Copy_u8PinDir == DIO_OUTPUT)
		{
			switch (Copy_u8PortID) {
			case PORT_A:
				SET_BIT(DIO_DDRA->Byte,Copy_u8PinNo);
				break;
			case PORT_B:
				SET_BIT(DIO_DDRB->Byte,Copy_u8PinNo);
				break;
			case PORT_C:
				SET_BIT(DIO_DDRC->Byte,Copy_u8PinNo);
				break;
			case PORT_D:
				SET_BIT(DIO_DDRD->Byte,Copy_u8PinNo);
				break;
			default:
				Local_Error = PORT_OUT_OF_RANGE;
				break;
			}
		}
	}
	else
	{
		Local_Error = PIN_OUT_OF_RANGE;
	}
	return Local_Error;
}

DIO_ERROR_RETURN DIO_VoidSetPinVal(PORT_SELECT_TYPE Copy_u8PortID, PIN_SELECT_TYPE Copy_u8PinNo, PIN_VALUE Copy_u8PinVal)
{
	DIO_ERROR_RETURN Local_Error = DIO_OK;

	if( (Copy_u8PinNo >= 0 ) && (Copy_u8PinNo <= PIN_7) )
	{
		if(Copy_u8PinVal == DIO_LOW)
		{
			switch (Copy_u8PortID) {
			case PORT_A:
				CLR_BIT(DIO_PORTA->Byte,Copy_u8PinNo);
				break;
			case PORT_B:
				CLR_BIT(DIO_PORTB->Byte,Copy_u8PinNo);
				break;
			case PORT_C:
				CLR_BIT(DIO_PORTC->Byte,Copy_u8PinNo);
				break;
			case PORT_D:
				CLR_BIT(DIO_PORTD->Byte,Copy_u8PinNo);
				break;
			default:
				Local_Error = PORT_OUT_OF_RANGE;
				break;
			}
		}
		else if(Copy_u8PinVal == DIO_HIGH)
		{
			switch (Copy_u8PortID) {
			case PORT_A:
				SET_BIT(DIO_PORTA->Byte,Copy_u8PinNo);
				break;
			case PORT_B:
				SET_BIT(DIO_PORTB->Byte,Copy_u8PinNo);
				break;
			case PORT_C:
				SET_BIT(DIO_PORTC->Byte,Copy_u8PinNo);
				break;
			case PORT_D:
				SET_BIT(DIO_PORTD->Byte,Copy_u8PinNo);
				break;
			default:
				Local_Error = PORT_OUT_OF_RANGE;
				break;
			}
		}
	}
	else
	{
		Local_Error = PIN_OUT_OF_RANGE;
	}
	return Local_Error;
}

u8 DIO_u8GetPinVal(PORT_SELECT_TYPE Copy_u8PortID, PIN_SELECT_TYPE Copy_u8PinNo)
{
	u8 Local_PinVal = 0;
	if (Copy_u8PortID <= PORT_D && Copy_u8PinNo <= PIN_7)
	{
		switch (Copy_u8PortID)
		{
		case PORT_A:
			Local_PinVal = GET_BIT(DIO_PINA->Byte, Copy_u8PinNo);
			break;
		case PORT_B:
			Local_PinVal = GET_BIT(DIO_PINB->Byte, Copy_u8PinNo);
			break;
		case PORT_C:
			Local_PinVal = GET_BIT(DIO_PINC->Byte, Copy_u8PinNo);
			break;
		case PORT_D:
			Local_PinVal = GET_BIT(DIO_PIND->Byte, Copy_u8PinNo);
			break;
		default:
			//No Code
			break;
		}
		return Local_PinVal;
	}
	else
	{
		return -1;
	}
}

DIO_ERROR_RETURN DIO_VoidTogPin(PORT_SELECT_TYPE Copy_u8PortID, PIN_SELECT_TYPE Copy_u8PinNo)
{
	DIO_ERROR_RETURN Local_Error = DIO_OK;

	if( (Copy_u8PinNo >= 0 ) && (Copy_u8PinNo <= PIN_7) )
	{
		switch (Copy_u8PortID) {
		case PORT_A:
			TOG_BIT(DIO_PORTA->Byte, Copy_u8PinNo);
			break;
		case PORT_B:
			TOG_BIT(DIO_PORTB->Byte, Copy_u8PinNo);
			break;
		case PORT_C:
			TOG_BIT(DIO_PORTC->Byte, Copy_u8PinNo);
			break;
		case PORT_D:
			TOG_BIT(DIO_PORTD->Byte, Copy_u8PinNo);
			break;
		default:
			Local_Error = PORT_OUT_OF_RANGE;
			break;
		}
	}
	else
	{
		Local_Error = PIN_OUT_OF_RANGE;
	}
	return Local_Error;
}
