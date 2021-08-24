/*
 * Debouncing_Handler.h
 *
 * Created: 21/8/2021 6:36:15 PM
 *  Author: Ahmed Nabil
 */ 


#include "Debouncing_Handler.h"
#include "MCAL/Gpt Module/Gpt.h"

void Dev_0_TimerCallbackFunction(void);
void Dev_1_TimerCallbackFunction(void);
void Dev_2_TimerCallbackFunction(void);

DebouncingClientState_t   DevClient_State[BOUNCING_DEVICES_USED_NUM] = {DEBOUNCING_CLIENT_STATE_IDLE};
uint8_t  DevClient_currentState[BOUNCING_DEVICES_USED_NUM] = {PIN_LOW};
static uint8_t bouncingDev_counter = 0;
pfGpt_CallBack_t DebouncingClient_TimerCallbackFunctions[TIMERS_NUM] = {Dev_0_TimerCallbackFunction, Dev_1_TimerCallbackFunction, Dev_2_TimerCallbackFunction};
ptr_VoidFuncVoid DebouncingClient_EventCallbackFunctions[DEBOUNCING_MAX_CLIENTS_NUM] = {BouncingDevice_callBack_0, BouncingDevice_callBack_1, BouncingDevice_callBack_2};

ptr_VoidFuncVoid DebouncingClient_getEventCallback(uint8_t DevClient_ID)
{
	if((DevClient_ID < BOUNCING_DEVICES_USED_NUM) && (bouncingDev_counter < DEBOUNCING_MAX_CLIENTS_NUM-1))
	{
		if(DebouncingClient_Configrations[DevClient_ID].BouncingDev_EventType == DEBOUNCING_DEV_EVENT_INTERRUPT)
		{
			return DebouncingClient_EventCallbackFunctions[bouncingDev_counter++];
		}
		else
		{
			
		}
	}
	else
	{
		
	}
	return NULL_PTR;
}

Std_ReturnType DebouncingClient_getState(uint8_t DevClient_ID, uint8_t *DevClient_StateReading_pu8)
{
	*DevClient_StateReading_pu8 = DevClient_currentState[DevClient_ID];
	
	return E_OK;
}

Std_ReturnType DebouncingClient_mainFunction(uint8_t DevClient_ID)
{
    switch(DevClient_State[DevClient_ID])
    {
        case DEBOUNCING_CLIENT_STATE_IDLE:
        {
			if(DebouncingClient_Configrations[DevClient_ID].BouncingDev_EventType == DEBOUNCING_DEV_EVENT_POLLING)
			{
				uint8_t DevClient_newState = PIN_LOW;
				
				//Button_getState(BtnClient_ButtonID, &DevClient_newState);
				DebouncingClient_Configrations[DevClient_ID].BouncingDev_getterFun_Ptr(DebouncingClient_Configrations[DevClient_ID].BouncingDev_ID, &DevClient_newState);
				
				if(DevClient_newState != DevClient_currentState[DevClient_ID])
				{ /* Change in button */
	                DebouncingClient_eventReceive(DevClient_ID);
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
        case DEBOUNCING_CLIENT_STATE_BUSY:
        {

            break;
        }
        case DEBOUNCING_CLIENT_STATE_UPDATE:
        {
            uint8_t DevClient_newState = PIN_LOW;
            //Button_getState(BtnClient_ButtonID, &DevClient_newState);
			DebouncingClient_Configrations[DevClient_ID].BouncingDev_getterFun_Ptr(DebouncingClient_Configrations[DevClient_ID].BouncingDev_ID, &DevClient_newState);
            if(DevClient_newState != DevClient_currentState[DevClient_ID])
            { /* Change in button */
                DevClient_currentState[DevClient_ID] = DevClient_newState;
                DevClient_State[DevClient_ID] = DEBOUNCING_CLIENT_STATE_IDLE;
            }
            break;
        }
        default:
        {

        }
	}
	return E_OK;
}

Std_ReturnType DebouncingClient_eventReceive(uint8_t DevClient_ID)
{
    if(DevClient_State[DevClient_ID] == DEBOUNCING_CLIENT_STATE_IDLE)
    {
		if(DebouncingClient_Configrations[DevClient_ID].DebouncingDelayType == DEBOUNCING_ASYNC_TIMER)
		{
			/* Start async Timer and pass a callback function */
			GptStart_aSync(DebouncingClient_Configrations[DevClient_ID].Gpt_channelID \
						  ,DebouncingClient_Configrations[DevClient_ID].DebounceDelay_ms\
						  ,DebouncingClient_TimerCallbackFunctions[DevClient_ID]);
		}
		else if(DebouncingClient_Configrations[DevClient_ID].DebouncingDelayType == DEBOUNCING_SYNC_TIMER)
		{
			/* Start sync timer (( Blocking ))*/
			GptStart_Sync(DebouncingClient_Configrations[DevClient_ID].Gpt_channelID, DebouncingClient_Configrations[DevClient_ID].DebounceDelay_ms);
		}
		else if(DebouncingClient_Configrations[DevClient_ID].DebouncingDelayType == DEBOUNCING_OS_TICKS)
		{
			/* Get the current tick time */
			//xLastWakeTime=xTaskGetTickCount();
		}
		else
		{
			uint32_t u32_loopIndex = 0;
			/* De-bouncing Delay */
			for(u32_loopIndex=0; u32_loopIndex < DebouncingClient_Configrations[DevClient_ID].DebounceDelay_ms ; u32_loopIndex++);
		}
        /* Change the state to Busy */
        DevClient_State[DevClient_ID] = DEBOUNCING_CLIENT_STATE_BUSY;
    }
    else
    {

    }
	return E_OK;
}

/** These callback functions must be installed in the interrupt vector table **/
void BouncingDevice_callBack_0(void)
{
	DebouncingClient_eventReceive(0);
}

/** These callback functions must be installed in the interrupt vector table **/
void BouncingDevice_callBack_1(void)
{
	DebouncingClient_eventReceive(1);
}

/** These callback functions must be installed in the interrupt vector table **/
void BouncingDevice_callBack_2(void)
{
	DebouncingClient_eventReceive(2);
}




void Dev_0_TimerCallbackFunction(void)
{
	if(DevClient_State[0] == DEBOUNCING_CLIENT_STATE_BUSY)
	{
		DevClient_State[0] = DEBOUNCING_CLIENT_STATE_UPDATE;
	}
	else
	{
		
	}
}



void Dev_1_TimerCallbackFunction(void)
{
	if(DevClient_State[1] == DEBOUNCING_CLIENT_STATE_BUSY)
	{
		DevClient_State[1] = DEBOUNCING_CLIENT_STATE_UPDATE;
	}
	else
	{
		
	}
}


void Dev_2_TimerCallbackFunction(void)
{
	if(DevClient_State[2] == DEBOUNCING_CLIENT_STATE_BUSY)
	{
		DevClient_State[2] = DEBOUNCING_CLIENT_STATE_UPDATE;
	}
	else
	{
		
	}
}