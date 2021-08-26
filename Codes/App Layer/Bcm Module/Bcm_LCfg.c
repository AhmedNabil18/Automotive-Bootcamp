/*
 * Bcm_LCfg.c
 *
 * Created: 8/25/2021 7:14:55 PM
 *  Author: Ahmed Nabil
 */ 


#include "Bcm.h"

const BCM_TxConfig_t BCM_TxConfigurations[BCM_COM_DEVICES_USED] = 
{
	 {UART_CHANNEL_0, USART_TXC_IRQ, Uart_writeByte, Uart_EnableNotification_TXC, Uart_DisableNotification_TXC}
};