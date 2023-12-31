/*
 ============================================================================
 Name        : LCD_interface.h
 Author      : Manar Hashem
 Date		 : Oct 21, 2023
 Version     : 1.0
 Description : LCD_interface header file
 ============================================================================
 */
#ifndef HAL_LCD_INTERFACE_H_
#define HAL_LCD_INTERFACE_H_

#include "LCD_config.h"
#include "LCD_private.h"

void LCD_Void4BitsInit(void);
void LCD_VoidSendCommand(u8 Local_Command);
void LCD_VoidSendData(u8 Local_Data);
void LCD_VoidSendString (char *Ref_string);
void LCD_VoidSendNumber(u32 Local_Number);
void LCD_VoidStartFrom(u8 Local_RowPosition, u8 Local_ColPosition);
void LCD_VoidDisplayStrRowCol (u8 *Ref_str, u8 Local_RowPosition, u8 Local_ColPosition);

void HLCD_voidDisplayNumber(u32 A_u32Number);

#endif /* HAL_LCD_INTERFACE_H_ */
