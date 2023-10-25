/*
 ============================================================================
 Name        : Bit_math.h
 Author      : Manar Hashem
 Date		 : Oct 15, 2023
 Version     : 2.0
 Description : Bit_math LIB
 ============================================================================
*/

#ifndef COMMON_BITMATH_H_
#define COMMON_BITMATH_H_

#define SET_BIT(REG,BIT_NO)		(REG |= (1 << BIT_NO))

#define CLR_BIT(REG,BIT_NO)		(REG &= ~(1 << BIT_NO))

#define TOG_BIT(REG,BIT_NO)		(REG ^= (1 << BIT_NO))

#define GET_BIT(REG,BIT_NO)		(REG >> BIT_NO) & 1

#define CONC_BYTE(b0,b1,b2,b3,b4,b5,b6,b7)	(0b##b7##b6##b5##b4##b3##b2##b1##b0)

#define SET_BYTE(REG,VAL)	(REG = VAL)

#define MASK(REG,MASK_VAL)	(REG &= MASK_VAL)

#define GET_MSB(REG,No_Bits)	(REG >> No_Bits)

#define BIT_0		(u8)0x00
#define BIT_1		(u8)0x01
#define BIT_2		(u8)0x02
#define BIT_3		(u8)0x03
#define BIT_4		(u8)0x04
#define BIT_5		(u8)0x05
#define BIT_6		(u8)0x06
#define BIT_7		(u8)0x07

#endif /* COMMON_BITMATH_H_ */
