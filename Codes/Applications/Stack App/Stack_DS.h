#ifndef _STACK_DS_H_
#define _STACK_DS_H_

#include <stdlib.h>
#include "Platform_Types.h"

/****************************************************************
 ********************* Stack With Linked List *******************
 ****************************************************************/

#define DS_ERROR_STACK_NULL     0xAA
#define DS_ERROR_STACK_EMPTY    0xBB


typedef uint8_t DS_Error_t;
typedef struct StackNode
{
    uint8_t data;
    struct Stack_Node* next;
}str_StackNode_t;

typedef struct
{
    str_StackNode_t* Head;
    uint32_t Size;
}str_Stack_t;

str_Stack_t * DS_stackCreate(void);
uint32_t DS_stackGetSize(str_Stack_t * pstrStack);
DS_Error_t DS_stackPush(str_Stack_t* pstrStack, uint8_t newData);
uint8_t DS_stackPop(str_Stack_t* pstrStack);
DS_Error_t DS_stackDelete(str_Stack_t *pstrStack);
DS_Error_t DS_stackPrint(str_Stack_t* pstrStack);

#endif // _STACK_DS_H_
