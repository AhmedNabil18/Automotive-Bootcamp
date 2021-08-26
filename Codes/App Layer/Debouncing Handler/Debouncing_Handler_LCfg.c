/*
 * Debouncing_Handler_LCfg.c
 *
 * Created: 21/8/2021 9:08:21 PM
 *  Author: Ahmed Nabil
 */ 
#include "Debouncing_Handler.h"

/* Array of structs holds the button client config */
DebouncingClient_Config_t DebouncingClient_Configrations[BOUNCING_DEVICES_USED_NUM] =
{
	{BUTTON_CHANNEL_0, TIMER_CHANNEL_0_ID, 3750, DEBOUNCING_ASYNC_TIMER, DEBOUNCING_DEV_EVENT_INTERRUPT, Button_getState},
	{BUTTON_CHANNEL_1, TIMER_CHANNEL_1_ID, 3750, DEBOUNCING_ASYNC_TIMER, DEBOUNCING_DEV_EVENT_POLLING, Button_getState}
};
