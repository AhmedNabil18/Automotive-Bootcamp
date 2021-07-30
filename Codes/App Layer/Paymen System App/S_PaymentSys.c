/*******************************************************************************
 * File : S_PaymentSys.c
 * Source File for Task_04 in Sprint_02 S_CPP_01
 * Payment System Application
 * Description: ATM Payment System which Reads Card from Client, Check Validity
                of Data, and process a transaction
 *******************************************************************************/


/**------------------**
 **---- Includes ----**
 **------------------**/
#include "S_PaymentSys.h"
#include "LinkedList.h"

/**
 ** GLOBAL VARIABLES
 **/

/*** Server Data Base --- Array of structures holds user PAN and Balance ***/
strAccountBalance_t  gastr_ServerDataBase[PS_DATABASE_SIZE] =
{
    {"123456789",100.0},{"234567891",6000.0},{"567891234",3250.25},{"456789123",1500.12},
    {"258649173",500.0},{"654823719",2100.0},{"971362485",0.0},{"793148625",1.0},
    {"123123456",10.12},{"456789321",0.55}
};

/*** Transaction Data Base --- LinkedList holds the transactions done ***/
str_LinkedList gstrLnkLst_TransactionDataBase;

/**************************************
 **---- Functions Implementation ----**
 **************************************/

/*************************************************************************************
* Service Name: PS_StartPaymentSystem
* Parameters (in): None
* Parameters (inout): None
* Parameters (out):None
* Return value: PS_Error_t -> State of the function returned with PS_ERROR_OK or PS_ERROR_NOK
* Description: Function to Start the Payment System Application
* *************************************************************************************/
PS_Error_t PS_StartPaymentSystem(void)
{
    /********************************************************
     **** Create a Transaction Data Base with LinkedList ****
     ********************************************************/
    gstrLnkLst_TransactionDataBase = LinkedList_Create();

    strCardData_t stCardD_User1;
    strCardData_t* pstCardD_User1 = &stCardD_User1;

    strTerminalData_t stTermD_User1;
    strTerminalData_t* pstTermD_User1 = &stTermD_User1;

    strTransactionData_t strTransD_user;

    PS_getCardData(pstCardD_User1);
    PS_getTerminalData(pstTermD_User1);

    strTransD_user.stCardD_user = stCardD_User1;
    strTransD_user.stTermD_user = stTermD_User1;
    strTransD_user.enTransS_user = TRANS_DENIED;

    if(PS_processTerminal(pstCardD_User1, pstTermD_User1) != PS_TERMINAL_APPROVED)
    {
        PS_sendTransactionToServer(strTransD_user);
        return PS_ERROR_NOK;
    }

    strTransD_user.enTransS_user = TRANS_APPROVED;
    if(PS_sendTransactionToServer(strTransD_user) != PS_SERVER_APPROVED)
        return PS_ERROR_NOK;
    return PS_ERROR_OK;
}

/*************************************************************************************
* Service Name: PS_sendTransactionToServer
* Parameters (in): strTranD_user -> structure hold the transaction data.
* Parameters (inout): None
* Parameters (out):None
* Return value: PS_Error_t -> State of the function returned with PS_SERVER_APPROVED,
*                             PS_BALANCE_LOW, PS_PAN_NOT_FOUND or PS_ERROR_OK.
* Description: Function to send data to the server and process it.
* *************************************************************************************/
PS_Error_t PS_sendTransactionToServer(strTransactionData_t strTranD_user)
{
    uint8_t u8_userIndexInDataBase=0;

    if(strTranD_user.enTransS_user == TRANS_DENIED)
    {
        /**
         ** If the process was denied by the terminal
         ** Continue and save the transaction with the denial.
         **/
        PS_saveTransaction(strTranD_user);
    }else
    {
        /**
         ** Check if PAN exists
         **/
        for(u8_userIndexInDataBase=0; u8_userIndexInDataBase<PS_DATABASE_SIZE; u8_userIndexInDataBase++)
        {
            if(stringCompare( strTranD_user.stCardD_user.au8_primaryAccountNumber, \
                              gastr_ServerDataBase[u8_userIndexInDataBase].u8_primaryAccountNumber))
            {
                strTranD_user.enTransS_user = TRANS_APPROVED;
                break;
            }else
            {
                strTranD_user.enTransS_user = TRANS_DENIED;
            }
        }
        if(strTranD_user.enTransS_user == TRANS_DENIED)
        {
            PS_saveTransaction(strTranD_user);
            return PS_PAN_NOT_FOUND;
        }
        /**
         ** Check if Balance enough
         **/
        if(gastr_ServerDataBase[u8_userIndexInDataBase].balance < strTranD_user.stTermD_user.f32_transAmount)
        {
            strTranD_user.enTransS_user = TRANS_DENIED;
            PS_saveTransaction(strTranD_user);
            return PS_BALANCE_LOW;
        }else
        {
            printf("Successful Transaction\n");
            strTranD_user.enTransS_user = TRANS_APPROVED;
            PS_saveTransaction(strTranD_user);
            return PS_SERVER_APPROVED;
        }
    }
}

/*************************************************************************************
* Service Name: PS_saveTransaction
* Parameters (in): strTranD_user -> structure hold the transaction data.
* Parameters (inout): None
* Parameters (out):None
* Return value: PS_Error_t -> State of the function returned with PS_SERVER_APPROVED,
                              PS_BALANCE_LOW, PS_PAN_NOT_FOUND or PS_ERROR_OK.
* Description: Function to save transaction data in the server.
* *************************************************************************************/
PS_Error_t PS_saveTransaction(strTransactionData_t strTranD_user)
{
    str_LinkedList_Data_t strLnkdLst_TransData = {strTranD_user};
    LinkedList_InsertNode_PANSortedASC(gstrLnkLst_TransactionDataBase,\
                                       strLnkdLst_TransData);
    return PS_ERROR_OK;
}

