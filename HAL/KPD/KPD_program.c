/*
 ============================================================================
 Name        : KPD_program.c
 Author      : Manar Hashem
 Date		 : Oct 22, 2023
 Version     : 1.0
 Description : KPD_program source file
 ============================================================================
 */

#include <util/delay.h>

#include "../../LIB/Bit_math.h"
#include "../../LIB/STD_types.h"

#include "../../MCAL/DIO/DIO_interface.h"

#include "KPD_interface.h"

u8 KPD_Values[ROW][Column] = KPD_ConfValues;
void KPD_VoidInit(void)
{
	/*set Row as Output*/
	DIO_VoidSetPinDirection(KPD_RowGroup,KPD_Row1,DIO_OUTPUT);
	DIO_VoidSetPinDirection(KPD_RowGroup,KPD_Row2,DIO_OUTPUT);
	DIO_VoidSetPinDirection(KPD_RowGroup,KPD_Row3,DIO_OUTPUT);
	DIO_VoidSetPinDirection(KPD_RowGroup,KPD_Row4,DIO_OUTPUT);

	/*set Row as High*/
	DIO_VoidSetPinVal(KPD_ColumnGroup,KPD_Column1,DIO_HIGH);
	DIO_VoidSetPinVal(KPD_ColumnGroup,KPD_Column2,DIO_HIGH);
	DIO_VoidSetPinVal(KPD_ColumnGroup,KPD_Column3,DIO_HIGH);
	DIO_VoidSetPinVal(KPD_ColumnGroup,KPD_Column4,DIO_HIGH);

	/*set Column as input*/
	DIO_VoidSetPinDirection(KPD_ColumnGroup,KPD_Column1,DIO_INPUT);
	DIO_VoidSetPinDirection(KPD_ColumnGroup,KPD_Column2,DIO_INPUT);
	DIO_VoidSetPinDirection(KPD_ColumnGroup,KPD_Column3,DIO_INPUT);
	DIO_VoidSetPinDirection(KPD_ColumnGroup,KPD_Column4,DIO_INPUT);

	/*set Column pin pull up*/
	DIO_VoidSetPinVal(KPD_ColumnGroup,KPD_Column1,DIO_HIGH);
	DIO_VoidSetPinVal(KPD_ColumnGroup,KPD_Column2,DIO_HIGH);
	DIO_VoidSetPinVal(KPD_ColumnGroup,KPD_Column3,DIO_HIGH);
	DIO_VoidSetPinVal(KPD_ColumnGroup,KPD_Column4,DIO_HIGH);

}

u8 KPD_u8ReadButton(void)
{
	/*Create a u8 variable to for the return value and initialize it to NotFound*/
	u8 Local_Return = 255;

	/*Create 2 counters for looping*/
	u8 Local_ColCounter		= 0;
	u8 Local_RowCounter		= 0;

	u8 local_u8Flag = 0;

	/*Create 2 arrays of the pins of ROWs and Columns */
	u8 Local_u8RowPinArr[ROW] = {KPD_Row1, KPD_Row2, KPD_Row3, KPD_Row4};
	u8 Local_u8ColumnPinArr[Column] = {KPD_Column1, KPD_Column2, KPD_Column3, KPD_Column4};


	/*Loop to Get the Pressed Button*/
	for (Local_RowCounter = ROWStart ; Local_RowCounter <= ROWEnd ; Local_RowCounter++)
	{
		/*set the Row as low (GND) --> Activate*/
		DIO_VoidSetPinVal(KPD_RowGroup, Local_u8RowPinArr[Local_RowCounter], DIO_LOW);

		/*Loop to read the Rows*/
		for(Local_ColCounter = ColumnStart; Local_ColCounter <= ColumnEnd; Local_ColCounter++)
		{
			u8 Local_PinState = DIO_u8GetPinVal(KPD_ColumnGroup, Local_u8ColumnPinArr[Local_ColCounter]);

			/*Check if the Key is Pressed*/
			if(Local_PinState == 0)
			{
				//Debouncing delay
				_delay_ms(250);

				/*Pulling until the button is released*/
				while (DIO_u8GetPinVal(KPD_ColumnGroup, Local_u8ColumnPinArr[Local_ColCounter]) == 0);

				local_u8Flag = 1;

				Local_Return = KPD_Values[Local_RowCounter][Local_ColCounter];

				break;
			}
		}
		DIO_VoidSetPinVal(KPD_RowGroup, Local_u8RowPinArr[Local_RowCounter], DIO_HIGH);
		if (local_u8Flag == 1)
		{
			break;
		}
	}
	return Local_Return;
}
