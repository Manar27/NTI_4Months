/*
 ============================================================================
 Name		 : GIE_program.c
 Author		 : Manar Hashem
 Date		 : Oct 23, 2023
 Version	 : 1.0
 Description : GIE_program Source file
 ============================================================================
*/
#include "../../LIB/Bit_math.h"
#include "../../LIB/STD_types.h"

#include "GIE_interface.h"
#include "GIE_register.h"

void GIE_VoidEnable (void)
{
	SET_BIT(GIE_SREG,GIE_SREG_I);
}

void GIE_VoidDisable (void)
{
	CLR_BIT(GIE_SREG,GIE_SREG_I);
}
