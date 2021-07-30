
#include "Test_Cases.h"


/************************************************************************************
 * Description: Structures holds the test cases of the function balancedParentheses.
************************************************************************************/
str_TC_Stack_balancedParentheses_t  astr_TC_Stack_balancedParentheses_TestData[TC_STACK_BALANCED_PARENTHESES_NUM] =
{ /**       au8_TC_ID                   au8_TC_ExpectedResult   pu8_TC_ActualResult      au8_expression         u8_TC_Status **/
    {"TC_Stack_balancedParentheses_01",      "Balanced",             NULL_PTR,        "H{e(l)l}o {W(or)ld}",        NULL},
    {"TC_Stack_balancedParentheses_02",    "Not Balanced",           NULL_PTR,        "H{e{l)l}o )W{or{)ld}",       NULL},

};

