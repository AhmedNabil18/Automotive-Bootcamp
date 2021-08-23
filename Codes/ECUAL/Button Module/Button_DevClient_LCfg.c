/*
 * Button_DevClient_LCfg.c
 *
 * Created: 21/8/2021 9:08:21 PM
 *  Author: Ahmed Nabil
 */ 
#include "Button_DevClient.h"
#include "../../MCAL/Gpt Module/Gpt.h"
/* Array of structs holds the button client config */
ButtonClient_Config_t ButtonClient_Configrations[BUTTONS_USED_NUM] =
{
	{TIMER_CHANNEL_0_ID, 3750, DEBOUNCING_ASYNC_TIMER, DEBOUNCING_BTN_INTERRUPT},
	{TIMER_CHANNEL_2_ID, 3750, DEBOUNCING_ASYNC_TIMER, DEBOUNCING_BTN_POLLING}
};