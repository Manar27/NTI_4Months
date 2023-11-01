/*
 ============================================================================
 Name		 : TIMER0_interface.h
 Author		 : Manar Hashem
 Date		 : Oct 27, 2023
 Version	 : 1.0
 Description : TIMER0_interface header file
 ============================================================================
*/
#ifndef MCAL_TIMER0_TIMER0_INTERFACE_H_
#define MCAL_TIMER0_TIMER0_INTERFACE_H_


#include "TIMER0_private.h"
#include "TIMER0_register.h"
#include "TIMER0_config.h"

void TIMER0_VoidInit(void);
void TIMER0_VoidStop(void);
void TIMER0_VoidStart(void);
void TIMER0_VoidSetPreload(u8 copy_u8PRELOAD);
u8 TIMER0_VoidVal(void);


//void TIMER0_Void(u8 copy_u8PRELOAD );
void TIMER0_VoidSetPWMCompareMatch(u8 copy_u8Val );

void TIMER_voidSetCallBack(void (*ptr_timer)(void));


void WDT_VoidEnabel(void );
void WDT_VoidDisEnabel(void);
void WDT_VoidSleep(u8 sleep_time);

#endif /* MCAL_TIMER0_TIMER0_INTERFACE_H_ */
