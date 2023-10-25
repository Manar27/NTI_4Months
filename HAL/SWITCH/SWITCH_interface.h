/*
 ============================================================================
 Name        : SWITCH_interface.h
 Author      : Manar Hashem
 Date		 : Oct 22, 2023
 Version     : 1.0
 Description : SWITCH_interface header file
 ============================================================================
 */
#ifndef HAL_SWITCH_SWITCH_INTERFACE_H_
#define HAL_SWITCH_SWITCH_INTERFACE_H_

#include "SWITCH_config.h"
#include "SWITCH_private.h"

void SWITCH_VoidInit(SWITCH_SelectType Local_SwitchNO);
u8 SWITCH_u8ReadSwitch(SWITCH_SelectType Local_SwitchNO);

#endif /* HAL_SWITCH_SWITCH_INTERFACE_H_ */
