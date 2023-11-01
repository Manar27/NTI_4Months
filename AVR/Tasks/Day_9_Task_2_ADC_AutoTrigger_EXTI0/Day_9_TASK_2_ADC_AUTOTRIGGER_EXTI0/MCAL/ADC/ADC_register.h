/*
 ============================================================================
 Name		 : ADC_register.h
 Author		 : Manar Hashem
 Date		 : Oct 24, 2023
 Version	 : 1.0
 Description : ADC_register header file
 ============================================================================
*/

#ifndef MCAL_ADC_ADC_REGISTER_H_
#define MCAL_ADC_ADC_REGISTER_H_

typedef struct
{
	u8 MUX 		: 5;
	u8 ADLAR 	: 1;
	u8 REFS		: 2;
}ADMUX;
#define ADC_ADMUX			((volatile ADMUX *)0x27)

/*******************************************************/
typedef struct
{
	u8 ADPS		: 3;
	u8 ADIE		: 1;
	u8 ADIF		: 1;
	u8 ADATE	: 1;
	u8 ADSC		: 1;
	u8 ADEN		: 1;
}ADCSRA;
#define ADC_ADCSRA			((volatile ADCSRA *)0x26)

/*******************************************************/
typedef struct
{
	u8 			: 5;
	u8 ADTS		: 3;
}SFIOR;
#define ADC_SFIOR			((volatile SFIOR *)0x50)

/*******************************************************/
#define ADC_ADCH			*((volatile u8 *)0x25)
#define ADC_ADCL			*((volatile u8 *)0x24)
#define ADC_DATA			*((volatile u16 *)0x24)


#endif /* MCAL_ADC_ADC_REGISTER_H_ */
