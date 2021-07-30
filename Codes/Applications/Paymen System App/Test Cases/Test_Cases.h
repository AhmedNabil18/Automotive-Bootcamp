#ifndef _TEST_CASES_H_
#define _TEST_CASES_H_

#include <stdio.h>
#include "Test_Cases_Cfg.h"
#include "Platform_Types.h"
#include "S_PaymentSys.h"

#define TC_PASSED       1
#define TC_FAILED       0
#define TC_ERROR_OK     1



typedef uint8_t TC_Error_t;

/************************************************************************************
 * Description: Structure type holds the test case parameters of the
 *              payment system.
************************************************************************************/
typedef struct
{
    uint8_t au8_TC_ID[50];
    uint8_t u8_TC_ExpectedResult;
    uint8_t u8_TC_ActualResult;
    strTransactionData_t str_TC_Data;
    uint8_t u8_TC_Status;
}str_TC_PaymentSys_t;


TC_Error_t TC_ExecuteAndLog(void);
TC_Error_t TC_PaymentSys_StartPaymentSys(void);
TC_Error_t TC_PaymentSys_checkExpiration(void);
TC_Error_t TC_PaymentSys_sendTransToServer(void);
TC_Error_t TC_PaymentSys_processTerminal(void);

#endif // _TEST_CASES_H_
