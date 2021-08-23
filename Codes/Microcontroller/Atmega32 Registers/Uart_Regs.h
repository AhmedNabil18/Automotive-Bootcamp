/******************************************************************************
 *
 * Module: Uart - Registers
 *
 * File Name: Uart_Regs.h
 *
 * Description: Uart Registers
 *
 * Author: Mohamed Magdy
 *
 * Date: 19-July-2021
 *******************************************************************************/



#ifndef UART_REGS_H_
#define UART_REGS_H_

#include "Microcontroller/Std_Types.h"

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
/*-*-*-*-*-*-*-*-*-*-*-*- UART REGISTERS -*-*-*-*-*-*-*-*-*-*-*-*/
#define UART_UDR_REG			(*((volatile uint8_t*)(0x2C)))
#define UART_UCSRC_REG			(*((volatile uint8_t*)(0x40)))
#define UART_UBRRH_REG			(*((volatile uint8_t*)(0x40)))
#define UART_UCSRA_REG			(*((volatile uint8_t*)(0x2B)))
#define UART_UCSRB_REG			(*((volatile uint8_t*)(0x2A)))
#define UART_UBRRL_REG			(*((volatile uint8_t*)(0x29)))

#endif /* UART_REGS_H_ */