/*
 * Button_DevClient.h
 *
 * Created: 21/8/2021 6:36:15 PM
 *  Author: Ahmed Nabil
 */ 


#include "Button_DevClient.h"
#include "MCAL/Gpt Module/Gpt.h"

void Button0_TimerCallbackFunction(void);
void Button1_TimerCallbackFunction(void);
void Button2_TimerCallbackFunction(void);


ButtonClientState_t   BtnClient_State[BUTTONS_USED_NUM] = {BTN_CLIENT_STATE_IDLE};
u8_ButtonState_t  BtnClient_currentButtonState[BUTTONS_USED_NUM] = {PIN_LOW};
pfGpt_CallBack_t TimerCallbackFunctions[TIMERS_NUM] = {Button0_TimerCallbackFunction, Button1_TimerCallbackFunction, Button2_TimerCallbackFunction};

Std_ReturnType ButtonClient_getState(u8_ButtonChannel_t BtnClient_ButtonID, u8_ButtonState_t *BtnClient_ButtonReading_pu8)
{
	*BtnClient_ButtonReading_pu8 = BtnClient_currentButtonState[BtnClient_ButtonID];
	
	return E_OK;
}

Std_ReturnType ButtonClient_Update(u8_ButtonChannel_t BtnClient_ButtonID)
{
    switch(BtnClient_State[BtnClient_ButtonID])
    {
        case BTN_CLIENT_STATE_IDLE:
        {
			if(ButtonClient_Configrations[BtnClient_ButtonID].BtnClient_ButtonEventType == DEBOUNCING_BTN_POLLING)
			{
				u8_ButtonState_t BtnClient_newButtonState = PIN_LOW;
				Button_getState(BtnClient_ButtonID, &BtnClient_newButtonState);
				if(BtnClient_newButtonState != BtnClient_currentButtonState[BtnClient_ButtonID])
				{ /* Change in button */
	                ButtonClient_eventReceive(BtnClient_ButtonID);
				}
				else
				{
					
				}
			}
			else
			{
				
			}
			break;
        }
        case BTN_CLIENT_STATE_BUSY:
        {

            break;
        }
        case BTN_CLIENT_STATE_UPDATE:
        {
            u8_ButtonState_t BtnClient_newButtonState = PIN_LOW;
            Button_getState(BtnClient_ButtonID, &BtnClient_newButtonState);

            if(BtnClient_newButtonState != BtnClient_currentButtonState[BtnClient_ButtonID])
            { /* Change in button */
                BtnClient_currentButtonState[BtnClient_ButtonID] = BtnClient_newButtonState;
                BtnClient_State[BtnClient_ButtonID] = BTN_CLIENT_STATE_IDLE;
            }
            break;
        }
        default:
        {

        }
	}
	return E_OK;
}

Std_ReturnType ButtonClient_eventReceive(u8_ButtonChannel_t BtnClient_ButtonID)
{
    if(BtnClient_State[BtnClient_ButtonID] == BTN_CLIENT_STATE_IDLE)
    {
		if(ButtonClient_Configrations[BtnClient_ButtonID].BtnClient_debouncingDelayType == DEBOUNCING_ASYNC_TIMER)
		{
			/* Start async Timer and pass a callback function */
			GptStart_aSync(ButtonClient_Configrations[BtnClient_ButtonID].Gpt_channelID \
						  ,ButtonClient_Configrations[BtnClient_ButtonID].BtnClient_DebounceDelay_ms\
						  ,TimerCallbackFunctions[BtnClient_ButtonID]);
		}
		else if(ButtonClient_Configrations[BtnClient_ButtonID].BtnClient_debouncingDelayType == DEBOUNCING_SYNC_TIMER)
		{
			/* Start sync timer (( Blocking ))*/
			GptStart_Sync(ButtonClient_Configrations[BtnClient_ButtonID].Gpt_channelID, ButtonClient_Configrations[BtnClient_ButtonID].BtnClient_DebounceDelay_ms);
		}
		else if(ButtonClient_Configrations[BtnClient_ButtonID].BtnClient_debouncingDelayType == DEBOUNCING_OS_TICKS)
		{
			/* Get the current tick time */
			//xLastWakeTime=xTaskGetTickCount();
		}
		else
		{
			uint32_t u32_loopIndex = 0;
			/* De bouncing Delay */
			for(u32_loopIndex=0; u32_loopIndex < ButtonClient_Configrations[BtnClient_ButtonID].BtnClient_DebounceDelay_ms*100 ; u32_loopIndex++);
		}
        /* Change the state to Busy */
        BtnClient_State[BtnClient_ButtonID] = BTN_CLIENT_STATE_BUSY;
    }
    else
    {

    }
	return E_OK;
}


/** These callback functions must be installed in the interrupt vector table **/

void ButtonCallBack_0(void)
{
    ButtonClient_eventReceive(BUTTON_CHANNEL_0);
}

void Button0_TimerCallbackFunction(void)
{
	if(BtnClient_State[0] == BTN_CLIENT_STATE_BUSY)
	{
		BtnClient_State[0] = BTN_CLIENT_STATE_UPDATE;
	}
	else
	{
		
	}
}




void ButtonCallBack_1(void)
{
    ButtonClient_eventReceive(BUTTON_CHANNEL_1);
}

void Button1_TimerCallbackFunction(void)
{
	if(BtnClient_State[1] == BTN_CLIENT_STATE_BUSY)
	{
		BtnClient_State[1] = BTN_CLIENT_STATE_UPDATE;
	}
	else
	{
		
	}
}


void ButtonCallBack_2(void)
{
    ButtonClient_eventReceive(BUTTON_CHANNEL_1);
}

void Button2_TimerCallbackFunction(void)
{
	if(BtnClient_State[2] == BTN_CLIENT_STATE_BUSY)
	{
		BtnClient_State[2] = BTN_CLIENT_STATE_UPDATE;
	}
	else
	{
		
	}
}
