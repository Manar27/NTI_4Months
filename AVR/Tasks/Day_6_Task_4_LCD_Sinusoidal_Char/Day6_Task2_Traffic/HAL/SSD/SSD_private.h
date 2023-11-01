/*
 ============================================================================
 Name        : SSD_private.h
 Author      : Manar Hashem
 Date		 : Oct 20, 2023
 Version     : 1.0
 Description : SSD_private header file
 ============================================================================
 */

#ifndef HAL_SSD_SSD_PRIVATE_H_
#define HAL_SSD_SSD_PRIVATE_H_


#define SSD_OUTPUT		DIO_OUTPUT
#define SSD_INPUT		DIO_INPUT

#define SSD_HIGH		DIO_HIGH
#define SSD_LOW			DIO_LOW

#define SSD_ZERO		0x00
#define SSD_ONE			0x01
#define SSD_TWO			0x02
#define SSD_THREE		0x03
#define SSD_FOUR		0x04
#define SSD_FIVE		0x05
#define SSD_SIX			0x06
#define SSD_SEVEN		0x07
#define SSD_EIGHT		0x08
#define SSD_NINE		0x09

typedef enum{
	SSD_NO_1 = 0x01, SSD_NO_2, SSD_NO_3, SSD_NO_4
}SSD_SelectType;


#endif /* HAL_SSD_SSD_PRIVATE_H_ */
