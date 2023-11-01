/*
 ============================================================================
 Name        : SSD_program.c
 Author      : Manar Hashem
 Date		 : Oct 20, 2023
 Version     : 1.0
 Description : SSD_program source file
 ============================================================================
 */

#include <util/delay.h>
#include "../../LIB/STD_types.h"
#include "../../LIB/Bit_math.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "SSD_interface.h"


void SSD_VoidInit(SSD_SelectType Local_Select)
{
	/* Set the Direction of each BCD pin as output */
	DIO_VoidSetPinDirection(BCD_A_PORT,BCD_A_PIN,SSD_OUTPUT);
	DIO_VoidSetPinDirection(BCD_B_PORT,BCD_B_PIN,SSD_OUTPUT);
	DIO_VoidSetPinDirection(BCD_C_PORT,BCD_C_PIN,SSD_OUTPUT);
	DIO_VoidSetPinDirection(BCD_D_PORT,BCD_D_PIN,SSD_OUTPUT);

	/* Set the Direction of each Common pin as output */
	DIO_VoidSetPinDirection(COM1_PORT,COM1_PIN,SSD_OUTPUT);
	DIO_VoidSetPinDirection(COM2_PORT,COM2_PIN,SSD_OUTPUT);
	DIO_VoidSetPinDirection(COM3_PORT,COM3_PIN,SSD_OUTPUT);
	DIO_VoidSetPinDirection(COM4_PORT,COM4_PIN,SSD_OUTPUT);

	SSD_VoidDisplay_COM(Local_Select, 0);
}
void SSD_VoidDisplayNo(u8 Local_Number)
{
	if (Local_Number <= SSD_NINE && Local_Number >= SSD_ZERO)
	{
		DIO_VoidSetPinVal(BCD_A_PORT,BCD_A_PIN, GET_BIT(Local_Number,0));
		DIO_VoidSetPinVal(BCD_B_PORT,BCD_B_PIN, GET_BIT(Local_Number,1));
		DIO_VoidSetPinVal(BCD_C_PORT,BCD_C_PIN, GET_BIT(Local_Number,2));
		DIO_VoidSetPinVal(BCD_D_PORT,BCD_D_PIN, GET_BIT(Local_Number,3));
	}
}
void SSD_VoidDisplayRange(u8 Local_Start, u8 Local_End)
{
	if(Local_Start <= Local_End && Local_Start >= SSD_ZERO && Local_End <= SSD_NINE)
	{
		u8 Local_counter = 0;
		for (Local_counter = Local_Start; Local_counter <= Local_End ; Local_counter++)
		{
			SSD_VoidDisplayNo(Local_counter);
			_delay_ms(1000);
		}
	}
}

void SSD_VoidClear(void)
{
	SSD_VoidDisplayNo(0);
}
void SSD_VoidDisplay_COM(SSD_SelectType Local_Select, u8 Local_Number)
{
	if (Local_Select == SSD_NO_1 )
	{
		DIO_VoidSetPinVal(COM1_PORT,COM1_PIN,SSD_LOW);
		DIO_VoidSetPinVal(COM2_PORT,COM2_PIN,SSD_HIGH);
		DIO_VoidSetPinVal(COM3_PORT,COM3_PIN,SSD_HIGH);
		DIO_VoidSetPinVal(COM4_PORT,COM4_PIN,SSD_HIGH);
	}
	else if (Local_Select == SSD_NO_2)
	{
		DIO_VoidSetPinVal(COM1_PORT,COM1_PIN,SSD_HIGH);
		DIO_VoidSetPinVal(COM2_PORT,COM2_PIN,SSD_LOW);
		DIO_VoidSetPinVal(COM3_PORT,COM3_PIN,SSD_HIGH);
		DIO_VoidSetPinVal(COM4_PORT,COM4_PIN,SSD_HIGH);
	}
	else if (Local_Select == SSD_NO_3)
	{
		DIO_VoidSetPinVal(COM1_PORT,COM1_PIN,SSD_HIGH);
		DIO_VoidSetPinVal(COM2_PORT,COM2_PIN,SSD_HIGH);
		DIO_VoidSetPinVal(COM3_PORT,COM3_PIN,SSD_LOW);
		DIO_VoidSetPinVal(COM4_PORT,COM4_PIN,SSD_HIGH);
	}

	else if (Local_Select == SSD_NO_4)
	{
		DIO_VoidSetPinVal(COM1_PORT,COM1_PIN,SSD_HIGH);
		DIO_VoidSetPinVal(COM2_PORT,COM2_PIN,SSD_HIGH);
		DIO_VoidSetPinVal(COM3_PORT,COM3_PIN,SSD_HIGH);
		DIO_VoidSetPinVal(COM4_PORT,COM4_PIN,SSD_LOW);
	}
	SSD_VoidDisplayNo(Local_Number);
}
