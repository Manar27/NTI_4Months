/*
 ============================================================================
 Name		 : EXTI_interface.h
 Author		 : Manar Hashem
 Date		 : Oct 23, 2023
 Version	 : 1.0
 Description : EXTI_interface header file
 ============================================================================
*/

#ifndef MCAL_EXTI_HEADER_EXTI_INTERFACE_H_
#define MCAL_EXTI_HEADER_EXTI_INTERFACE_H_

#include "EXTI_config.h"
#include "EXTI_private.h"
#include "EXTI_register.h"

/*Individual Init*/
void EXTI0_VoidInit(void);
void EXTI1_VoidInit(void);
void EXTI2_VoidInit(void);

/*All in one init*/
void EXT_VoidInit(u8 Local_INT_number, u8 Local_ControlState);

/*Set sence control*/
void EXT_VoidSetSenceControl(u8 Local_INT_number, u8 Local_ControlState);

/*Interrupt Service Routine*/
void EXT0_CallBackFunction(void(*PTF)(void));
void EXT1_CallBackFunction(void(*PTF)(void));
void EXT2_CallBackFunction(void(*PTF)(void));

void __vector_1(void)	__attribute__((signal));
void __vector_2(void)	__attribute__((signal));
void __vector_3(void)	__attribute__((signal));

#endif /* MCAL_EXTI_HEADER_EXTI_INTERFACE_H_ */
