/*
 ============================================================================
 Name        : LCD_program.c
 Author      : Manar Hashem
 Date		 : Oct 21, 2023
 Version     : 1.0
 Description : LCD_program source file
 ============================================================================
 */

#include <util/delay.h>
#include "../../LIB/STD_types.h"
#include "../../LIB/Bit_math.h"
#include "../../MCAL/DIO/DIO_interface.h"
#include "LCD_interface.h"

void LCD_VoidSendCommand(u8 Local_Command)
{
	/*send the command line*/
	DIO_VoidSetPinVal(LCD_Data_PORT, LCD_Data_PIN4, GET_BIT(Local_Command,4));
	DIO_VoidSetPinVal(LCD_Data_PORT, LCD_Data_PIN5, GET_BIT(Local_Command,5));
	DIO_VoidSetPinVal(LCD_Data_PORT, LCD_Data_PIN6, GET_BIT(Local_Command,6));
	DIO_VoidSetPinVal(LCD_Data_PORT, LCD_Data_PIN7, GET_BIT(Local_Command,7));
	/*set RS pin to command --> 0*/
	DIO_VoidSetPinVal(LCD_RS_PORT,LCD_RS_Pin,DIO_LOW);
	_delay_ms(1);
	/*set Enable pin to High*/
	DIO_VoidSetPinVal(LCD_EN_PORT,LCD_EN_Pin,DIO_HIGH);
	_delay_ms(1);
	/*set Enable pin to Low*/
	DIO_VoidSetPinVal(LCD_EN_PORT,LCD_EN_Pin,DIO_LOW);
	_delay_ms(1);

	/*send the command line*/
	DIO_VoidSetPinVal(LCD_Data_PORT, LCD_Data_PIN4, GET_BIT(Local_Command,0));
	DIO_VoidSetPinVal(LCD_Data_PORT, LCD_Data_PIN5, GET_BIT(Local_Command,1));
	DIO_VoidSetPinVal(LCD_Data_PORT, LCD_Data_PIN6, GET_BIT(Local_Command,2));
	DIO_VoidSetPinVal(LCD_Data_PORT, LCD_Data_PIN7, GET_BIT(Local_Command,3));

	/*set Enable pin to High*/
	DIO_VoidSetPinVal(LCD_EN_PORT,LCD_EN_Pin,DIO_HIGH);
	_delay_ms(1);
	/*set Enable pin to Low*/
	DIO_VoidSetPinVal(LCD_EN_PORT,LCD_EN_Pin,DIO_LOW);
	_delay_ms(1);


}
void LCD_VoidSendData(u8 Local_Data)
{
	/*send the char line*/
	DIO_VoidSetPinVal(LCD_Data_PORT, LCD_Data_PIN4, GET_BIT(Local_Data,4));
	DIO_VoidSetPinVal(LCD_Data_PORT, LCD_Data_PIN5, GET_BIT(Local_Data,5));
	DIO_VoidSetPinVal(LCD_Data_PORT, LCD_Data_PIN6, GET_BIT(Local_Data,6));
	DIO_VoidSetPinVal(LCD_Data_PORT, LCD_Data_PIN7, GET_BIT(Local_Data,7));
	/*set RS pin to command --> 0*/
	DIO_VoidSetPinVal(LCD_RS_PORT,LCD_RS_Pin,DIO_HIGH);
	_delay_ms(1);
	/*set Enable pin to High*/
	DIO_VoidSetPinVal(LCD_EN_PORT,LCD_EN_Pin,DIO_HIGH);
	_delay_ms(1);
	/*set Enable pin to Low*/
	DIO_VoidSetPinVal(LCD_EN_PORT,LCD_EN_Pin,DIO_LOW);
	_delay_ms(1);

	/*send the command line*/
	DIO_VoidSetPinVal(LCD_Data_PORT, LCD_Data_PIN4, GET_BIT(Local_Data,0));
	DIO_VoidSetPinVal(LCD_Data_PORT, LCD_Data_PIN5, GET_BIT(Local_Data,1));
	DIO_VoidSetPinVal(LCD_Data_PORT, LCD_Data_PIN6, GET_BIT(Local_Data,2));
	DIO_VoidSetPinVal(LCD_Data_PORT, LCD_Data_PIN7, GET_BIT(Local_Data,3));

	/*set Enable pin to High*/
	DIO_VoidSetPinVal(LCD_EN_PORT,LCD_EN_Pin,DIO_HIGH);
	_delay_ms(1);
	/*set Enable pin to Low*/
	DIO_VoidSetPinVal(LCD_EN_PORT,LCD_EN_Pin,DIO_LOW);
	_delay_ms(1);
}
void LCD_Void4BitsInit(void)
{
	/*Select The Directions*/
	DIO_VoidSetPinDirection(LCD_Data_PORT, LCD_Data_PIN4, DIO_OUTPUT);
	DIO_VoidSetPinDirection(LCD_Data_PORT, LCD_Data_PIN5, DIO_OUTPUT);
	DIO_VoidSetPinDirection(LCD_Data_PORT, LCD_Data_PIN6, DIO_OUTPUT);
	DIO_VoidSetPinDirection(LCD_Data_PORT, LCD_Data_PIN7, DIO_OUTPUT);

	DIO_VoidSetPinDirection(LCD_RS_PORT, LCD_RS_Pin, DIO_OUTPUT);
	DIO_VoidSetPinDirection(LCD_EN_PORT, LCD_EN_Pin, DIO_OUTPUT);

	_delay_ms(20);
	LCD_VoidSendCommand(0x33);
	LCD_VoidSendCommand(0x32);
	/*function set*/
	LCD_VoidSendCommand(FUNCTION_SET_4BIT_2LINES_5X7_DOTS);
	/*Display On off control*/
	LCD_VoidSendCommand(DISPLAY_ON_CURSOR_OFF);
	/*Clear LCD*/
	LCD_VoidSendCommand(DISPLAY_CLEAR);
	/*Entry Mode*/
	LCD_VoidSendCommand(ENTRY_MODE_SET);
}

