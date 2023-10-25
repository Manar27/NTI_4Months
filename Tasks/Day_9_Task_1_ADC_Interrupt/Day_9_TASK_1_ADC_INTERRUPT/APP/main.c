/*
 ============================================================================
 Name        : main.c
 Author      : Manar Hashem
 Version     : 1.00V
 Description : Read Temp from LM35 using ADC interrupt
 ============================================================================
 */

#define F_CPU	8000000UL

#include <util/delay.h>

/**********************************************************************/

#include "../LIB/STD_types.h"
#include "../LIB/Bit_math.h"

/**********************************************************************/

#include "../HAL/LCD/LCD_interface.h"
#include "../MCAL/ADC/ADC_interface.h"
#include "../MCAL/GIE/GIE_interface.h"

/**********************************************************************/

volatile u8 Flag = 0;

/************* Function to raise a flag when ISR occurs ***************/

void Fun (void)
{
	Flag = 1;
}

/**********************************************************************/

void main(void)
{
	u16 ADC_Data;

	LCD_Void4BitsInit();

	/* Initialize ADC at Channel 0 */
	ADC_voidSetCallBack(&ADC_Data,Fun);
	ADC_voidChannelSelect(CHANNEL_0);
	ADC_voidInit();

	/* Enable Global Interrupt */
	GIE_VoidEnable();

	while(1)
	{
		/* Start ADC Conversion.. When Conversion is complete, ISR occurs */
		ADC_StartConversion();

		/* Check if Flag is raised */
		if(Flag == 1)
		{
			Flag = 0;

			/* Display the Temperature on LCD */
			LCD_VoidStartFrom(0,0);
			LCD_VoidSendString("Temp = ");
			f32 celsius = ADC_Data * 4.88;
			celsius = (celsius / 10);
			HLCD_voidDisplayNumber(celsius);
			LCD_VoidSendString(" C");

			_delay_ms(1000);
		}
	}
}
