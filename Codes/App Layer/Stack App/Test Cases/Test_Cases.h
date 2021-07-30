#ifndef _TEST_CASES_H_
#define _TEST_CASES_H_

#include <stdio.h>
#include "S_DS_Task.h"
#include "Test_Cases_Cfg.h"

#define TC_PASSED       1
#define TC_FAILED       0
#define TC_ERROR_OK     1



typedef uint8_t TC_Error_t;

/************************************************************************************
 * Description: Structure type holds the test case parameters of the
 *              function balancedParentheses.
************************************************************************************/
typedef struct
{
    uint8_t au8_TC_ID[50];
    uint8_t au8_TC_ExpectedResult[15];
    uint8_t* pu8_TC_ActualResult;
    uint8_t au8_expression[255];
    uint8_t u8_TC_Status;
}str_TC_Stack_balancedParentheses_t;

TC_Error_t TC_ExecuteAndLog(void);
TC_Error_t TC_Stack_balancedParentheses(void);

#endif // _TEST_CASES_H_
