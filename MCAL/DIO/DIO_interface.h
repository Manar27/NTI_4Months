/*
 ============================================================================
 Name		 : DIO_interface.h
 Author		 : Manar Hashem
 Date		 : Oct 25, 2023
 Version	 : 2.0 (Struct Configuration)
 Description : DIO_interfac header file
 ============================================================================
*/
#ifndef DIO_INTERFACE_H_
#define DIO_INTERFACE_H_

/*******************************************************/

#include "DIO_register.h"
#include "DIO_private.h"
#include "DIO_config.h"

/*******************************************************/
typedef enum
{
	PORT_A,
	PORT_B,
	PORT_C,
	PORT_D
}PORT_SELECT_TYPE;

/*******************************************************/
typedef enum
{
	PIN_0,
	PIN_1,
	PIN_2,
	PIN_3,
	PIN_4,
	PIN_5,
	PIN_6,
	PIN_7
}PIN_SELECT_TYPE;

/*******************************************************/
typedef enum
{
	DIO_INPUT,
	DIO_OUTPUT
}PIN_DIRECTION;

/*******************************************************/
typedef enum
{
	DIO_LOW,
	DIO_HIGH
}PIN_VALUE;

/*******************************************************/
typedef enum
{
	DIO_PORT_INPUT,
	DIO_PORT_OUTPUT = 0xFF
}PORT_DIRECTION;

/*******************************************************/
typedef enum
{
	DIO_PORT_LOW,
	DIO_PORT_HIGH = 0xFF
}PORT_VALUE;

/*******************************************************/
typedef enum
{
	DIO_OK,
	PORT_OUT_OF_RANGE,
	PIN_OUT_OF_RANGE
}DIO_ERROR_RETURN;

/**************** Functions Prototypes *****************/

DIO_ERROR_RETURN DIO_VoidSetPortDirection(PORT_SELECT_TYPE Copy_u8PortID, PORT_DIRECTION Copy_u8PortDir);

/*******************************************************/

DIO_ERROR_RETURN DIO_VoidSetPortValue(PORT_SELECT_TYPE Copy_u8PortID, PORT_VALUE Copy_u8PortVal);

/*******************************************************/

DIO_ERROR_RETURN DIO_VoidSetPinDirection(PORT_SELECT_TYPE Copy_u8PortID, PIN_SELECT_TYPE Copy_u8PinNo, PIN_DIRECTION Copy_u8PinDir);

/*******************************************************/

DIO_ERROR_RETURN DIO_VoidSetPinVal(PORT_SELECT_TYPE Copy_u8PortID, PIN_SELECT_TYPE Copy_u8PinNo, PIN_VALUE Copy_u8PinVal);

/*******************************************************/

u8 DIO_u8GetPinVal(PORT_SELECT_TYPE Copy_u8PortID, PIN_SELECT_TYPE Copy_u8PinNo);

/*******************************************************/

DIO_ERROR_RETURN DIO_VoidTogPin(PORT_SELECT_TYPE Copy_u8PortID, PIN_SELECT_TYPE Copy_u8PinNo);

/*******************************************************/



#endif /* DIO_INTERFACE_H_ */
