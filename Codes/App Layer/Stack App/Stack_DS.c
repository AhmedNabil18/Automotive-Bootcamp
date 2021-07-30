
#include "Stack_DS.h"



/*************************************************************************************
* Service Name: DS_stackCreate
* Parameters (in): None
* Parameters (inout): None
* Parameters (out):None
* Return value: str_Stack_t * -> Pointer to the created Linked List.
* Description: Function to create a new linked list and return the pointer to this list.
* *************************************************************************************/
str_Stack_t * DS_stackCreate(void)
{
    str_Stack_t * str_Stack = (str_Stack_t *) malloc(sizeof(str_Stack_t));
    str_Stack->Head = NULL_PTR;
    str_Stack->Size = 0;

    return str_Stack;
}

/************************************************************************************
* Service Name: DS_stackDelete
* Parameters (in): pstrStack -> Pointer to a Stack
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to delete a stack.
************************************************************************************/
DS_Error_t DS_stackDelete(str_Stack_t *pstrStack)
{
    if(pstrStack == NULL_PTR)
    {
        return DS_ERROR_STACK_NULL;
    }
    free(pstrStack);
}

/************************************************************************************
* Service Name: DS_stackGetSize
* Parameters (in): pstrStack -> Pointer to a Stack
* Parameters (inout): None
* Parameters (out):None
* Return value: uint32_t -> Size of the Stack (Number of Nodes inside the Stack)
* Description: Function to return the size of the Stack.
************************************************************************************/
uint32_t DS_stackGetSize(str_Stack_t * pstrStack)
{
    return str_Stack->Size;
}

/************************************************************************************
* Service Name: DS_stackPush
* Parameters (in): pstrStack -> Pointer to a Stack
                   newData -> the value of the data will be saved in the new node
* Parameters (inout): None
* Parameters (out):None
* Return value: None
* Description: Function to push a new node at the head of the Stack.
************************************************************************************/
DS_Error_t DS_stackPush(str_Stack_t* pstrStack, uint8_t newData)
{
    if(pstrStack == NULL_PTR)
    {
        return DS_ERROR_STACK_NULL;
    }
    str_StackNode_t * strNode = (str_StackNode_t *) malloc(sizeof(str_StackNode_t));

    strNode->data = newData;
    strNode->next = pstrStack->Head;
    pstrStack->Head = strNode;
    (pstrStack->Size)++;
}

/************************************************************************************
* Service Name: DS_stackPop
* Parameters (in): pstrStack -> Pointer to a Stack.
* Parameters (inout): None
* Parameters (out):None
* Return value: uint8_t -> The value of the data inside the Head node.
* Description: Function to pop the head of the Stack and return its data.
************************************************************************************/
uint8_t DS_stackPop(str_Stack_t* pstrStack)
{
    if(pstrStack == NULL_PTR)
    {
        return DS_ERROR_STACK_NULL;
    }else if(pstrStack->Head == NULL_PTR)
    {
        return DS_ERROR_STACK_EMPTY;
    }
    uint8_t u8_dataPopped = 0;
    str_StackNode_t * strTempNode = pstrStack->Head;
    pstrStack->Head = strTempNode->next;
    u8_dataPopped = strTempNode->data;

    free(strTempNode);
    (pstrStack->Size)--;

    return u8_dataPopped;
}

/************************************************************************************
* Service Name: DS_stackPrint
* Parameters (in): pstrStack -> Pointer to a Stack.
* Parameters (inout): None
* Parameters (out):None
* Return value: None
* Description: Function to print data inside the stack.
************************************************************************************/
DS_Error_t DS_stackPrint(str_Stack_t* pstrStack)
{
    if(pstrStack == NULL_PTR)
    {
        return DS_ERROR_STACK_NULL;
    }else if(pstrStack->Head == NULL_PTR)
    {
        return DS_ERROR_STACK_EMPTY;
    }
    str_StackNode_t * strTempNode = pstrStack->Head;
    do
    {
        printf("%c\n", strTempNode->data);
        strTempNode = strTempNode->next;
    }while(strTempNode != NULL_PTR);
}


