
#include "S_DS_Task.h"



/*************************************************************************************
* Service Name: balancedParentheses
* Parameters (in): pu8_expression -> Pointer to unsigned char holds an expression
* Parameters (inout): None
* Parameters (out):None
* Return value: uint8_t* -> returns "Balanced" or "Not Balanced".
* Description: Function to check the balance of the parentheses of an input expression.
* *************************************************************************************/
uint8_t* balancedParentheses(uint8_t* pu8_expression)
{
    str_Stack_t * strStackBrackets = DS_stackCreate();

    uint32_t u32loopIndex=0;

    while(pu8_expression[u32loopIndex] != '\0')
    {
        if((pu8_expression[u32loopIndex]=='{') || (pu8_expression[u32loopIndex]=='('))
        {
            DS_stackPush(strStackBrackets, pu8_expression[u32loopIndex]);
        }else if(pu8_expression[u32loopIndex] == '}')
        {
            DS_stackPrint(strStackBrackets);
            if(DS_stackPop(strStackBrackets) != '{')
                return "Not Balanced";
        }else if(pu8_expression[u32loopIndex] == ')')
        {
            DS_stackPrint(strStackBrackets);
            if(DS_stackPop(strStackBrackets) != '(')
                return "Not Balanced";
        }
        u32loopIndex++;
    }
    return "Balanced";

}
