/*****************************************************************************
* Module: Adc Module
* File Name: Adc_Regs.h
* Description: Header file for Adc Module
* Author: Mohamed Magdy
* Date: 25-July-2021
******************************************************************************/


#ifndef ADC_REGS_H_
#define ADC_REGS_H_

#include "Microcontroller/Std_Types.h"

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
/*-*-*-*-*-*-*-*-*-*-*-*- ADC REGISTERS -*-*-*-*-*-*-*-*-*-*-*-*/
#define ADC_ADMUX_REG			(*((volatile uint8_t*)(0x27)))
#define ADC_ADCSRA_REG			(*((volatile uint8_t*)(0x26)))
#define ADC_ADCH_REG			(*((volatile uint8_t*)(0x25)))
#define ADC_ADCL_REG			(*((volatile uint8_t*)(0x24)))

#endif /* ADC_REGS_H_ */