/*
 * Bcm.c
 *
 * Created: 8/25/2021 7:14:41 PM
 *  Author: Ahmed Nabil
 */ 

#include "Bcm.h"

BCM_TxRequestData_t BCM_TxRequests[BCM_COM_DEVICES_USED][BCM_MAX_TX_REQUESTS];

BCM_TxRequestData_t *BCM_TxCurrentRequest[BCM_COM_DEVICES_USED];

uint16_t BCM_TxRequests_Counter[BCM_COM_DEVICES_USED] = {0};
uint16_t BCM_TxRequests_Available[BCM_COM_DEVICES_USED] = {0};
uint16_t BCM_TxRequest_Index[BCM_COM_DEVICES_USED] = {0};
BCM_mainState_t BCM_TxCurrentChannelsState[BCM_COM_DEVICES_USED] = {BCM_MAINFUNC_STATE_IDLE};

uint16_t BCM_dataCounter[BCM_COM_DEVICES_USED] = {0};


Std_ReturnType BCM_init(void)
{
	uint8_t BCM_channelCounter=0;
	
	for(BCM_channelCounter=0; BCM_channelCounter<BCM_COM_DEVICES_USED; BCM_channelCounter++)
	{
		Interrupt_install(BCM_TxConfigurations[BCM_channelCounter].BCM_Tx_INTVector_ID, BCM_TxCallBack_Function);
	}
	
	return E_OK;
}


Std_ReturnType BCM_Transmit(BCM_DeviceID_t BCM_Channel_ID,
							uint8_t *BCM_TxData_ptr,
							uint16_t BCM_TxData_Size, BCM_CallBack_t BCM_CB_Ptr)
{
	uint16_t currentRqCounter = BCM_TxRequests_Counter[BCM_Channel_ID];
	
	if(BCM_TxRequests_Counter[BCM_Channel_ID] == BCM_MAX_TX_REQUESTS)
	{
		if(BCM_TxRequests_Available[BCM_Channel_ID] < BCM_MAX_TX_REQUESTS)
		{
			BCM_TxRequests_Counter[BCM_Channel_ID] = 0;
			currentRqCounter = BCM_TxRequests_Counter[BCM_Channel_ID];
		}
		else
		{
			/* Request will be rejected */
			return E_NOT_OK;
		}
	}
	else
	{
		
	}
	
	BCM_TxRequests[BCM_Channel_ID][currentRqCounter].BCM_ChannelID = BCM_Channel_ID;
	BCM_TxRequests[BCM_Channel_ID][currentRqCounter].BCM_TxRq_Data_ptr = BCM_TxData_ptr;
	BCM_TxRequests[BCM_Channel_ID][currentRqCounter].BCM_TxRq_Data_Size = BCM_TxData_Size;
	BCM_TxRequests[BCM_Channel_ID][currentRqCounter].BCM_TxRq_CB_Ptr = BCM_CB_Ptr;
	BCM_TxRequests[BCM_Channel_ID][currentRqCounter].BCM_TxRq_DataFrame[BCM_ID_INDEX] = BCM_ID;
	BCM_TxRequests[BCM_Channel_ID][currentRqCounter].BCM_TxRq_DataFrame[BCM_ID_INDEX+1] = '\0';
		
	uint8_t dataSize_string[5] = {0};
	integerToString(BCM_TxRequests[BCM_Channel_ID][currentRqCounter].BCM_TxRq_Data_Size, dataSize_string, DEC);
	stringConcatenate(BCM_TxRequests[BCM_Channel_ID][currentRqCounter].BCM_TxRq_DataFrame ,dataSize_string);
	stringConcatenate(BCM_TxRequests[BCM_Channel_ID][currentRqCounter].BCM_TxRq_DataFrame
						, BCM_TxRequests[BCM_Channel_ID][currentRqCounter].BCM_TxRq_Data_ptr);
// 		stringConcatenate(BCM_TxRequests[BCM_Channel_ID][currentRqCounter].BCM_TxRq_DataFrame
// 						, (uint8_t*)"\r");
	BCM_TxRequests[BCM_Channel_ID][currentRqCounter].BCM_TxRq_FrameSize = stringLength(BCM_TxRequests[BCM_Channel_ID][currentRqCounter].BCM_TxRq_DataFrame) -1;
	if (BCM_TxCurrentChannelsState[BCM_Channel_ID] == BCM_MAINFUNC_STATE_IDLE)
	{
		BCM_TxRequests[BCM_Channel_ID][currentRqCounter].BCM_TxRq_State = BCM_REQUEST_TX_SENDING;
		BCM_TxCurrentRequest[BCM_Channel_ID] = &BCM_TxRequests[BCM_Channel_ID][currentRqCounter];
		BCM_TxCurrentChannelsState[currentRqCounter] = BCM_MAINFUNC_STATE_BYTE_SEND;
	}
	else
	{
		BCM_TxRequests[BCM_Channel_ID][currentRqCounter].BCM_TxRq_State = BCM_REQUEST_TX_PENDING;
	}
		
	BCM_TxConfigurations[BCM_Channel_ID].BCM_TxIntEnable(BCM_TxConfigurations[BCM_Channel_ID].BCM_Com_ID);
	BCM_TxRequests_Counter[BCM_Channel_ID]++;
	BCM_TxRequests_Available[BCM_Channel_ID]++;
	
	return E_OK;
}

