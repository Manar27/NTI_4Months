/*
 ============================================================================
 Name        : main.c
 Author      : Manar Hashem
 Version     : 1.00V
 Description : Use the 1st digit of the 7 segment
 ============================================================================
 */

#define F_CPU	12000000UL
#include <util/delay.h>
#include "../LIB/STD_types.h"
#include "../MCAL/DIO/DIO_interface.h"
#include "../HAL/SEVSEG/SEVSEG_interface.h"

int main(void)
{
	SEVSEG_VoidInit();
	SEVSEG_VoidDisplayRange(1,9);
	while (1)
	{
		SEVSEG_VoidClear();
	}
}
