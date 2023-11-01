/*
 ============================================================================
 Name        : SWITCH_interface.h
 Author      : Manar Hashem
 Date		 : Oct 22, 2023
 Version     : 1.0
 Description : SWITCH_interface header file
 ============================================================================
 */

#ifndef HAL_SWITCH_SWITCH_CONFIG_H_
#define HAL_SWITCH_SWITCH_CONFIG_H_

typedef enum{
	SW_NO_1, SW_NO_2, SW_NO_3, SW_NO_4
}SWITCH_SelectType;

#define SWITCH_1_PIN		PIN_7
#define SWITCH_2_PIN		PIN_6
#define SWITCH_3_PIN		PIN_5
#define SWITCH_4_PIN		PIN_3
#define SWITCH_PORT			PORT_D


#endif /* HAL_SWITCH_SWITCH_CONFIG_H_ */
