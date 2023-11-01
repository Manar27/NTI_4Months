/*
 ============================================================================
 Name		 : RCC_config.h
 Author		 : Manar Hashem
 Date		 : Oct 31, 2023
 Version	 : 1.0
 Description : RCC_config header file
 ============================================================================
*/

#ifndef MCAL_RCC_RCC_CONFIG_H_
#define MCAL_RCC_RCC_CONFIG_H_


/* Options:
 * RCC_HSE_CRYSTAL
 * RCC_HSE_RC
 * RCC_HSI
 * RCC_PLL
 * */
#define RCC_CLOCK_TYPE			RCC_PLL

/* Options:
 * RCC_PLL_HSI
 * RCC_PLL_HSE
 * */
#define RCC_PLL_SELECTION		RCC_PLL_HSE

/* Options:
 * RCC_PLL_HSE_1
 * RCC_PLL_HSE_2
 * */
#if RCC_PLL_SELECTION == RCC_PLL_HSE
#define RCC_PLL_HSE_SELECTION	RCC_PLL_HSE_1
#endif

/* Options:
 * RCC_ENABLE
 * RCC_DISABLE
 * */
#define RCC_SECURITY			RCC_ENABLE

/* Options:
 * RCC_PLL_MUL_2
 * RCC_PLL_MUL_3
 * RCC_PLL_MUL_4
 * RCC_PLL_MUL_5
 * RCC_PLL_MUL_6
 * RCC_PLL_MUL_7
 * RCC_PLL_MUL_8
 * RCC_PLL_MUL_9
 * RCC_PLL_MUL_10
 * RCC_PLL_MUL_11
 * RCC_PLL_MUL_12
 * RCC_PLL_MUL_13
 * RCC_PLL_MUL_14
 * RCC_PLL_MUL_15
 * RCC_PLL_MUL_16_1
 * RCC_PLL_MUL_16_2
 */
#define RCC_PLL_MULL		RCC_PLL_MUL_2

#endif /*MCAL_RCC_RCC_CONFIG_H_*/
