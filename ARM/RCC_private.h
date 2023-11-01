/*
 ============================================================================
 Name		 : RCC_private.h
 Author		 : Manar Hashem
 Date		 : Oct 31, 2023
 Version	 : 1.0
 Description : RCC_private header file
 ============================================================================
 */

#ifndef MCAL_RCC_RCC_PRIVATE_H_
#define MCAL_RCC_RCC_PRIVATE_H_

/* Clock Types */
#define RCC_HSE_CRYSTAL 			0
#define RCC_HSE_RC      			1
#define RCC_HSI         			2
#define RCC_PLL         			3

/* PLL Options */
#define RCC_PLL_HSI 	 			100
#define RCC_PLL_HSE		 			200
#define RCC_PLL_HSE_1		 		210
#define RCC_PLL_HSE_2		 		110

/* System Clock Selection */
#define RCC_SW_HSI_SELECTION		0b00
#define RCC_SW_HSE_SELECTION		0b01
#define RCC_SW_PLL_SELECTION		0b10

/* PLL Multiplication */
#define RCC_PLL_MUL_2       		0b0000
#define RCC_PLL_MUL_3       		0b0001
#define RCC_PLL_MUL_4       		0b0010
#define RCC_PLL_MUL_5       		0b0011
#define RCC_PLL_MUL_6       		0b0100
#define RCC_PLL_MUL_7       		0b0101
#define RCC_PLL_MUL_8       		0b0110
#define RCC_PLL_MUL_9       		0b0111
#define RCC_PLL_MUL_10      		0b1000
#define RCC_PLL_MUL_11      		0b1001
#define RCC_PLL_MUL_12      		0b1010
#define RCC_PLL_MUL_13      		0b1011
#define RCC_PLL_MUL_14      		0b1100
#define RCC_PLL_MUL_15      		0b1101
#define RCC_PLL_MUL_16_1    		0b1110
#define RCC_PLL_MUL_16_2    		0b1111

/* AHB Range */
#define AHB_START		10
#define AHB_END			20

/* APB2 Range */
#define APB2_START		30
#define APB2_END		51

/* APB1 Range */
#define APB1_START		70
#define APB1_END		99

#endif /*MCAL_RCC_RCC_PRIVATE_H_*/
