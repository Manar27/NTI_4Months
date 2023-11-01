/*
 ============================================================================
 Name		 : TIMER0_private.h
 Author		 : Manar Hashem
 Date		 : Oct 27, 2023
 Version	 : 1.0
 Description : TIMER0_private header file
 ============================================================================
*/
#ifndef MCAL_TIMER0_TIMER0_PRIVATE_H_
#define MCAL_TIMER0_TIMER0_PRIVATE_H_

/*******************************************************/
typedef enum
{
	NO_CLOCK	 			= 0b000,
	NO_PRESCALER			= 0b001,
	PRESCALER_8				= 0b010,
	PRESCALER_64			= 0b011,
	PRESCALER_265			= 0b100,
	PRESCALER_1024			= 0b101,
	EXT_CLK_SRC_FALING_EDGE = 0b110,
	EXT_CLK_SRC_RISING_EDGE = 0b111
}PRESCALER_SELECT;

/*******************************************************/

/* Bits WGM01 WGM00 at Reg TCCR0*/

typedef enum
{
	Normal_MODE 					= 0b000,
	PWM__PHASE_CORRECT_MODE			= 0b001,
	CTC_MODE						= 0b010,
	FAST_PWM__MODE					= 0b011
}TIMER_MODE_SELECT;

/*******************************************************/

#endif /* MCAL_TIMER0_TIMER0_PRIVATE_H_ */
