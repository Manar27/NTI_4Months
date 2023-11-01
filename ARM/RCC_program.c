/*
 ============================================================================
 Name		 : RCC_program.h
 Author		 : Manar Hashem
 Date		 : Oct 31, 2023
 Version	 : 1.0
 Description : RCC_program source file
 ============================================================================
 */

#include "Bit_math.h"
#include "STD_types.h"

#include "RCC_register.h"
#include "RCC_config.h"
#include "RCC_private.h"
#include "RCC_interface.h"

void RCC_voidInitSysClock (void)
{
/****************** HSI is the System Clock *******************/
#if	RCC_CLOCK_TYPE == RCC_HSI
	SET_BIT(RCC->CR, RCC_CR_HSI);
	while (GET_BIT(RCC->CR, RCC_HSI_READY) == 0);
	RCC->CFGR &= ~(3 >> 0);
	RCC->CFGR |= RCC_SC_HSI_SELECTION;

/***************** HSE RC is the System Clock *****************/
#elif RCC_CLOCK_TYPE == RCC_HSE_RC
	SET_BIT(RCC->CR, RCC_CR_HSE);
	SET_BIT(RCC->CR, RCC_HSE_BYPASS);
	while (GET_BIT(RCC->CR,RCC_HSE_READY) == 0);
	RCC->CFGR &= ~(3 >> 0);
	RCC->CFGR |= RCC_SW_HSE_SELECTION;

/*************** HSE Crystal is the System Clock **************/
#elif RCC_CLOCK_TYPE == RCC_HSE_CRYSTAL
	SET_BIT(RCC->CR, RCC_CR_HSE);
	while (GET_BIT(RCC->CR,RCC_HSE_READY) == 0);
	RCC->CFGR &= ~(3 >> 0);
	RCC->CFGR |= RCC_SW_HSE_SELECTION;

/******************* PLL is the System Clock ******************/
#elif RCC_CLOCK_TYPE == RCC_PLL
	SET_BIT(RCC->CR, RCC_CR_PLL);
	while (GET_BIT(RCC->CR,RCC_PLL_READY) == 0);
	RCC->CFGR &= ~(3 >> 0);
	RCC->CFGR |= RCC_SW_PLL_SELECTION;

/************** Select the multiplication of PLL **************/
	RCC->CFGR &= ~(15 << 18);			//Reset the PLLMUL Bits 18 -> 21 & 0b0000 (~1111)
	RCC->CFGR |= (RCC_PLL_MULL << 18);

/****************** HSI / 2 is the PLL source *****************/
	#if RCC_PLL_SELECTION  == RCC_PLL_HSI
		CLR_BIT(RCC->CFGR, RCC_PLL_SRC);

/******************** HSE is the PLL source *******************/
	#elif RCC_PLL_SELECTION  == RCC_PLL_HSE

/******************** HSE is the PLL source *******************/
		#if RCC_PLL_HSE_SELECTION == RCC_PLL_HSE_1
		CLR_BIT(RCC->CFGR, RCC_PLL_HSE_DIV);

/****************** HSE / 2 is the PLL source *****************/
		#elif RCC_PLL_HSE_SELECTION == RCC_PLL_HSE_2
		SET_BIT(RCC->CFGR, RCC_PLL_HSE_DIV);
		#endif
	#endif
#endif

#if RCC_SECURITY == RCC_ENABLE
	SET_BIT(RCC->CR, RCC_SECURITY_SYS_EN);
#elif RCC_SECURITY == RCC_DISABLE
	CLR_BIT(RCC->CR, RCC_SECURITY_SYS_EN);
#endif
}
void RCC_voidEnableClock (u8 Copy_u8BusId, u8 Copy_u8PeripheralId)
{
	if(Copy_u8PeripheralId <= 31)
	{
		switch (Copy_u8BusId)
		{
		/* AHB Bus */
		case RCC_AHB:
			SET_BIT(RCC->AHBENR , Copy_u8PeripheralId);
			break;
		/* APB1 Bus */
		case RCC_APB1:
			SET_BIT(RCC->APB1ENR , Copy_u8PeripheralId);
			break;
		/* APB2 Bus */
		case RCC_APB2:
			SET_BIT(RCC->APB2ENR , Copy_u8PeripheralId);
			break;

		default:
			/* Return Error */
			break;
		}

	}
	else
	{
		/* Return Error */
	}
}

void RCC_voidEnableClock_2 (u8 Copy_u8PeripheralId)
{
	/* AHB Bus */
	if(Copy_u8PeripheralId <= AHB_END  && Copy_u8PeripheralId >= AHB_START)
	{
		SET_BIT(RCC->AHBENR, (Copy_u8PeripheralId-AHB_START) );
	}
	/* APB1 Bus */
	else if(Copy_u8PeripheralId <= APB1_END  && Copy_u8PeripheralId >= APB1_START)
	{
		SET_BIT(RCC->APB1ENR, (Copy_u8PeripheralId-APB1_START) );
	}
	/* APB2 Bus */
	else if (Copy_u8PeripheralId <= APB2_END  && Copy_u8PeripheralId >= APB2_START)
	{
		SET_BIT(RCC->APB2ENR, (Copy_u8PeripheralId-APB2_START) );
	}
	else
	{
		/* Return Error */
	}
}
