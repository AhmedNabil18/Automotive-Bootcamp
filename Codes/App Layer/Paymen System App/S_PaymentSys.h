/*******************************************************************************
 * File : S_PaymentSys.h
 * Header File for Task_04 in Sprint_02 S_CPP_01
 * Payment System Application
 * Description: ATM Payment System which Reads Card from Client, Check Validity
                of Data, and process a transaction
 *******************************************************************************/

#ifndef _S_PAYMENTSYS_H_
#define _S_PAYMENTSYS_H_


/**------------------**
 **---- Includes ----**
 **------------------**/
#include <stdlib.h>
#include <stdio.h>
#include "Platform_Types.h"
#include "StringManipulation.h"

/**
 ** MACROS and CONSTANTS
 **/
#define PS_TERMINAL_DENIED              0x00
#define PS_TERMINAL_APPROVED            0x01
#define PS_CHECK_EXPIRATION_ERROR       0x02
#define PS_CARD_EXPIRED                 0x03
#define PS_CARD_NOT_EXPIRED             0x04
#define PS_MAX_AMOUNT_EXCEEDED          0x05


#define PS_SERVER_DENIED                0x10
#define PS_SERVER_APPROVED              0x11
#define PS_BALANCE_LOW                  0x12
#define PS_PAN_NOT_FOUND                0x13

#define PS_ERROR_OK                     0xFF
#define PS_ERROR_NOK                     0xAA


#define PS_DATABASE_SIZE                10U


/**
 ** Typedefs
 **/
typedef enum
{
    TRANS_DENIED,
    TRANS_APPROVED
}enTransState_t;

typedef struct
{
    uint8_t au8_cardHolderName[25];
    uint8_t au8_primaryAccountNumber[20];
    uint8_t au8_cardExpirationDate[6];
}strCardData_t;

typedef struct
{
    float32_t f32_transAmount;
    float32_t f32_maxAmount;
    uint8_t au8_transactionDate[11];
}strTerminalData_t;

typedef struct
{
    strCardData_t       stCardD_user;
    strTerminalData_t   stTermD_user;
    enTransState_t      enTransS_user;
}strTransactionData_t;

typedef struct
{
    uint8_t u8_primaryAccountNumber[20];
    float32_t balance;
}strAccountBalance_t;

typedef uint8_t PS_Error_t;


/*********************************
 **---- Functions Prototype ----**
 *********************************/

/**
 ** FUNCTIONS PROTOTYPE
 **/

void PS_ApplicationStart(void);
PS_Error_t PS_StartPaymentSystem(void);
PS_Error_t PS_getCardData(strCardData_t * pstrCD_user);
PS_Error_t PS_getTerminalData(strTerminalData_t * pstrTD_user);
PS_Error_t PS_processTerminal(strCardData_t * pstrCD_user, strTerminalData_t * pstrTD_user);
PS_Error_t PS_checkExpiration(uint8_t* pau8_cardExpirationDate, uint8_t* pau8_transactionDate);
PS_Error_t PS_sendTransactionToServer(strTransactionData_t strTranD_user);
PS_Error_t PS_saveTransaction(strTransactionData_t strTranD_user);

#endif // _S_PAYMENTSYS_H_




