/*
 ============================================================================
 Name		 : ADC_config.h
 Author		 : Manar Hashem
 Date		 : Oct 24, 2023
 Version	 : 1.0
 Description : ADC_config header file
 ============================================================================
*/

#ifndef MCAL_ADC_ADC_CONFIG_H_
#define MCAL_ADC_ADC_CONFIG_H_

#define TIMEOUT				100000UL

#define VOLT_SELECT			AVCC

#define DATA_ORG			RIGHT_DATA

#define PRESALAR			PRESCALER_64

/*
 * ISR_ENABLE
 * ISR_Polling
 * */
#define ISR_ENABLE

/*
 * TRIGGER_ENABLE
 * TRIGGER_DISABLE
 * */
#define TRIGGER_ENABLE


#ifdef TRIGGER_ENABLE
#define TRIGGER_SOURCE			EXTI_NO_0
#endif
#endif /* MCAL_ADC_ADC_CONFIG_H_ */
