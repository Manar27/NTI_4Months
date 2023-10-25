/*
 ============================================================================
 Name        : KPD_interface.h
 Author      : Manar Hashem
 Date		 : Oct 22, 2023
 Version     : 1.0
 Description : KPD_interface header file
 ============================================================================
 */
#ifndef HAL_KPD_HEADER_KPD_INTERFACE_H_
#define HAL_KPD_HEADER_KPD_INTERFACE_H_

#include "../../LIB/Bit_math.h"
#include "../../LIB/STD_types.h"

#include "KPD_config.h"


void KPD_VoidInit(void);
u8 KPD_u8ReadButton(void);

#endif /* HAL_KPD_HEADER_KPD_INTERFACE_H_ */
