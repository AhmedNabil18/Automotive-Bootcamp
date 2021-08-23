/******************************************************************************
 *
 * Module: I2C - Registers
 *
 * File Name: I2C_Regs.h
 *
 * Description: I2C Registers
 *
 * Author: Mohamed Magdy
 *
 * Date: 21-July-2021
 *******************************************************************************/



#ifndef  I2C_REGS_H_
#define  I2C_REGS_H_

#include "Microcontroller/Std_Types.h"

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
/*-*-*-*-*-*-*-*-*-*-*-*- I2C REGISTERS -*-*-*-*-*-*-*-*-*-*-*-*/
#define I2C_TWCR_REG			(*((volatile uint8_t*)(0x56)))
#define I2C_TWDR_REG			(*((volatile uint8_t*)(0x23)))
#define I2C_TWAR_REG			(*((volatile uint8_t*)(0x22)))
#define I2C_TWSR_REG			(*((volatile uint8_t*)(0x21)))
#define I2C_TWBR_REG			(*((volatile uint8_t*)(0x20)))
#endif /*  I2C_REGS_H_ */