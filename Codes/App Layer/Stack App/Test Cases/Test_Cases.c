
#include "Test_Cases.h"
#include "Test_Cases_Cfg.h"

extern str_TC_Stack_balancedParentheses_t  astr_TC_Stack_balancedParentheses_TestData[TC_STACK_BALANCED_PARENTHESES_NUM];


TC_Error_t TC_ExecuteAndLog(void)
{
    TC_Error_t returnError = TC_ERROR_OK;

    returnError = TC_Stack_balancedParentheses();

    return returnError;
}

TC_Error_t TC_Stack_balancedParentheses(void)
{
    uint16_t u16_loopIndex=0;
    str_TC_Stack_balancedParentheses_t* pstr_TC_Data= NULL_PTR;

    /*
     * Test Case Execution
     */
    for(u16_loopIndex=0; u16_loopIndex<TC_STACK_BALANCED_PARENTHESES_NUM; u16_loopIndex++)
    {
        pstr_TC_Data = &astr_TC_Stack_balancedParentheses_TestData[u16_loopIndex];


        pstr_TC_Data->pu8_TC_ActualResult = balancedParentheses(pstr_TC_Data->au8_expression);
    }
    /*
     * Log the Results
     */
    for(u16_loopIndex=0; u16_loopIndex<TC_STACK_BALANCED_PARENTHESES_NUM; u16_loopIndex++)
    {
        pstr_TC_Data = &astr_TC_Stack_balancedParentheses_TestData[u16_loopIndex];
        /*
         * Test Case Result
         */
        if(*(pstr_TC_Data->pu8_TC_ActualResult) == pstr_TC_Data->au8_TC_ExpectedResult[0])
        {
            pstr_TC_Data->u8_TC_Status = TC_PASSED;
            printf("%s Passed\n", pstr_TC_Data->au8_TC_ID);
        }else{
            pstr_TC_Data->u8_TC_Status = TC_FAILED;
            printf("%s Failed\n", pstr_TC_Data->au8_TC_ID);
        }
    }

    return TC_ERROR_OK;
}

