/*
 ============================================================================
 Name		 : EXTI_program.c
 Author		 : Manar Hashem
 Date		 : Oct 23, 2023
 Version	 : 1.0
 Description : EXTI_program Source file
 ============================================================================
*/
#include "../../LIB/STD_types.h"
#include "../../LIB/Bit_math.h"

#include "../DIO/DIO_interface.h"

#include "EXTI_Interface.h"


static void (*GPTF[3])(void);

void EXTI0_VoidInit(void)
{
	/*Set INT0 pin to input and enable the internal Pull up*/
	DIO_VoidSetPinDirection(EXTI0_PORT,EXTI0_PIN,DIO_INPUT);
	DIO_VoidSetPinVal(EXTI0_PORT, EXTI0_PIN, DIO_HIGH);
	/*set INT0 bit in GICR --> enable external interrupt of pin 0*/
	SET_BIT(EXTI_GICR, EXTI_INT0);
	/*Check for the Trigger mode*/
#if EXTI0_TriggerMode == EXTI_LowLevel
	CLR_BIT(EXTI_MCUCR, EXTI_ISC00);
	CLR_BIT(EXTI_MCUCR, EXTI_ISC01);

#elif EXTI0_TriggerMode == EXTI_OnChangeEdge
	CLR_BIT(EXTI_MCUCR, EXTI_ISC00);
	CLR_BIT(EXTI_MCUCR, EXTI_ISC01);

#elif EXTI0_TriggerMode == EXTI_FallingEdge
	CLR_BIT(EXTI_MCUCR, EXTI_ISC00);
	SET_BIT(EXTI_MCUCR, EXTI_ISC01);

#elif EXTI0_TriggerMode == EXTI_RisingEdge
	SET_BIT(EXTI_MCUCR, EXTI_ISC00);
	SET_BIT(EXTI_MCUCR, EXTI_ISC01);
#endif
}

void EXTI1_VoidInit(void)
{
	/*Set INT1 pin to input and enable the internal Pull up*/
	DIO_VoidSetPinDirection(EXTI1_PORT,EXTI1_PIN,DIO_INPUT);
	DIO_VoidSetPinVal(EXTI1_PORT, EXTI1_PIN, DIO_HIGH);
	/*set INT1 bit in GICR --> enable external interrupt of pin 1*/
	SET_BIT(EXTI_GICR, EXTI_INT1);

#if EXTI1_TriggerMode == EXTI_LowLevel
	CLR_BIT(EXTI_MCUCR, EXTI_ISC10);
	CLR_BIT(EXTI_MCUCR, EXTI_ISC11);
#elif EXTI1_TriggerMode == EXTI_OnChangeEdge
	SET_BIT(EXTI_MCUCR, EXTI_ISC10);
	CLR_BIT(EXTI_MCUCR, EXTI_ISC11);
#elif EXTI1_TriggerMode == EXTI_FallingEdge
	CLR_BIT(EXTI_MCUCR, EXTI_ISC10);
	SET_BIT(EXTI_MCUCR, EXTI_ISC11);
#elif EXTI1_TriggerMode == EXTI_RisingEdge
	SET_BIT(EXTI_MCUCR, EXTI_ISC10);
	SET_BIT(EXTI_MCUCR, EXTI_ISC11);
#endif
}

void EXTI2_VoidInit(void)
{
	/*Set INT1 pin to input and enable the internal Pull up*/
	DIO_VoidSetPinDirection(EXTI2_PORT,EXTI2_PIN,DIO_INPUT);
	DIO_VoidSetPinVal(EXTI1_PORT, EXTI2_PIN, DIO_HIGH);
	/*set INT1 bit in GICR --> enable external interrupt of pin 1*/
	SET_BIT(EXTI_GICR, EXTI_INT2);

#if EXTI2_TriggerMode == EXTI_FallingEdge
	CLR_BIT(EXTI_MCUCR, EXTI_ISC2);
#elif EXTI2_TriggerMode == EXTI_RisingEdge
	SET_BIT(EXTI_MCUCR, EXTI_ISC2);
#endif
}