Std_ReturnType BCM_TxMainFunction(void)
{
	uint8_t BCM_channelCounter=0;
	
	for(BCM_channelCounter=0; BCM_channelCounter<BCM_COM_DEVICES_USED; BCM_channelCounter++)
	{
		switch(BCM_TxCurrentChannelsState[BCM_channelCounter])
		{
			case (BCM_MAINFUNC_STATE_IDLE):
			{
				break;
			}
			case (BCM_MAINFUNC_STATE_BYTE_SEND):
			{
				if(BCM_dataCounter[BCM_channelCounter] != BCM_TxCurrentRequest[BCM_channelCounter]->BCM_TxRq_FrameSize)
				{
					BCM_TxConfigurations[BCM_channelCounter].BCM_TxSender(BCM_TxConfigurations[BCM_channelCounter].BCM_Com_ID
													,BCM_TxCurrentRequest[BCM_channelCounter]->BCM_TxRq_DataFrame[BCM_dataCounter[BCM_channelCounter]]);
					BCM_TxCurrentChannelsState[BCM_channelCounter] = BCM_MAINFUNC_STATE_ISR_WAIT;
				}
				else
				{
					BCM_TxCurrentChannelsState[BCM_channelCounter] = BCM_MAINFUNC_STATE_TX_COMPLETE;
				}
				break;
			}
			case (BCM_MAINFUNC_STATE_ISR_WAIT):
			{
				/* Time Out Looping */
				break;
			}
			case (BCM_MAINFUNC_STATE_TX_COMPLETE):
			{
				BCM_TxRequests_Available[BCM_channelCounter]--;
				BCM_TxCurrentRequest[BCM_channelCounter]->BCM_TxRq_CB_Ptr(NULL);
				BCM_dataCounter[BCM_channelCounter] = 0;
				BCM_cleanRequestData(BCM_TxCurrentRequest[BCM_channelCounter]);
				if(BCM_TxRequests_Available[BCM_channelCounter] > 0)
				{
					if(BCM_TxRequest_Index[BCM_channelCounter] == BCM_MAX_TX_REQUESTS-1)
					{
						BCM_TxRequest_Index[BCM_channelCounter] = 0;
					}
					else
					{
						BCM_TxRequest_Index[BCM_channelCounter]++;
					}
					uint16_t currentRqIndex = BCM_TxRequest_Index[BCM_channelCounter];
					if(BCM_TxRequests[BCM_channelCounter][currentRqIndex].BCM_TxRq_State == BCM_REQUEST_TX_PENDING)
					{
						BCM_TxCurrentRequest[BCM_channelCounter] = &BCM_TxRequests[BCM_channelCounter][currentRqIndex];
						BCM_TxCurrentChannelsState[BCM_channelCounter] = BCM_MAINFUNC_STATE_BYTE_SEND;
					}
					else
					{
						
					}
				}
				else
				{
					BCM_TxCurrentChannelsState[BCM_channelCounter] = BCM_MAINFUNC_STATE_IDLE;
				}
				break;
			}
			default:
			{
				return E_NOT_OK;
			}
		}
	}
	
	return E_OK;
}


void BCM_TxCallBack_Function(uint8_t IntVector_ID)
{
	uint8_t BCM_channelCounter=0;
	
	for(BCM_channelCounter=0; BCM_channelCounter<BCM_COM_DEVICES_USED; BCM_channelCounter++)
	{
		if(BCM_TxConfigurations[BCM_channelCounter].BCM_Tx_INTVector_ID == IntVector_ID)
		{
			BCM_TxCurrentChannelsState[BCM_channelCounter] = BCM_MAINFUNC_STATE_BYTE_SEND;
			BCM_dataCounter[BCM_channelCounter]++;
			return;
		}
		else
		{
			
		}
	}
}

Std_ReturnType BCM_cleanRequestData(BCM_TxRequestData_t *BCM_requestDataPtr)
{
	BCM_requestDataPtr->BCM_ChannelID = 0;
	BCM_requestDataPtr->BCM_TxRq_CB_Ptr = NULL_PTR;
	//BCM_requestDataPtr->BCM_TxRq_Data_ptr = NULL_PTR;
	BCM_requestDataPtr->BCM_TxRq_Data_Size = 0;
	EmptyString(BCM_requestDataPtr->BCM_TxRq_DataFrame);
	BCM_requestDataPtr->BCM_TxRq_State = BCM_REQUEST_TX_CLOSED;
	
	return E_OK;
}