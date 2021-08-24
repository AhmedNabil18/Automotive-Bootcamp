/*
 * Button.c
 *
 * Created: 7/15/2021 6:35:45 PM
 *  Author: Ahmed Nabil
 */ 

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
/*-*-*-*-*- INCLUDES *-*-*-*-*-*/
#include "Button.h"

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
/*-*-*-*-*- GLOBAL STATIC VARIABLES *-*-*-*-*-*/
/*static u8_ButtonState_t gu8_ButtonsState[BUTTONS_USED_NUM] = {BUTTON_STATE_RELEASED};*/
static enuBttn_Status_t genu_BttnModuleState = BTTN_STATUS_NOT_INIT;
extern uint8_t gau8_buttonsUsed[BUTTONS_USED_NUM];
/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
/*--*-*-*- FUNCTIONS IMPLEMENTATION -*-*-*-*-*-*/

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
* Service Name: Button_init
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Parameters (in): None
* Parameters (inout): None
* Parameters (out): None
* Return value: enuBttn_Status_t - return the status of the function ERROR_OK or NOT_OK
* Description: Function to Initialize the Button module.
*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
Std_ReturnType Button_init(void)
{
/**************************************************************************************/
/*								Start of Error Checking								  */
/**************************************************************************************/
	/* Check if the button module is already initialized */
	if (genu_BttnModuleState == BTTN_STATUS_INIT)
	{
		return E_OK;
	}else{/*Nothing to here*/}
	
	/* Check if there are no DIO Pins configured */
	if(DIO_USED_PINS_NUM == 0)
	{
		return E_NOT_OK;
	}
		
/**************************************************************************************/
/*								End of Error Checking								  */
/**************************************************************************************/

/**************************************************************************************/
/*								Function Implementation								  */
/**************************************************************************************/
	/* Initialize the DIO Module and check if any error returned */
	enuDio_Status_t Dio_State = Dio_init(strDio_pins);
	if((DIO_STATUS_ERROR_OK != Dio_State) && (DIO_STATUS_ALREADY_INIT != Dio_State))
		return E_NOT_OK;
	
	/* Change the state of the Button module to Initialized */
	genu_BttnModuleState = BTTN_STATUS_INIT;
	return E_OK;
}

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
* Service Name: Button_getState
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Parameters (in): u8_bttnID - Index of the button 
* Parameters (inout): None
* Parameters (out): pu8_state - Pointer to the state of the button
* Return value: enuBttn_Status_t - return the status of the function ERROR_OK or NOT_OK
* Description: Function to get the state of the button (Pressed or Released).
*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
Std_ReturnType Button_getState(u8_ButtonChannel_t u8_bttnID, u8_ButtonState_t * pu8_state)
{
/**************************************************************************************/
/*								Start of Error Checking								  */
/**************************************************************************************/
	/* Check if the button index is invalid */
	if (BUTTONS_USED_NUM < u8_bttnID)
	{
		return E_NOT_OK;
	}else{/*Nothing to here*/}
		
	/* Check if the input parameter is NULL */
	if (NULL_PTR == pu8_state)
	{
		return E_NOT_OK;
	}else{/*Nothing to here*/}
	
/**************************************************************************************/
/*								End of Error Checking								  */
/**************************************************************************************/

/**************************************************************************************/
/*								Function Implementation								  */
/**************************************************************************************/
	uint8_t u8_valueTemp=0;
	/* Read the Pin and put its state in the global variable */
	if(Dio_readPin(gau8_buttonsUsed[u8_bttnID], &u8_valueTemp) != DIO_STATUS_ERROR_OK)
		return E_NOT_OK;
	*pu8_state = u8_valueTemp;
	#if 0
	*pu8_state = gu8_ButtonsState[u8_bttnID];
	#endif
	return E_OK;
}

/*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*
* Service Name: Button_updateState
* Sync/Async: Synchronous
* Reentrancy: Non reentrant
* Parameters (in): u8_bttnID - Index of the button
* Parameters (inout): None
* Parameters (out): None
* Return value: enuBttn_Status_t - return the status of the function ERROR_OK or NOT_OK
* Description: Function to update the state of the button (Pressed or Released) by reading the Pin.
*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*/
Std_ReturnType Button_updateState(u8_ButtonChannel_t u8_bttnID)
{
/**************************************************************************************/
/*								Start of Error Checking								  */
/**************************************************************************************/
	/* Check if the button index is invalid */
	if(u8_bttnID > BUTTONS_USED_NUM)
		return E_NOT_OK;
	else{/*Nothing to here*/}
/**************************************************************************************/
/*								End of Error Checking								  */
/**************************************************************************************/

/**************************************************************************************/
/*								Function Implementation								  */
/**************************************************************************************/
	uint8_t u8_valueTemp=0;
	/* Read the Pin and put its state in the global variable */
	if(Dio_readPin(gau8_buttonsUsed[u8_bttnID], &u8_valueTemp) != DIO_STATUS_ERROR_OK)
		return E_NOT_OK;

#if 0
	uint32_t u32_loopIndex = 0;
	if(u8_valueTemp == PIN_HIGH)
	{
		/* De bouncing Delay */
		for(u32_loopIndex=0; u32_loopIndex<3000; u32_loopIndex++);
		/* De bouncing Check */
		if(Dio_readPin(gau8_buttonsUsed[u8_bttnID],&u8_valueTemp) != DIO_STATUS_ERROR_OK)
			return BTTN_STATUS_ERROR_NOK;
		if(u8_valueTemp == PIN_HIGH)
			gu8_ButtonsState[u8_bttnID] = BUTTON_STATE_PRESSED;
	}else if (u8_valueTemp == PIN_LOW)
	{
		/* De bouncing Delay */
		for(u32_loopIndex=0; u32_loopIndex<3000; u32_loopIndex++);
		/* De bouncing Check */
		if(Dio_readPin(gau8_buttonsUsed[u8_bttnID],&u8_valueTemp) != DIO_STATUS_ERROR_OK)
			return BTTN_STATUS_ERROR_NOK;
		if(u8_valueTemp == PIN_LOW)
			gu8_ButtonsState[u8_bttnID] = BUTTON_STATE_RELEASED;
	}
#endif
	return E_OK;
}
