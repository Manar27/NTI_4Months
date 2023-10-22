/*
 ============================================================================
 Name        : STD_types.h
 Author      : Manar Hashem
 Date		 : Oct 15, 2023
 Version     : 2.0
 Description : STD_types LIB
 ============================================================================
*/

#ifndef COMMON_TYPEDEF_H_
#define COMMON_TYPEDEF_H_

/*
	u --> unsigned
	s --> signed	
*/
 
/*char*/
typedef unsigned char 			u8; 		// 1 byte = 8 bits
typedef signed char 			s8; 		// 1 byte = 8 bits

/*int*/
typedef unsigned short int 		u16; 		// 2 bytes = 16 bits
typedef signed short int 		s16; 		// 2 bytes = 16 bits
typedef unsigned long int 		u32; 		// 4 bytes = 32 bits
typedef signed long int 		s32; 		// 4 bytes = 32 bits
typedef unsigned long long int	u64;
typedef signed long long int	s64;

/*float*/
typedef float 					f32;

/*double*/
typedef double 					f64;
typedef long double 			f128;

#define NULL		((void*)0x00)
#endif /* COMMON_TYPEDEF_H_ */
