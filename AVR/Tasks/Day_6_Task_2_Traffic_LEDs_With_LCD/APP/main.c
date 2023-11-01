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
#include "../HAL/LCD/LCD_interface.h"

#define STOP_NUM		20
/*Task 2---------Traffic LEDs*/
int main(void)
{
	LCD_Void4BitsInit();
	/*Select the Direction of the 3 Pins connected to LEDs to Output*/
	DIO_VoidSetPinDirection(PORT_A,PIN_6,DIO_OUTPUT); //Yellow
	DIO_VoidSetPinDirection(PORT_A,PIN_4,DIO_OUTPUT); //Green
	DIO_VoidSetPinDirection(PORT_B,PIN_7,DIO_OUTPUT); //Red

	/*Local_Counter is counter to make the 2 Digit number appear for a specific time*/
	u8 Local_Counter = 0;
	/*Digit_0 is the Ones of a two digit number*/
	u8 Digit_0 = 0;
	/*Digit_1 is the Ones of a two digit number*/
	u8 Digit_1 = 0;
	/*Traffic_Flay is that the Traffic LEDs is changing corresponding to*/
	u8 Traffic_Flag = 0;
	while (1)
	{
		Digit_0 = 0;
		Digit_1 = 0;

		Traffic_Flag++;
		/*Turn on LED 1 -> RED and Turn off all others*/
		if(Traffic_Flag == 1)
		{
			DIO_VoidSetPinVal(PORT_B,PIN_7,DIO_HIGH); 	//Red
			DIO_VoidSetPinVal(PORT_A,PIN_6,DIO_LOW); 	//Yellow
			DIO_VoidSetPinVal(PORT_A,PIN_4,DIO_LOW); 	//Green
		}

		/*Turn on LED 2 -> YELLOW and Turn off all others*/
		else if(Traffic_Flag == 2)
		{
			DIO_VoidSetPinVal(PORT_B,PIN_7,DIO_LOW); 	//Red
			DIO_VoidSetPinVal(PORT_A,PIN_6,DIO_HIGH); 	//Yellow
			DIO_VoidSetPinVal(PORT_A,PIN_4,DIO_LOW); 	//Green
		}

		/*Turn on LED 3 -> GREEN and Turn off all others*/
		else if(Traffic_Flag == 3)
		{
			/*make Traffic Flag = 0 again to loop again*/
			Traffic_Flag = 0;
			DIO_VoidSetPinVal(PORT_B,PIN_7,DIO_LOW); 	//Red
			DIO_VoidSetPinVal(PORT_A,PIN_6,DIO_LOW); 	//Yellow
			DIO_VoidSetPinVal(PORT_A,PIN_4,DIO_HIGH);	 //Green
		}
		/*Display the counter from 0 to 20 on 2 digit multiplexed Seven Segment with Decoder*/
		/*Break event is when the Number = stop number (20)*/
		/*Number = Digit_0 + (Digit_1 * 10) -> Example:  4 + (1*10) = 14*/
		while((Digit_0 + (Digit_1 * 10)) <= STOP_NUM)
		{
			/*increment Digit_1 (tens) when Digit_0 is more than 9 and Digit_0 = 0 again*/
			if(Digit_0 > 9)
			{
				Digit_1++;
				Digit_0 = 0;
			}



			/*Call the initialization function for Seven segment 1*/
			SSD_VoidInit(SSD_NO_3);
			/*Display the ones Number (Digit_0) on 7 segment 1*/
			SSD_VoidDisplayNo(Digit_0);
			/*Delay for visibility*/
			_delay_ms(10);

			/*Call the initialization function for Seven segment 2*/
			SSD_VoidInit(SSD_NO_4);
			/*Display the tens Number (Digit_1) on 7 segment 2*/
			SSD_VoidDisplayNo(Digit_1);
			/*Delay for visibility*/
			_delay_ms(10);


			/*Increment Counter to make the Whole number appear for approx. 1 second*/
			Local_Counter++;
			if(Local_Counter == 20)
			{
				LCD_VoidSendCommand(DISPLAY_CLEAR);
				_delay_ms(10);
				LCD_VoidSendData((char)Digit_1 +'0');
				LCD_VoidSendData((char)Digit_0 +'0');
				_delay_ms(50);

				Local_Counter = 0;
				/*After the approximate time (1sec), Increment Digit_0 to loop*/
				Digit_0++;
				_delay_ms(10);
			}
		}
	}

}

