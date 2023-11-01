/*
 ============================================================================
 Name		 : RCC_register.h
 Author		 : Manar Hashem
 Date		 : Oct 31, 2023
 Version	 : 1.0
 Description : RCC_register header file
 ============================================================================
 */

#ifndef MCAL_RCC_RCC_REGISTER_H_
#define MCAL_RCC_RCC_REGISTER_H_

/* Register Definitions */

typedef struct
{
	/* Clock control register */
	volatile u32 CR;

	/* Clock configuration register */
	volatile u32 CFGR;

	/* Clock interrupt register */
	volatile u32 CIR;

	/* APB2 peripheral reset register */
	volatile u32 APB2RSTR;

	/* APB1 peripheral reset register */
	volatile u32 APB1RSTR;

	/* AHB Peripheral Clock enable register */
	volatile u32 AHBENR;

	/* APB2 peripheral clock enable register */
	volatile u32 APB2ENR;

	/* APB1 peripheral clock enable register */
	volatile u32 APB1ENR;

	/* Backup domain control register */
	volatile u32 BDCR;

	/* Control/status register */
	volatile u32 CSR;
}RCC_t;


/* RCC Base Address */
#define RCC			((volatile RCC_t*)0x40021000)

/* Control Register Bits */
#define RCC_CR_HSI				0
#define RCC_HSI_READY			1

#define RCC_CR_HSE		 		16
#define RCC_HSE_READY			17
#define RCC_HSE_BYPASS			18

#define RCC_CR_PLL				24
#define RCC_PLL_READY 			25
#define RCC_SECURITY_SYS_EN		19 //Clock security system enable

/* Clock Configuration Register Bits*/
#define RCC_PLL_SRC				16	// 0 -> HSI , 1 -> HSE and need to configure Bit 17 also
#define RCC_PLL_HSE_DIV			17	// 0 -> HSE , 1 -> HSE / 2

#endif /*MCAL_RCC_RCC_REGISTER_H_*/
