/*
 ============================================================================
 Name		 : DIO_register.h
 Author		 : Manar Hashem
 Date		 : Oct 20, 2023
 Version	 : 2.0 (Struct Configuration)
 Description : DIO_register header file
 ============================================================================
*/

#ifndef DIO_REGISTER_H_
#define DIO_REGISTER_H_

typedef union
{
	struct
	{
		u8 Bit0 	: 1;
		u8 Bit1 	: 1;
		u8 Bit2 	: 1;
		u8 Bit3 	: 1;
		u8 Bit4 	: 1;
		u8 Bit5 	: 1;
		u8 Bit6 	: 1;
		u8 Bit7 	: 1;
	}Bit;
	u8 Byte;
}DDR_t;

/*******************************************************/

#define DIO_DDRA			((volatile DDR_t *)0x3A)
#define DIO_DDRB			((volatile DDR_t *)0x37)
#define DIO_DDRC			((volatile DDR_t *)0x34)
#define DIO_DDRD			((volatile DDR_t *)0x31)

/*******************************************************/
typedef union
{
	struct
	{
		u8 Bit0 	: 1;
		u8 Bit1 	: 1;
		u8 Bit2 	: 1;
		u8 Bit3 	: 1;
		u8 Bit4 	: 1;
		u8 Bit5 	: 1;
		u8 Bit6 	: 1;
		u8 Bit7 	: 1;
	}Bit;
	u8 Byte;
}PORT_t;

/*******************************************************/

#define DIO_PORTA			((volatile PORT_t *)0x3B)
#define DIO_PORTB			((volatile PORT_t *)0x38)
#define DIO_PORTC			((volatile PORT_t *)0x35)
#define DIO_PORTD			((volatile PORT_t *)0x32)

/*******************************************************/
typedef union
{
	struct
	{
		u8 Bit0 	: 1;
		u8 Bit1 	: 1;
		u8 Bit2 	: 1;
		u8 Bit3 	: 1;
		u8 Bit4 	: 1;
		u8 Bit5 	: 1;
		u8 Bit6 	: 1;
		u8 Bit7 	: 1;
	}Bit;
	u8 Byte;
}PIN_t;

/*******************************************************/

#define DIO_PINA			((volatile PIN_t *)0x39)
#define DIO_PINB			((volatile PIN_t *)0x36)
#define DIO_PINC			((volatile PIN_t *)0x33)
#define DIO_PIND			((volatile PIN_t *)0x30)

#endif /* DIO_REGISTER_H_ */
