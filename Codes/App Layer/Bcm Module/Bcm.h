/*
 * Bcm.h
 *
 * Created: 8/25/2021 7:15:09 PM
 *  Author: Ahmed Nabil
 */ 


#ifndef BCM_H_
#define BCM_H_

#include "Bcm_LCfg.h"
#include "Microcontroller/Std_types.h"
#include "Microcontroller/Platform_Types.h"
#include "Microcontroller/Interrupt Handler/Interrupt_Interface.h"
#include "Libraries/Utility Module/Utility.h"
/*
 * TX States
 */
#define BCM_MAINFUNC_STATE_IDLE					0U
#define BCM_MAINFUNC_STATE_BYTE_SEND			1U
#define BCM_MAINFUNC_STATE_ISR_WAIT				2U
#define BCM_MAINFUNC_STATE_TX_COMPLETE			3U

/*
 * Request States
 */
#define BCM_REQUEST_TX_CLOSED		0U
#define BCM_REQUEST_TX_PENDING		1U
#define BCM_REQUEST_TX_SENDING		2U
#define BCM_REQUEST_TX_REJECTED		3U


#define BCM_ID				99U
#define BCM_ID_INDEX		0U

typedef uint8_t BCM_DeviceID_t;

typedef void (*BCM_CallBack_t)(uint8_t);

typedef Std_ReturnType (*BCM_DeviceTXFunction)(uint8_t, uint8_t);
typedef Std_ReturnType (*BCM_DeviceTxIntOnOff)(uint8_t);

typedef uint8_t BCM_mainState_t;

typedef struct
{
	BCM_DeviceID_t BCM_Com_ID;
	uint8_t BCM_Tx_INTVector_ID;
	BCM_DeviceTXFunction BCM_TxSender;
	BCM_DeviceTxIntOnOff BCM_TxIntEnable;
	BCM_DeviceTxIntOnOff BCM_TxIntDisable;
}BCM_TxConfig_t;

typedef struct
{
	BCM_DeviceID_t BCM_ChannelID;
	uint8_t *BCM_TxRq_Data_ptr;
	uint8_t BCM_TxRq_Data_Size;
	BCM_CallBack_t BCM_TxRq_CB_Ptr;
	uint8_t BCM_TxRq_State;
	uint8_t BCM_TxRq_DataFrame[20];
	uint8_t BCM_TxRq_FrameSize;
}BCM_TxRequestData_t;

Std_ReturnType BCM_init(void);

Std_ReturnType BCM_Transmit(BCM_DeviceID_t BCM_Channel_ID,
							uint8_t *BCM_TxData_ptr, 
							uint16_t BCM_TxData_Size, BCM_CallBack_t BCM_CB_Ptr);
Std_ReturnType BCM_TxMainFunction(void);

Std_ReturnType BCM_cleanRequestData(BCM_TxRequestData_t *BCM_requestDataPtr);
void BCM_TxCallBack_Function(uint8_t IntVector_ID);
extern const BCM_TxConfig_t BCM_TxConfigurations[BCM_COM_DEVICES_USED];

#endif /* BCM_H_ */