
#include "Test_Cases.h"
#include "Test_Cases_Cfg.h"
#include "S_PaymentSys.h"

extern str_TC_PaymentSys_t  astr_TC_PaymentSys_TestData[TC_PAYSYS_NUM];

TC_Error_t TC_ExecuteAndLog(void)
{
    TC_Error_t returnError = TC_ERROR_OK;

    returnError = TC_PaymentSys_StartPaymentSys();
    returnError = TC_PaymentSys_checkExpiration();
    returnError = TC_PaymentSys_sendTransToServer();
    returnError = TC_PaymentSys_processTerminal();

    return returnError;
}

TC_Error_t TC_PaymentSys_StartPaymentSys(void)
{
    str_TC_PaymentSys_t* pstr_TC_Data= NULL_PTR;
    /*
     * Test Case Execution
     */
    pstr_TC_Data = &astr_TC_PaymentSys_TestData[TC_STRT_PAY_SYS_01];

    pstr_TC_Data->u8_TC_ActualResult = PS_StartPaymentSystem(&(pstr_TC_Data->str_TC_Data));

    /*
     * Log the Results
     */
    /*
     * Test Case Result
     */
    if(pstr_TC_Data->u8_TC_ActualResult == pstr_TC_Data->u8_TC_ExpectedResult)
    {
        pstr_TC_Data->u8_TC_Status = TC_PASSED;
        printf("%s Passed\n", pstr_TC_Data->au8_TC_ID);
    }else{
        pstr_TC_Data->u8_TC_Status = TC_FAILED;
        printf("%s Failed\n", pstr_TC_Data->au8_TC_ID);
    }

    return TC_ERROR_OK;
}


TC_Error_t TC_PaymentSys_checkExpiration(void)
{
    str_TC_PaymentSys_t* pstr_TC_Data= NULL_PTR;
    /*
     * Test Case Execution
     */
    pstr_TC_Data = &astr_TC_PaymentSys_TestData[TC_CHK_EXPIRY_01];

    pstr_TC_Data->u8_TC_ActualResult = PS_checkExpiration(pstr_TC_Data->str_TC_Data.stCardD_user.au8_cardExpirationDate,\
                                                           pstr_TC_Data->str_TC_Data.stTermD_user.au8_transactionDate);

    /*
     * Log the Results
     */
    /*
     * Test Case Result
     */
    if(pstr_TC_Data->u8_TC_ActualResult == pstr_TC_Data->u8_TC_ExpectedResult)
    {
        pstr_TC_Data->u8_TC_Status = TC_PASSED;
        printf("%s Passed\n", pstr_TC_Data->au8_TC_ID);
    }else{
        pstr_TC_Data->u8_TC_Status = TC_FAILED;
        printf("%s Failed\n", pstr_TC_Data->au8_TC_ID);
    }

    return TC_ERROR_OK;
}


TC_Error_t TC_PaymentSys_sendTransToServer(void)
{
    str_TC_PaymentSys_t* pstr_TC_Data= NULL_PTR;
    /*********************************************************/
    /** Test Case 3 TC_PaymentSys_sendTransactionToServer_01 **/
    /*
     * Test Case Execution
     */
    pstr_TC_Data = &astr_TC_PaymentSys_TestData[TC_SEND_TRANS_SERVER_01];

    pstr_TC_Data->u8_TC_ActualResult = PS_sendTransactionToServer(pstr_TC_Data->str_TC_Data);

    /*
     * Log the Results
     */
    /*
     * Test Case Result
     */
    if(pstr_TC_Data->u8_TC_ActualResult == pstr_TC_Data->u8_TC_ExpectedResult)
    {
        pstr_TC_Data->u8_TC_Status = TC_PASSED;
        printf("%s Passed\n", pstr_TC_Data->au8_TC_ID);
    }else{
        pstr_TC_Data->u8_TC_Status = TC_FAILED;
        printf("%s Failed\n", pstr_TC_Data->au8_TC_ID);
    }

    /*********************************************************/
    /** Test Case 4 TC_PaymentSys_sendTransactionToServer_02 **/
    pstr_TC_Data = &astr_TC_PaymentSys_TestData[TC_SEND_TRANS_SERVER_02];

    pstr_TC_Data->u8_TC_ActualResult = PS_sendTransactionToServer(pstr_TC_Data->str_TC_Data);

    /*
     * Log the Results
     */
    /*
     * Test Case Result
     */
    if(pstr_TC_Data->u8_TC_ActualResult == pstr_TC_Data->u8_TC_ExpectedResult)
    {
        pstr_TC_Data->u8_TC_Status = TC_PASSED;
        printf("%s Passed\n", pstr_TC_Data->au8_TC_ID);
    }else{
        pstr_TC_Data->u8_TC_Status = TC_FAILED;
        printf("%s Failed\n", pstr_TC_Data->au8_TC_ID);
    }

    return TC_ERROR_OK;
}

TC_Error_t TC_PaymentSys_processTerminal(void)
{
    str_TC_PaymentSys_t* pstr_TC_Data= NULL_PTR;
    /*
     * Test Case Execution
     */
    pstr_TC_Data = &astr_TC_PaymentSys_TestData[TC_PROCESS_TERMINAL_01];

    pstr_TC_Data->u8_TC_ActualResult = PS_processTerminal(&(pstr_TC_Data->str_TC_Data.stCardD_user),\
                                                          &(pstr_TC_Data->str_TC_Data.stTermD_user));

    /*
     * Log the Results
     */
    /*
     * Test Case Result
     */
    if(pstr_TC_Data->u8_TC_ActualResult == pstr_TC_Data->u8_TC_ExpectedResult)
    {
        pstr_TC_Data->u8_TC_Status = TC_PASSED;
        printf("%s Passed\n", pstr_TC_Data->au8_TC_ID);
    }else{
        pstr_TC_Data->u8_TC_Status = TC_FAILED;
        printf("%s Failed\n", pstr_TC_Data->au8_TC_ID);
    }

    return TC_ERROR_OK;
}
