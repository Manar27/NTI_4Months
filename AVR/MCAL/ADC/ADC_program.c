/*
 ============================================================================
 Name		 : ADC_program.c
 Author		 : Manar Hashem
 Date		 : Oct 24, 2023
 Version	 : 1.0
 Description : ADC_program Source file
 ============================================================================
 */

/*
 * ***************** ADC (Analog to digital Converter) *****************
 * Types: RAMP and SAR
 * 		  1- RAMP -> Conversion time changes with the incoming input
 * 		  			1 V -> 1 msec for example, then
 * 		  			5 V -> 5 msec
 *
 * 		  2- SAR -> Successive approximation (Conversion time is constant for all inputs)
 *
 * DAC types -> R2R and Weight Resistor
 * 		  1- R2R -> only get a resistor R and its duplicate 2R
 * 		  2- W Resistor -> get R and 2R and 4R and 8R .... each resistor converts 1 bit
 *
 * 		  0		1	 2	 	3	....
 * 		  R		2R	 4R		8R
 *
 */

#include "../../LIB/Bit_math.h"
#include "../../LIB/STD_types.h"
#include "../DIO/DIO_interface.h"

#include "ADC_interface.h"

void ADC_voidInit()
{
	/*Set reference voltage to AVCC*/
	ADC_ADMUX->REFS = VOLT_SELECT;
	/*activate left adjust result*/
	ADC_ADMUX->ADLAR = DATA_ORG;
	/*Select prescaler to 8 --> 011*/
	ADC_ADCSRA->ADPS = PRESALAR;
	/*Enable ADC*/
	ADC_ADCSRA->ADEN = EN;

	/*Enable ADC Interrupt if required*/
#ifdef ISR_ENABLE
	ADC_ADCSRA->ADIE = EN;
#endif

#ifdef TRIGGER_ENABLE
	ADC_ADCSRA->ADATE = EN;
	ADC_SFIOR->ADTS = TRIGGER_SOURCE;
#endif
}
ADC_ERROR_RETURN ADC_voidChannelSelect(ADC_CHANNEL_NUM copy_u8ChannelSellect)
{
	ADC_ERROR_RETURN Local_Error = OK;
	if(copy_u8ChannelSellect <= CHANNEL_7)
	{
		DIO_VoidSetPinDirection(PORT_A,copy_u8ChannelSellect,DIO_INPUT);
		ADC_ADMUX->MUX = copy_u8ChannelSellect;
	}
	else
	{
		Local_Error = NUM_OUT_OF_RANGE;
	}
	return Local_Error;
}

ADC_ERROR_RETURN ADC_StartConversionBoling (u16 *copy_Pu8Data)
{
	ADC_ERROR_RETURN Local_Error = OK;
	u32 Counter = 0;
	if(copy_Pu8Data != NULL)
	{
		ADC_ADCSRA->ADSC = EN;
		/*Polling Until the Flag is Set or till the timeout*/
		while((ADC_ADCSRA->ADIF == 0))// && (Counter <= TIMEOUT))
		{
			//Counter++;
		}
		if(ADC_ADCSRA->ADIF == 1)
		{
			ADC_ADCSRA->ADIF = EN;
#if DATA_ORG == RIGHT_DATA
			(*copy_Pu8Data) = ADC_DATA;
#elif DATA_ORG == LEFT_DATA
			(*copy_Pu8Data) = ((u16)ADC_DATA >> 6);
#endif
		}
		else
		{
			Local_Error = TIME_OUT_ERROR;
		}
	}
	else
	{
		Local_Error = NULL_ERROR;
	}
	return Local_Error;
}
void ADC_StartConversion(void)
{
	ADC_ADCSRA->ADSC = EN;
}
ADC_ERROR_RETURN ADC_voidChannelMulBoling(u16 *copy_Pu8Data)
{
	u8 i = 7;
	ADC_ERROR_RETURN Local_Error = OK;
	if(copy_Pu8Data != NULL)
	{
		while(i != 0)
		{
			ADC_voidChannelSelect(i);
			Local_Error = ADC_StartConversionBoling(&copy_Pu8Data[i]);

			/*if(Local_Error == TIMEOUT)
			{
				Local_Error = ADC_StartConversionBoling(&copy_Pu8Data[i]);
			}*/
			i--;
		}
	}
	else
	{
		Local_Error = NULL_ERROR;
	}
	return Local_Error;
}
u16 ADC_Mapping (u16 x1 ,u16 x2 , u16 y1 ,u16 y2)
{
	/*Function to change the range of the ADC output from
	 * for Example 0 to 1023 to 2500 to 5000
	 *						(x - x1) * (y2 - y1)
	 * By the Equation y = ----------------------- + y1
	 * 							  (x2-x1)
	 * */
	u16 Local_u16NewData = 0;
	u16 Local_u16OLdData = 0;

#if DATA_ORG == RIGHT_DATA
	Local_u16OLdData = ADC_DATA;
#elif DATA_ORG == LEFT_DATA
	Local_u16OLdData = ((u16)ADC_DATA >> 6);
#endif

	/*Mappu*/
	Local_u16NewData = ( ( (u32)(Local_u16OLdData - x1) * (y2 - y1) )/ (x2 - x1) ) + y1;
	return Local_u16NewData;
}

/***************************************************************************/
/*
 * ISR Functions.. Only used when ISR is enabled for ADC */

#ifdef ISR_ENABLE
static u16 *ADC_po16DataResult = NULL;
static void (*ADC_CallBackPTR)(void);

ADC_ERROR_RETURN ADC_voidSetCallBack(u16 *copy_po16Data, void(*PTR)(void))
{
	ADC_ERROR_RETURN Local_Error = OK;
	if(copy_po16Data != NULL)
	{
		ADC_po16DataResult = copy_po16Data;
	}
	else
	{
		Local_Error = NULL_ERROR;
	}
	if(PTR != NULL)
	{
		ADC_CallBackPTR = PTR;
	}
	else
	{
		Local_Error = NULL_ERROR;
	}
	return Local_Error;
}

void __vector_16(void)		__attribute__((signal));
void __vector_16(void)
{
	#if DATA_ORG == RIGHT_DATA
		(*ADC_po16DataResult) = ADC_DATA;
	#elif DATA_ORG == LEFT_DATA
		(*ADC_po16DataResult) = ((u16)ADC_DATA >> 6);
	#endif

	if(ADC_CallBackPTR != NULL)
	{
		ADC_CallBackPTR();
	}
	else
	{
		//No Code
	}
}
#endif
