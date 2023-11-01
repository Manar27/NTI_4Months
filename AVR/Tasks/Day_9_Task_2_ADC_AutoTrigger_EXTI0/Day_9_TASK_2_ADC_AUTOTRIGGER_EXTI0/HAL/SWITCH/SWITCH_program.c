/*
 ============================================================================
 Name        : SWITCH_program.c
 Author      : Manar Hashem
 Date		 : Oct 22, 2023
 Version     : 1.0
 Description : SWITCH_program source file
 ============================================================================
 */
#include "../../LIB/Bit_math.h"
#include "../../LIB/STD_types.h"

#include "../../MCAL/DIO/DIO_interface.h"
#include "SWITCH_interface.h"

void SWITCH_VoidInit(SWITCH_SelectType Local_SwitchNO)
{
	switch(Local_SwitchNO)
	{
	case SW_NO_1:
		DIO_VoidSetPinDirection(SWITCH_PORT,SWITCH_1_PIN,DIO_INPUT);
		DIO_VoidSetPinVal(SWITCH_PORT,SWITCH_1_PIN,DIO_HIGH);
		break;
	case SW_NO_2:
		DIO_VoidSetPinDirection(SWITCH_PORT,SWITCH_2_PIN,DIO_INPUT);
		DIO_VoidSetPinVal(SWITCH_PORT,SWITCH_2_PIN,DIO_HIGH);
		break;
	case SW_NO_3:
		DIO_VoidSetPinDirection(SWITCH_PORT,SWITCH_3_PIN,DIO_INPUT);
		DIO_VoidSetPinVal(SWITCH_PORT,SWITCH_3_PIN,DIO_HIGH);
		break;
	case SW_NO_4:
		DIO_VoidSetPinDirection(SWITCH_PORT,SWITCH_4_PIN,DIO_INPUT);
		DIO_VoidSetPinVal(SWITCH_PORT,SWITCH_4_PIN,DIO_HIGH);
		break;
	default:
		//No Code
		break;
	}
}
u8 SWITCH_u8ReadSwitch(SWITCH_SelectType Local_SwitchNO)
{
	if(DIO_u8GetPinVal(SWITCH_PORT,SWITCH_1_PIN) == SWITCH_PRESSED)
	{
		while(DIO_u8GetPinVal(SWITCH_PORT,SWITCH_1_PIN) != SWITCH_RELEASED);
		return 1;
	}
	return 0;
}
