/*
 * Button_DevClient.h
 *
 * Created: 21/8/2021 6:36:15 PM
 *  Author: Ahmed Nabil
 */
#include "Button.h"
#include "../../Microcontroller/Std_Types.h"
#include "../../Libraries/Common_Macros.h"

#ifndef BUTTON_DEVCLIENT_H_
#define BUTTON_DEVCLIENT_H_


#define BTN_CLIENT_STATE_IDLE            0U
#define BTN_CLIENT_STATE_BUSY            1U
#define BTN_CLIENT_STATE_UPDATE          2U

#define DEBOUNCING_OS_TICKS             0U
#define DEBOUNCING_ASYNC_TIMER          1U
#define DEBOUNCING_SYNC_TIMER           2U

#define DEBOUNCING_BTN_POLLING			0U
#define DEBOUNCING_BTN_INTERRUPT		1U

/*
 * Data Type for Button Client State
 */
typedef uint8_t ButtonClientState_t;

/*
 * Data Type for Button Client Configurations per button    
 */
typedef struct
{
    uint8_t Gpt_channelID;
    uint16_t BtnClient_DebounceDelay_ms;
    uint8_t BtnClient_debouncingDelayType;
	uint8_t BtnClient_ButtonEventType;
}ButtonClient_Config_t;

Std_ReturnType ButtonClient_getState(u8_ButtonChannel_t BtnClient_ButtonID, u8_ButtonState_t *BtnClient_ButtonReading_pu8);
Std_ReturnType ButtonClient_Update(u8_ButtonChannel_t BtnClient_ButtonID);
Std_ReturnType ButtonClient_eventReceive(u8_ButtonChannel_t BtnClient_ButtonID);

void ButtonCallBack_0(void);
void ButtonCallBack_1(void);
void ButtonCallBack_2(void);

extern ButtonClient_Config_t ButtonClient_Configrations[BUTTONS_USED_NUM];
#endif