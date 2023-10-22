/*
 ============================================================================
 Name        : SSD_config.h
 Author      : Manar Hashem
 Date		 : Oct 20, 2023
 Version     : 1.0
 Description : SSD_config header file
 ============================================================================
 */

#ifndef HAL_SSD_SSD_CONFIG_H_
#define HAL_SSD_SSD_CONFIG_H_

/*********** BCD Decoder Pins ***********/
#define BCD_A_PIN		PIN_0
#define BCD_A_PORT		PORT_B
#define BCD_B_PIN		PIN_1
#define BCD_B_PORT		PORT_B
#define BCD_C_PIN		PIN_2
#define BCD_C_PORT		PORT_B
#define BCD_D_PIN		PIN_4
#define BCD_D_PORT		PORT_B

/*********** 7 Segments Common Pins***********/
#define COM1_PIN		PIN_3
#define COM1_PORT		PORT_A
#define COM2_PIN		PIN_2
#define COM2_PORT		PORT_A
#define COM3_PIN		PIN_5
#define COM3_PORT		PORT_B
#define COM4_PIN		PIN_6
#define COM4_PORT		PORT_B

#define SSD_SELECT		SSD_NO_1

#endif /* HAL_SSD_SSD_CONFIG_H_ */
