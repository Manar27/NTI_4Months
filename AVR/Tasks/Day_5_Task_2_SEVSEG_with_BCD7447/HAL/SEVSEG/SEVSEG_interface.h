/*
 ============================================================================
 Name        : SEVSEG_interface.h
 Author      : Manar Hashem
 Date		 : Oct 20, 2023
 Version     : 1.0
 Description : SEVSEG_interface header file
 ============================================================================
 */
#ifndef HAL_SEVSEG_SEVSEG_INTERFACE_H_
#define HAL_SEVSEG_SEVSEG_INTERFACE_H_

#include "SEVSEG_config.h"
#include "SEVSEG_private.h"


void SEVSEG_VoidInit(void);
void SEVSEG_VoidDisplayNo(u8 Local_Number);
void SEVSEG_VoidDisplayRange(u8 Local_Start, u8 Local_End);
void SEVSEG_VoidClear(void);

#endif /* HAL_SEVSEG_SEVSEG_INTERFACE_H_ */
