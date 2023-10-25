/*
 ============================================================================
 Name        : KPD_config.h
 Author      : Manar Hashem
 Date		 : Oct 22, 2023
 Version     : 1.0
 Description : KPD_config header file
 ============================================================================
 */

#ifndef HAL_KPD_HEADER_KPD_CONFIG_H_
#define HAL_KPD_HEADER_KPD_CONFIG_H_

#define ROW 				4
#define Column				4

#define ROWStart			0
#define ROWEnd				3

#define ColumnStart			0
#define ColumnEnd			3

#define KPD_RowGroup 		PORT_C
#define KPD_Row1			PIN_5
#define KPD_Row2			PIN_4
#define KPD_Row3			PIN_3
#define KPD_Row4			PIN_2

#define KPD_ColumnGroup 	PORT_D
#define KPD_Column1			PIN_7
#define KPD_Column2			PIN_6
#define KPD_Column3			PIN_5
#define KPD_Column4			PIN_3


#define KPD_ConfValues		\
{{'1','2','3','+'},			\
{'4','5','6','-'},			\
{'7','8','9','*'},			\
{'C','0','=','/'}}

#endif /* HAL_KPD_HEADER_KPD_CONFIG_H_ */
