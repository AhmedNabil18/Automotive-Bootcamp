/*
 * Debouncing_Handler.h
 *
 * Created: 21/8/2021 6:36:15 PM
 *  Author: Ahmed Nabil
 */
#include "MCAL/Gpt Module/Gpt.h"
#include "Microcontroller/Std_Types.h"
#include "Libraries/Common_Macros.h"
#include "Debouncing_Handler_LCfg.h"
#ifndef DEBOUNCING_HANDLER_H_
#define DEBOUNCING_HANDLER_H_

#define DEBOUNCING_MAX_CLIENTS_NUM				3U

#define DEBOUNCING_CLIENT_STATE_IDLE            0U
#define DEBOUNCING_CLIENT_STATE_BUSY            1U
#define DEBOUNCING_CLIENT_STATE_UPDATE          2U

#define DEBOUNCING_OS_TICKS						0U
#define DEBOUNCING_ASYNC_TIMER					1U
#define DEBOUNCING_SYNC_TIMER					2U

#define DEBOUNCING_DEV_EVENT_POLLING			0U
#define DEBOUNCING_DEV_EVENT_INTERRUPT			1U

/*
 * Data Type for Debouncing Client State
 */
typedef uint8_t DebouncingClientState_t;


typedef Std_ReturnType (*BouncingDev_getterFun_t)(uint8_t , uint8_t *);

typedef void (*Debouncing_CallBack_t)(uint8_t);

/*
 * Data Type for Debouncing Client Configurations per button    
 */
typedef struct
{
	uint8_t BouncingDev_ID;
	uint8_t Gpt_channelID;
	uint16_t DebounceDelay_ms;
	uint8_t DebouncingDelayType;
	uint8_t BouncingDev_EventType;
	BouncingDev_getterFun_t BouncingDev_getterFun_Ptr;
}DebouncingClient_Config_t;

Debouncing_CallBack_t DebouncingClient_getEventCallback(uint8_t DevClient_ID);
Std_ReturnType DebouncingClient_getState(u8_ButtonChannel_t BtnClient_ButtonID, u8_ButtonState_t *BtnClient_ButtonReading_pu8);
Std_ReturnType DebouncingClient_mainFunction(u8_ButtonChannel_t BtnClient_ButtonID);
Std_ReturnType DebouncingClient_eventReceive(u8_ButtonChannel_t BtnClient_ButtonID);

void BouncingDevice_callBack_0(uint8_t Int_ID);
void BouncingDevice_callBack_1(uint8_t Int_ID);
void BouncingDevice_callBack_2(uint8_t Int_ID);

extern DebouncingClient_Config_t DebouncingClient_Configrations[BOUNCING_DEVICES_USED_NUM];

#endif