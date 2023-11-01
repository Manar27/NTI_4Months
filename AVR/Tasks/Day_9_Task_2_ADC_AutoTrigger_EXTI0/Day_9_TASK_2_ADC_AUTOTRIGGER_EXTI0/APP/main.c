/*
 ============================================================================
 Name        : main.c
 Author      : Manar Hashem
 Version     : 1.00V
 Description : Read Temp from LM35 using ADC auto triggered with EXT0
 ============================================================================
 */

#define F_CPU	8000000UL

#include <util/delay.h>

/**********************************************************************/

#include "../LIB/STD_types.h"
#include "../LIB/Bit_math.h"

/**********************************************************************/

#include "../HAL/LCD/LCD_interface.h"
#include "../MCAL/EXTI/EXTI_interface.h"
#include "../MCAL/GIE/GIE_interface.h"
#include "../MCAL/ADC/ADC_interface.h"

/**********************************************************************/

volatile u8 Flag1 = 0;
volatile u8 Flag2 = 0;

/********** Function to raise a Flag1 when EXT0 ISR occurs ***********/
void Fun1 (void)
{
	Flag1 = 1;
}

/********** Function to raise a Flag2 when ADC ISR occurs ************/

void Fun2 (void)
{
	Flag2 = 1;
}

/**********************************************************************/

void main(void)
{
	u16 ADC_Data;
	LCD_Void4BitsInit();

	/* Initialize EXT0 that will auto trigger ADC to start Conversion  */
	EXT0_CallBackFunction(Fun1);
	EXTI0_VoidInit();

	/* Initialize ADC at Channel 0 with AutoTrigger Source = EXT_NO_0 */
	ADC_voidChannelSelect(CHANNEL_0);
	ADC_voidInit();
	ADC_voidSetCallBack(&ADC_Data,Fun2);

	/* Enable Global Interrupt */
	GIE_VoidEnable();

	while(1)
	{
		/* Check if Flag 1 is raised -> if Flag1 = 1, EXT0 ISR occurred  */
		if(Flag1 == 1)
		{
			Flag1 = 0;

			/* Display the Temperature on LCD with indicator to Fun 1 */
			LCD_VoidStartFrom(0,0);
			LCD_VoidSendString("Fun 1 ");
			f32 celsius = ADC_Data * 4.88;
			celsius = (celsius / 10);
			HLCD_voidDisplayNumber(celsius);
			LCD_VoidSendString(" C");

			_delay_ms(1000);
		}

		/* Check if Flag 2 is raised -> if Flag2 = 1, ADC ISR occurred means
		 * that EXT0 ISR occurs and triggered ADC and ADC conversion complete */
		if(Flag2 == 1)
		{
			Flag2 = 0;

			/* Display the Temperature on LCD with indicator to Fun 2 */
			LCD_VoidStartFrom(0,0);
			LCD_VoidSendString("Fun 2 ");
			f32 celsius = ADC_Data * 4.88;
			celsius = (celsius / 10);
			HLCD_voidDisplayNumber(celsius);
			LCD_VoidSendString(" C");

			_delay_ms(1000);
		}
	}
}