void LCD_VoidSendString (char *Ref_string)
{
	while (*Ref_string != '\0')
	{
		LCD_VoidSendData(*Ref_string);
		Ref_string++;
	}
}

void LCD_VoidSendNumber(u32 Local_Number)
{
	u32 Local_ReversedNum = 2;
	while (Local_Number != 0)
	{
		Local_ReversedNum = (Local_ReversedNum * 10) + (Local_Number % 10);
		Local_Number = Local_Number / 10;
	}
	do
	{
		LCD_VoidSendData((Local_ReversedNum%10)+ '0');
		Local_ReversedNum /= 10;
	}while(Local_ReversedNum != 2);
}

void LCD_VoidStartFrom(u8 Local_RowPosition, u8 Local_ColPosition)
{
	u8 Local_DDRAMAddress = 0;
	if(Local_ColPosition < COLS_NUMBER && Local_RowPosition < ROWS_NUMBER)
	{
		if(Local_RowPosition == LINE_1)
		{
			Local_DDRAMAddress = 0x80 + Local_ColPosition;
		}
		else if(Local_RowPosition == LINE_2)
		{
			Local_DDRAMAddress = 0xC0 + Local_ColPosition;
		}
		else if(Local_RowPosition == LINE_3)
		{
			Local_DDRAMAddress = 0x94 + Local_ColPosition;
		}
		else if (Local_RowPosition == LINE_4)
		{
			Local_DDRAMAddress = 0xD4 + Local_ColPosition;

		}
		LCD_VoidSendCommand(Local_DDRAMAddress | SET_DDRAM_ADDRESS);
	}
}
void LCD_VoidDisplayStrRowCol (u8 *Ref_str, u8 Local_RowPosition, u8 Local_ColPosition)
{
	LCD_VoidStartFrom(Local_RowPosition,Local_ColPosition);
	LCD_VoidSendString(Ref_str);
}

void HLCD_voidDisplayNumber(u32 A_u32Number)
{
    u32 local_u32Number = 1;
    if (A_u32Number == 0)
    {
        LCD_VoidSendData('0');
    }
    while (A_u32Number != 0)
    {
        local_u32Number = ((local_u32Number * 10) + (A_u32Number % 10));
        A_u32Number = A_u32Number / 10;
    }
    while (local_u32Number != 1)
    {
        LCD_VoidSendData((local_u32Number % 10) + 48);
        local_u32Number = local_u32Number / 10;
    }
}
/*
void LCD_VoidSendStringFromPos (char *Ref_string, u8 Local_RowPosition, u8 Local_ColPosition)
{
	u8 index = 0;
	u8 line = 0;
	LCD_VoidStartFrom(Local_RowPosition,Local_ColPosition);
	while (Ref_string[index] != '\0' && ((Local_RowPosition * COLS_NUMBER) + (Local_ColPosition + index)) < TOTAL_BLOCKS_NUM)
	{
		if((Local_RowPosition * 20) + (Local_ColPosition + index) < COLS_NUMBER)
		{
			LCD_VoidSendData(Ref_string[index]);
			index++;
		}
		else if((Local_RowPosition * 20) + (Local_ColPosition + index) == COLS_NUMBER && line == LINE_1)
		{
			LCD_VoidStartFrom(1,0);
			line++;
		}
		else if((Local_RowPosition * 20) + (Local_ColPosition + index) == COLS_NUMBER && line == LINE_2)
		{
			LCD_VoidStartFrom(2,0);
			line++;
		}
		else if((Local_RowPosition*20) + (Local_ColPosition + index) == COLS_NUMBER && line == LINE_3)
		{
			LCD_VoidStartFrom(3,0);
			line++;
		}
	}
}*/
