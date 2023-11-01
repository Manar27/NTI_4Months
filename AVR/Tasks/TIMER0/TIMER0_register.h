/*
 ============================================================================
 Name		 : TIMER0_register.h
 Author		 : Manar Hashem
 Date		 : Oct 27, 2023
 Version	 : 1.0
 Description : TIMER0_register header file
 ============================================================================
*/

#ifndef MCAL_TIMER0_TIMER0_REGISTER_H_
#define MCAL_TIMER0_TIMER0_REGISTER_H_

typedef struct
{
	u8 CS0 		: 3;
	u8 WGM01 	: 1;
	u8 COM0		: 2;
	u8 WGM00	: 1;
	u8 FOC0		: 1;
}TCCR0;
#define TIMER0_TCCR0		((volatile TCCR0 *)0x53)

/*******************************************************/
typedef struct
{
	u8 OCIE0	: 1;
	u8 TOIE0	: 1;
	u8			: 6;

}TIMSK;
#define TIMER0_TIMSK		((volatile TIMSK *)0x59)

/*******************************************************/
typedef struct
{
	u8 TOV0		: 1;
	u8 OCF0		: 1;
	u8			: 6;

}TIFR;
#define TIMER0_TIFR			((volatile TIFR *)0x58)

/*******************************************************/
#define TIMER0_TCNT0		*((volatile u8 *)0x52)
#define TIMER0_OCR0			*((volatile u8 *)0x5C)


#endif /* MCAL_TIMER0_TIMER0_REGISTER_H_ */
