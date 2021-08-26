/*
 * ObstacleAvoid_Car.c
 *
 * Created: 8/9/2021 12:31:18 PM
 * Author : Ahmed Nabil
 */ 


#if 0
#include "App Component/App.h"

int main(void)
{
	App_start();
	
    /* Replace with your application code */
    while (1) 
    {
    }
}
#endif


















#include "App Layer/Bcm Module/Bcm.h"
#include "MCAL/Dio Module/Dio.h"

void Toggle_PinISR(uint8_t id)
{
	DIO_PORTB_DATA = 0xFF;
}

int main(void)
{
	Uart_init();
	BCM_init();
	EnableGlobalInterrupts();
	DIO_PORTB_DIR = 0xFF;
	DIO_PORTB_DATA = 0x00;
	while(1)
	{
		BCM_Transmit(BCM_CHANNEL_0, (uint8_t*)"Array", 5,Toggle_PinISR);
		BCM_TxMainFunction();
	}
	return 0;
}