void EXT_VoidInit(u8 Local_INT_number, u8 Local_ControlState)
{
	switch(Local_INT_number)
	{
	case EXTI_INT0:
		/*Set INT0 pin to input and enable the internal Pull up*/
		DIO_VoidSetPinDirection(EXTI0_PORT,EXTI0_PIN,DIO_INPUT);
		DIO_VoidSetPinVal(EXTI0_PORT, EXTI0_PIN, DIO_HIGH);
		/*set INT0 bit in GICR --> enable external interrupt of pin 0*/
		SET_BIT(EXTI_GICR, EXTI_INT0);
		EXT_VoidSetSenceControl(Local_INT_number,Local_ControlState);
		break;
	case EXTI_INT1:
		/*Set INT1 pin to input and enable the internal Pull up*/
		DIO_VoidSetPinDirection(EXTI1_PORT,EXTI1_PIN,DIO_INPUT);
		DIO_VoidSetPinVal(EXTI1_PORT, EXTI1_PIN, DIO_HIGH);
		/*set INT1 bit in GICR --> enable external interrupt of pin 1*/
		SET_BIT(EXTI_GICR, EXTI_INT1);
		EXT_VoidSetSenceControl(Local_INT_number,Local_ControlState);
		break;
	case EXTI_INT2:
		/*Set INT1 pin to input and enable the internal Pull up*/
		DIO_VoidSetPinDirection(EXTI2_PORT,EXTI2_PIN,DIO_INPUT);
		DIO_VoidSetPinVal(EXTI1_PORT, EXTI2_PIN, DIO_HIGH);
		/*set INT1 bit in GICR --> enable external interrupt of pin 1*/
		SET_BIT(EXTI_GICR, EXTI_INT2);
		EXT_VoidSetSenceControl(Local_INT_number,Local_ControlState);
		break;

	}
}

void EXT_VoidSetSenceControl(u8 Local_INT_number, u8 Local_ControlState)
{
	switch(Local_INT_number)
	{
	case EXTI_INT0:

		if(EXTI0_TriggerMode == EXTI_LowLevel)
		{
			CLR_BIT(EXTI_MCUCR, EXTI_ISC00);
			CLR_BIT(EXTI_MCUCR, EXTI_ISC01);
		}
		else if(EXTI0_TriggerMode == EXTI_OnChangeEdge)
		{
			SET_BIT(EXTI_MCUCR, EXTI_ISC00);
			CLR_BIT(EXTI_MCUCR, EXTI_ISC01);
		}
		else if(EXTI0_TriggerMode == EXTI_FallingEdge)
		{
			CLR_BIT(EXTI_MCUCR, EXTI_ISC00);
			SET_BIT(EXTI_MCUCR, EXTI_ISC01);
		}
		else if(EXTI0_TriggerMode == EXTI_RisingEdge)
		{
			SET_BIT(EXTI_MCUCR, EXTI_ISC00);
			SET_BIT(EXTI_MCUCR, EXTI_ISC01);
		}
		break;

	case EXTI_INT1:
		if(EXTI0_TriggerMode == EXTI_LowLevel)
		{
			CLR_BIT(EXTI_MCUCR, EXTI_ISC10);
			CLR_BIT(EXTI_MCUCR, EXTI_ISC11);
		}
		else if(EXTI0_TriggerMode == EXTI_OnChangeEdge)
		{
			SET_BIT(EXTI_MCUCR, EXTI_ISC10);
			CLR_BIT(EXTI_MCUCR, EXTI_ISC11);
		}

		else if(EXTI0_TriggerMode == EXTI_FallingEdge)
		{
			CLR_BIT(EXTI_MCUCR, EXTI_ISC10);
			SET_BIT(EXTI_MCUCR, EXTI_ISC11);
		}

		else if(EXTI0_TriggerMode == EXTI_RisingEdge)
		{
			SET_BIT(EXTI_MCUCR, EXTI_ISC10);
			SET_BIT(EXTI_MCUCR, EXTI_ISC11);
		}
		break;

	case EXTI_INT2:
		if(EXTI2_TriggerMode == EXTI_FallingEdge)
		{
			CLR_BIT(EXTI_MCUCR, EXTI_ISC2);
		}
		else if(EXTI2_TriggerMode == EXTI_RisingEdge)
		{
			SET_BIT(EXTI_MCUCR, EXTI_ISC2);
		}
		break;
	}
}

void EXT0_CallBackFunction(void(*PTF)(void))
{
	GPTF[0] = PTF;
}
void EXT1_CallBackFunction(void(*PTF)(void))
{
	GPTF[1] = PTF;
}
void EXT2_CallBackFunction(void(*PTF)(void))
{
	GPTF[2] = PTF;
}
void __vector_1(void)
{
	GPTF[0]();
}
void __vector_2(void)
{
	GPTF[1]();
}
void __vector_3(void)
{
	GPTF[2]();
}

