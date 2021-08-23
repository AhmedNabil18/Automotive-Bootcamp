/******************************************************************************
 *
 * Module: SPI - Registers
 *
 * File Name: Spi_Regs.h
 *
 * Description: Spi Registers
 *
 * Author: Mohamed Magdy
 *
 * Date: 20-July-2021
 *******************************************************************************/



#ifndef  SPI_REGS_H_
#define  SPI_REGS_H_

#include "Microcontroller/Std_Types.h"

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
/*-*-*-*-*-*-*-*-*-*-*-*- SPI REGISTERS -*-*-*-*-*-*-*-*-*-*-*-*/
#define SPI_SPDR_REG			(*((volatile uint8_t*)(0x2F)))
#define SPI_SPSR_REG			(*((volatile uint8_t*)(0x2E)))
#define SPI_SPCR_REG			(*((volatile uint8_t*)(0x2D)))


#endif /*  SPI_REGS_H_ */