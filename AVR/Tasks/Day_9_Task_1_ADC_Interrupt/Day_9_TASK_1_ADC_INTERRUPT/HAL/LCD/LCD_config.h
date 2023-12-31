/*
 ============================================================================
 Name        : LCD_config.h
 Author      : Manar Hashem
 Date		 : Oct 21, 2023
 Version     : 1.0
 Description : LCD_config header file
 ============================================================================
 */

#ifndef HAL_LCD_CONFIG_H_
#define HAL_LCD_CONFIG_H_


#define ROWS_NUMBER 			4
#define COLS_NUMBER				20


#define TOTAL_BLOCKS_NUM	 	80

#define LINE0_ADD				0x00
#define LINE1_ADD				0x40
#define LINE2_ADD				0x80
#define LINE3_ADD				0xC0

#define LINE_1					0
#define LINE_2					1
#define LINE_3					2
#define LINE_4					3

#define LCD_RS_Pin				PIN_3
#define LCD_RS_PORT				PORT_A
#define LCD_EN_Pin				PIN_2
#define LCD_EN_PORT				PORT_A

#define LCD_Data_PORT			PORT_B
#define LCD_Data_PIN4			PIN_0
#define LCD_Data_PIN5			PIN_1
#define LCD_Data_PIN6			PIN_2
#define LCD_Data_PIN7			PIN_4

#endif /* HAL_LCD_CONFIG_H_ */
