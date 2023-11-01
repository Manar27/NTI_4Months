/*
 ============================================================================
 Name		 : RCC_interface.h
 Author		 : Manar Hashem
 Date		 : Oct 31, 2023
 Version	 : 1.0
 Description : RCC_interface header file
 ============================================================================
*/


#ifndef MCAL_RCC_RCC_INTERFACE_H_
#define MCAL_RCC_RCC_INTERFACE_H_


#define RCC_ENABLE			1
#define RCC_DISABLE 		0

#define RCC_AHB     0
#define RCC_APB1    1
#define RCC_APB2    2


void RCC_voidInitSysClock (void);
void RCC_voidEnableClock (u8 Copy_u8BusId, u8 Copy_u8PeripheralId);
void RCC_voidEnableClock_2 (u8 Copy_u8PeripheralId);
void RCC_voidDisableClock (u8 Copy_u8BusId, u8 Copy_u8PeripheralId);
void RCC_voidDisableClock_2 (u8 Copy_u8PeripheralId);

#endif /*MCAL_RCC_RCC_INTERFACE_H_*/
