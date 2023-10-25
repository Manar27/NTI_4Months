/*
 ============================================================================
 Name		 : ADC_private.h
 Author		 : Manar Hashem
 Date		 : Oct 24, 2023
 Version	 : 1.0
 Description : ADC_private header file
 ============================================================================
*/
#ifndef MCAL_ADC_ADC_PRIVATE_H_
#define MCAL_ADC_ADC_PRIVATE_H_

#define EN					1

/*******************************************************/
typedef enum
{
	AREF 	= 0b00,
	AVCC 	= 0b01,
	AREF_IC = 0b11
}VOLTAGE_SELECT;

/*******************************************************/
typedef enum
{
	PRESCALER_2 		= 0b000,
	PRESCALER_4			= 0b010,
	PRESCALER_8			= 0b011,
	PRESCALER_16		= 0b100,
	PRESCALER_32		= 0b101,
	PRESCALER_64		= 0b110,
	PRESCALER_128		= 0b111
}PRESCALER_SELECT;

/*******************************************************/
typedef enum
{
	FREE_RUNNING 		= 0b000,
	ANALOG_COMPARATOR	= 0b001,
	EXTI_NO_0			= 0b010,
	TIMER_0_CM			= 0b011,
	TIMER_0_OF			= 0b100,
	TIMER_1_CM_B		= 0b101,
	TIMER_1_OF			= 0b110,
	TIMER_1_CE			= 0b111
}TRIGGER_SOURCE_SELECT;

/*******************************************************/
#define RIGHT_DATA		0x00
#define LEFT_DATA		0x01

#endif /* MCAL_ADC_ADC_PRIVATE_H_ */
