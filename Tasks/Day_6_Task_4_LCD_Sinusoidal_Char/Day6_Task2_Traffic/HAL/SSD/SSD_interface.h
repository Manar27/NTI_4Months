/*
 ============================================================================
 Name        : SSD_interface.h
 Author      : Manar Hashem
 Date		 : Oct 20, 2023
 Version     : 1.0
 Description : SSD_interface header file
 ============================================================================
 */
#ifndef HAL_SSD_SSD_INTERFACE_H_
#define HAL_SSD_SSD_INTERFACE_H_

#include "SSD_config.h"
#include "SSD_private.h"


void SSD_VoidInit(SSD_SelectType Local_Select);
void SSD_VoidDisplayNo(u8 Local_Number);
void SSD_VoidDisplayRange(u8 Local_Start, u8 Local_End);
void SSD_VoidClear(void);

#endif /* HAL_SSD_SSD_INTERFACE_H_ */
