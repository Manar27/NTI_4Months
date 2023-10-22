/*
 ============================================================================
 Name        : main.c
 Author      : Manar Hashem
 Version     : 1.00V
 Description : Display 1 Digit Number on Seven Segment and its binary
 	 	 	   Format on 4 LEDs
 ============================================================================
 */

#define F_CPU	8000000UL
#include <util/delay.h>

#include "../LIB/STD_types.h"
#include "../LIB/Bit_math.h"

#include "../MCAL/DIO/DIO_interface.h"
#include "../HAL/SSD/SSD_interface.h"

void main(void)
{
	/*Select the Direction of the 4 Pins connected to LEDs to Output*/
	DIO_VoidSetPinDirection(PORT_A,PIN_6,DIO_OUTPUT); //yellow
	DIO_VoidSetPinDirection(PORT_A,PIN_5,DIO_OUTPUT); //blue
	DIO_VoidSetPinDirection(PORT_A,PIN_4,DIO_OUTPUT); //green
	DIO_VoidSetPinDirection(PORT_B,PIN_7,DIO_OUTPUT); //red

	/*Call the initialization function of seven segment no. 1*/
	SSD_VoidInit(SSD_NO_1);

	while (1)
	{
		/*Loop from 0 to 9 to display each decimal number and its corresponding Binary*/
		for(u8 i = 0; i <= 9; i++)
		{
			/*Call the Display Number function of i */
			SSD_VoidDisplayNo(i);
			/*Divide the number into its binary format and set the value of the LEDs*/
			DIO_VoidSetPinVal(PORT_B, PIN_7, GET_BIT(i,0));
			DIO_VoidSetPinVal(PORT_A, PIN_4, GET_BIT(i,1));
			DIO_VoidSetPinVal(PORT_A, PIN_5, GET_BIT(i,2));
			DIO_VoidSetPinVal(PORT_A, PIN_6, GET_BIT(i,3));
			/*Delay for visibility*/
			_delay_ms(1000);
		}
	}
}
