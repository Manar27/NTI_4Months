/*
 ============================================================================
 Name		 : EXTI_private.h
 Author		 : Manar Hashem
 Date		 : Oct 23 2023
 Version	 : 1.0
 Description : EXTI_private header file
 ============================================================================
*/
#ifndef MCAL_EXTI_HEADER_EXTI_PRIVATE_H_
#define MCAL_EXTI_HEADER_EXTI_PRIVATE_H_

#define EXTI_FallingEdge 	0
#define EXTI_RisingEdge 	1
#define EXTI_OnChangeEdge 	2
#define EXTI_LowLevel		3

#define EXTI0_PORT 	PORT_D
#define EXTI0_PIN	PIN_2

#define EXTI1_PORT 	PORT_D
#define EXTI1_PIN	PIN_3

#define EXTI2_PORT 	PORT_A
#define EXTI2_PIN	PIN_2


#endif /* MCAL_EXTI_HEADER_EXTI_PRIVATE_H_ */
