/*
 ============================================================================
 Name        : main.c
 Author      : Manar Hashem
 Version     : 1.00V
 Description : Traffic Light system by counting on 2-Digit 7-seg from 0 to 20
 	 	 	   then change the color
 ============================================================================
 */

#define F_CPU	12000000UL

#include <util/delay.h>

#include "../LIB/STD_types.h"
#include "../LIB/Bit_math.h"

#include "../MCAL/DIO/DIO_interface.h"

#include "../HAL/SSD/SSD_interface.h"

/*Task 2---------Traffic LEDs*/
int main(void)
{
	/*Local_Counter is counter to make the 2 Digit number appear for a specific time*/
	u8 Local_Counter = 0;
	/*Digit_0 is the Ones of a two digit number*/
	u8 Digit_0 = 0;
	/*Digit_1 is the Ones of a two digit number*/
	u8 Digit_1 = 0;

	s8 Digit_2 = 9;
	/*Digit_1 is the Ones of a two digit number*/
	s8 Digit_3 = 9;
	/*Traffic_Flay is that the Traffic LEDs is changing corresponding to*/
	while (1)
	{
		/*Increment Counter to make the Whole number appear for approx. 1 second*/
		if(Local_Counter == 100)
		{
			Local_Counter = 0;
			Digit_0++;
			if(Digit_0 > 9)
			{
				Digit_0 = 0;
				Digit_1++;
				if(Digit_1 > 9)
				{
					Digit_1 = 0;
				}
			}

			Digit_2--;
			if(Digit_2 < 0)
			{
				Digit_2 = 9;
				Digit_3--;
				if(Digit_3 < 0)
				{
					Digit_3 = 9;
				}
			}
		}

		/*Call the initialization function for Seven segment 1*/
		SSD_VoidInit(SSD_NO_1);
		/*Display the ones Number (Digit_0) on 7 segment 1*/
		SSD_VoidDisplayNo(Digit_0);
		/*Delay for visibility*/
		_delay_ms(10);
		Local_Counter++;

		/*Call the initialization function for Seven segment 2*/
		SSD_VoidInit(SSD_NO_2);
		/*Display the tens Number (Digit_1) on 7 segment 2*/
		SSD_VoidDisplayNo(Digit_1);
		/*Delay for visibility*/
		_delay_ms(10);
		Local_Counter++;

		/*Call the initialization function for Seven segment 1*/
		SSD_VoidInit(SSD_NO_3);
		/*Display the ones Number (Digit_0) on 7 segment 1*/
		SSD_VoidDisplayNo(Digit_2);
		/*Delay for visibility*/
		_delay_ms(10);
		Local_Counter++;

		/*Call the initialization function for Seven segment 2*/
		SSD_VoidInit(SSD_NO_4);
		/*Display the tens Number (Digit_1) on 7 segment 2*/
		SSD_VoidDisplayNo(Digit_3);
		/*Delay for visibility*/
		_delay_ms(10);
		Local_Counter++;
	}
}


