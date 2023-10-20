/*
 ============================================================================
 Name        : SEVSEG_program.c
 Author      : Manar Hashem
 Date		 : Oct 20, 2023
 Version     : 1.0
 Description : SEVSEG_program source file
 ============================================================================
 */

#include <util/delay.h>
#include "../../LIB/STD_types.h"
#include "../../LIB/Bit_math.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "SEVSEG_interface.h"


void SEVSEG_VoidInit(void)
{
	/* Set the Direction of each BCD pin as output */
	DIO_VoidSetPinDirection(BCD_A_PORT,BCD_A_PIN,SEVSEG_OUTPUT);
	DIO_VoidSetPinDirection(BCD_B_PORT,BCD_B_PIN,SEVSEG_OUTPUT);
	DIO_VoidSetPinDirection(BCD_C_PORT,BCD_C_PIN,SEVSEG_OUTPUT);
	DIO_VoidSetPinDirection(BCD_D_PORT,BCD_D_PIN,SEVSEG_OUTPUT);

	/* Set the Direction of each Common pin as output */
	DIO_VoidSetPinDirection(COM1_PORT,COM1_PIN,SEVSEG_OUTPUT);
	DIO_VoidSetPinDirection(COM2_PORT,COM2_PIN,SEVSEG_OUTPUT);
	DIO_VoidSetPinDirection(COM3_PORT,COM3_PIN,SEVSEG_OUTPUT);
	DIO_VoidSetPinDirection(COM4_PORT,COM4_PIN,SEVSEG_OUTPUT);

	/* Set the Values of Common pins with the seven segment selection */
#if SEVSEG_SELECT == SEVSEG_NO_1
	DIO_VoidSetPinVal(COM1_PORT,COM1_PIN,SEVSEG_LOW);
	DIO_VoidSetPinVal(COM2_PORT,COM2_PIN,SEVSEG_HIGH);
	DIO_VoidSetPinVal(COM3_PORT,COM3_PIN,SEVSEG_HIGH);
	DIO_VoidSetPinVal(COM4_PORT,COM4_PIN,SEVSEG_HIGH);

#elif SEVSEG_SELECT == SEVSEG_NO_2
	DIO_VoidSetPinVal(COM1_PORT,COM1_PIN,SEVSEG_HIGH);
	DIO_VoidSetPinVal(COM2_PORT,COM2_PIN,SEVSEG_LOW);
	DIO_VoidSetPinVal(COM3_PORT,COM3_PIN,SEVSEG_HIGH);
	DIO_VoidSetPinVal(COM4_PORT,COM4_PIN,SEVSEG_HIGH);

#elif SEVSEG_SELECT == SEVSEG_NO_3
	DIO_VoidSetPinVal(COM1_PORT,COM1_PIN,SEVSEG_HIGH);
	DIO_VoidSetPinVal(COM2_PORT,COM2_PIN,SEVSEG_HIGH);
	DIO_VoidSetPinVal(COM3_PORT,COM3_PIN,SEVSEG_LOW);
	DIO_VoidSetPinVal(COM4_PORT,COM4_PIN,SEVSEG_HIGH);

#elif SEVSEG_SELECT == SEVSEG_NO_4
	DIO_VoidSetPinVal(COM1_PORT,COM1_PIN,SEVSEG_HIGH);
	DIO_VoidSetPinVal(COM2_PORT,COM2_PIN,SEVSEG_HIGH);
	DIO_VoidSetPinVal(COM3_PORT,COM3_PIN,SEVSEG_HIGH);
	DIO_VoidSetPinVal(COM4_PORT,COM4_PIN,SEVSEG_LOW);
#endif
}
void SEVSEG_VoidDisplayNo(u8 Local_Number)
{
	if (Local_Number <= SEVSEG_NINE && Local_Number >= SEVSEG_ZERO)
	{
		DIO_VoidSetPinVal(BCD_A_PORT,BCD_A_PIN, GET_BIT(Local_Number,0));
		DIO_VoidSetPinVal(BCD_B_PORT,BCD_B_PIN, GET_BIT(Local_Number,1));
		DIO_VoidSetPinVal(BCD_C_PORT,BCD_C_PIN, GET_BIT(Local_Number,2));
		DIO_VoidSetPinVal(BCD_D_PORT,BCD_D_PIN, GET_BIT(Local_Number,3));
	}
}
void SEVSEG_VoidDisplayRange(u8 Local_Start, u8 Local_End)
{
	if(Local_Start <= Local_End && Local_Start >= SEVSEG_ZERO && Local_End <= SEVSEG_NINE)
	{
		u8 Local_counter = 0;
		for (Local_counter = Local_Start; Local_counter <= Local_End ; Local_counter++)
		{
			SEVSEG_VoidDisplayNo(Local_counter);
			_delay_ms(1000);
		}
	}
}
void SEVSEG_VoidClear(void)
{
	SEVSEG_VoidDisplayNo(0);
}