/*************************************************************************************
* Service Name: PS_getCardData
* Parameters (in): None
* Parameters (inout): None
* Parameters (out):pstrCD_user -> pointer to structure that holds the card's data.
* Return value: PS_Error_t -> State of the function returned with PS_ERROR_OK or PS_ERROR_NOK
* Description: Function to get Data of the card and send it to the system.
* *************************************************************************************/
PS_Error_t PS_getCardData(strCardData_t * pstrCD_user)
{
    printf("Please Insert your Name: ");
    gets(pstrCD_user->au8_cardHolderName);

    printf("Please Insert your Card Number:");
    gets(pstrCD_user->au8_primaryAccountNumber);

    printf("Please Insert Expiry Date: ");
    gets(pstrCD_user->au8_cardExpirationDate);

    return PS_ERROR_OK;
}

/*************************************************************************************
* Service Name: PS_getTerminalData
* Parameters (in): None
* Parameters (inout): None
* Parameters (out):pstrTD_user -> pointer to structure that holds the terminal's data.
* Return value: PS_Error_t -> State of the function returned with PS_ERROR_OK or PS_ERROR_NOK
* Description: Function to get Data of the terminal and send it to the system.
* *************************************************************************************/
PS_Error_t PS_getTerminalData(strTerminalData_t * pstrTD_user)
{
    pstrTD_user->f32_maxAmount = 8000.0;
    printf("Please Insert Amount in EGP: ");
    scanf(" %f",&(pstrTD_user->f32_transAmount));
    gets(pstrTD_user->au8_transactionDate);
    printf("Please Insert the Transaction Date: ");
    gets(pstrTD_user->au8_transactionDate);

    return PS_ERROR_OK;
}

/*************************************************************************************
* Service Name: PS_processTerminal
* Parameters (in): pstrCD_user -> pointer to structure that hold the Card's data.
*                  pstrTD_user -> pointer to structure that hold the Terminal's data.
* Parameters (inout): None
* Parameters (out):None
* Return value: PS_Error_t -> State of the function returned with PS_CHECK_EXPIRATION_ERROR,
                              PS_MAX_AMOUNT_EXCEEDED or PS_TERMINAL_APPROVED.
* Description: Function to process the data from the terminal and check its validity.
* *************************************************************************************/
PS_Error_t PS_processTerminal(strCardData_t * pstrCD_user, strTerminalData_t * pstrTD_user)
{
    PS_Error_t returnValue=0;
    /**********************************/
    /**
     ** Expiration Check
     **/
    returnValue = PS_checkExpiration(pstrCD_user->au8_cardExpirationDate, pstrTD_user->au8_transactionDate);
    switch(returnValue)
    {
    case PS_CARD_EXPIRED:
        printf("Your Card is Expired\n");
        return PS_CHECK_EXPIRATION_ERROR;
    case PS_CARD_NOT_EXPIRED:
        break;
    default:
        return PS_CHECK_EXPIRATION_ERROR;
    }
    /**********************************/
    /**
     ** Amount Check
     **/
    if((pstrTD_user->f32_maxAmount) < (pstrTD_user->f32_transAmount))
        return PS_MAX_AMOUNT_EXCEEDED;
    else{/** Continue Processing **/}
    /**********************************/
    return PS_TERMINAL_APPROVED;
}

/*************************************************************************************
* Service Name: PS_checkExpiration
* Parameters (in): pau8_cardExpirationDate -> pointer to an array that holds the expiry date.
*                  pau8_transactionDate -> pointer to an array that holds the transaction date.
* Parameters (inout): None
* Parameters (out):None
* Return value: PS_Error_t -> State of the function returned with PS_CARD_EXPIRED, PS_CARD_NOT_EXPIRED
                              or PS_CHECK_EXPIRATION_ERROR.
* Description: Function to check if the card expired or not.
* *************************************************************************************/
PS_Error_t PS_checkExpiration(uint8_t* pau8_cardExpirationDate, uint8_t* pau8_transactionDate)
{
    uint8_t u8_Year = ((pau8_transactionDate[8]-'0')*10) + (pau8_transactionDate[9]-'0');
    uint8_t u8_expiryYear = ((pau8_cardExpirationDate[3]-'0')*10) + (pau8_cardExpirationDate[4]-'0');

    if(u8_Year > u8_expiryYear) return PS_CARD_EXPIRED;
    else if(u8_Year < u8_expiryYear) return PS_CARD_NOT_EXPIRED;
    else
    {
        uint8_t u8_Month = ((pau8_transactionDate[3]-'0')*10) + (pau8_transactionDate[4]-'0');
        uint8_t u8_expiryMonth = ((pau8_cardExpirationDate[0]-'0')*10) + (pau8_cardExpirationDate[1]-'0');
        if(u8_Month > u8_expiryMonth) return PS_CARD_EXPIRED;
        else if(u8_Month < u8_expiryMonth) return PS_CARD_NOT_EXPIRED;
    }
    return PS_CHECK_EXPIRATION_ERROR;
}


void PS_ApplicationStart(void)
{
    uint8_t User_Answer='N';
    volatile uint8_t* buffer= NULL_PTR;
    do
    {
        if(PS_StartPaymentSystem() == PS_ERROR_NOK)
        {
            printf("Transaction Failed\n");
        }
        printf("Do you want to continue? (Y/N)\n");
        //scanf(" %c",&User_Answer);
        gets(&User_Answer);
    }while(User_Answer == 'Y');
    LinkedList_print(gstrLnkLst_TransactionDataBase);
}
