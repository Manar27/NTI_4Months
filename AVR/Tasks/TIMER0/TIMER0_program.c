/*
 ============================================================================
 Name		 : TIMER0_program.c
 Author		 : Manar Hashem
 Date		 : Oct 27, 2023
 Version	 : 1.0
 Description : TIMER0_program Source file
 ============================================================================
 */

#include "../../LIB/Bit_math.h"
#include "../../LIB/STD_types.h"

#include "TIMER0_interface.h"

void TIMER0_VoidInit(void)
{
#if TIMER_MODE == Normal_MODE
	TIMER0_TCCR0->WGM01 = 0;
	TIMER0_TCCR0->WGM00 = 0;
#elif TIMER_MODE == PWM__PHASE_CORRECT_MODE
	TIMER0_TCCR0->WGM01 = 0;
	TIMER0_TCCR0->WGM00 = 1;
#elif TIMER_MODE == CTC_MODE
	TIMER0_TCCR0->WGM01 = 1;
	TIMER0_TCCR0->WGM00 = 0;
#elif TIMER_MODE == FAST_PWM__MODE
	TIMER0_TCCR0->WGM01 = 1;
	TIMER0_TCCR0->WGM00 = 1;
#else
	//return Error
#endif

}

