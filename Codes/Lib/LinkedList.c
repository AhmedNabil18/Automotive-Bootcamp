#include <stdlib.h>
#include <stdio.h>
#include "Platform_Types.h"
#include "LinkedList.h"



/****************************************************************
 ********************* Linked List Partition ********************
 ****************************************************************/


/*************************************************************************************
* Service Name: LinkedList_Create
* Parameters (in): None
* Parameters (inout): None
* Parameters (out):None
* Return value: str_LinkedList * -> Pointer to the created Linked List.
* Description: Function to create a new linked list and return the pointer to this list.
* *************************************************************************************/
str_LinkedList * LinkedList_Create(void)
{
    str_LinkedList * L_list = (str_LinkedList *) malloc(sizeof(str_LinkedList));
    L_list->Head = NULL_PTR;
    L_list->Size = 0;
    return L_list;
}

/************************************************************************************
* Service Name: LinkedList_Clear
* Parameters (in): L_list -> Pointer to a Linked List
* Parameters (inout): None
* Parameters (out): None
* Return value: None
* Description: Function to clear an already created linked list.
************************************************************************************/
void LinkedList_Clear(str_LinkedList *L_list)
{
    free(L_list);
}

/************************************************************************************
* Service Name: LinkedList_getSize
* Parameters (in): L_list -> Pointer to a Linked List
* Parameters (inout): None
* Parameters (out):None
* Return value: uint32_t -> Size of the Linked List (Number of Node inside the Linked List)
* Description: Function to return the size of the linked list.
************************************************************************************/
uint32_t LinkedList_getSize(str_LinkedList * L_list)
{
    uint32_t u32_loopIndex=1;
    str_LinkedList_Node * node = L_list->Head;
    if(L_list->Head == NULL_PTR) return 0;
    while(node->next != NULL_PTR)
    {
        node = node->next;
        u32_loopIndex++;
    }
    return u32_loopIndex;
}

/************************************************************************************
* Service Name: LinkedList_PushHead
* Parameters (in): L_list -> Pointer to a Linked List
                   stNewData -> Structure contains the new Data of the node
* Parameters (inout): None
* Parameters (out):None
* Return value: None
* Description: Function to insert a new node with a new data structure at the head of the linked list.
************************************************************************************/
void LinkedList_PushHead(str_LinkedList* L_list, str_LinkedList_Data_t stNewData)
{
    str_LinkedList_Node* node = (str_LinkedList_Node*)malloc(sizeof(str_LinkedList_Node));

    node->stData = stNewData;
    node->next = L_list->Head;
    L_list->Head = node;
    L_list->Size++;
}

/************************************************************************************
* Service Name: LinkedList_PopHead
* Parameters (in): L_list -> Pointer to a Linked List.
* Parameters (inout): None
* Parameters (out):None
* Return value: str_LinkedList_Data_t -> Structure contains the Data inside the Head node.
* Description: Function to pop the head node in the linked list and return its data.
************************************************************************************/
str_LinkedList_Data_t LinkedList_PopHead(str_LinkedList* L_list)
{
    if(L_list->Head == NULL_PTR)
    {
        printf("Error, There are no nodes in this list to pop");
    }
    str_LinkedList_Node *node = L_list->Head;
    str_LinkedList_Data_t stOldData = node->stData;

    L_list->Head = node->next;
    L_list->Size--;
    free(node);

    return stOldData;
}

/************************************************************************************
* Service Name: LinkedList_PushTail
* Parameters (in): L_list -> Pointer to a Linked List
                   stNewData -> Structure contains the new Data of the node
* Parameters (inout): None
* Parameters (out):None
* Return value: None
* Description: Function to insert a new node with a new data value at the tail of the linked list.
************************************************************************************/
void LinkedList_PushTail(str_LinkedList* L_list, str_LinkedList_Data_t stNewData)
{
    str_LinkedList_Node* node = (str_LinkedList_Node*)malloc(sizeof(str_LinkedList_Node));

    node->stData = stNewData;
    node->next = NULL_PTR;

    if(L_list->Head == NULL_PTR) L_list->Head = node;
    else
    {
        str_LinkedList_Node* temp_node= L_list->Head;

        while(temp_node->next != NULL_PTR)
            temp_node = temp_node->next;

        temp_node->next = node;
    }
    L_list->Size++;
}

/************************************************************************************
* Service Name: LinkedList_PopTail
* Parameters (in): L_list -> Pointer to a Linked List.
* Parameters (inout): None
* Parameters (out):None
* Return value: str_LinkedList_Data_t -> Structure contains the Data inside the Tail node.
* Description: Function to pop the tail node in the linked list and return its data.
************************************************************************************/
str_LinkedList_Data_t LinkedList_PopTail(str_LinkedList* L_list)
{
    if(L_list->Head == NULL_PTR)
    {
        printf("Error, There are no nodes in this list to pop");
    }
    str_LinkedList_Node * node = L_list->Head;
    str_LinkedList_Node * node2 = NULL_PTR;
    while(node->next != NULL_PTR)
    {
        node2 = node;
        node = node->next;
    }

    str_LinkedList_Data_t stOldData = node->stData;

    if(node2 == NULL_PTR)
        L_list->Head = NULL_PTR;
    else
        node2->next = NULL_PTR;
    free(node);
    L_list->Size--;
    return stOldData;
}

/************************************************************************************
* Service Name: LinkedList_InsertNode
* Parameters (in): L_list -> Pointer to a Linked List.
                   position -> The index or the position of the node to be inserted.
                   stNewData -> Structure contains the new Data of the node
* Parameters (inout): None
* Parameters (out):None
* Return value: None.
* Description: Function to insert a new node in a specific position inside the linked list.
************************************************************************************/
void LinkedList_InsertNode(str_LinkedList * L_list, uint32_t position, str_LinkedList_Data_t stNewData)
{
    if(position > (L_list->Size+1))
    {
        printf("Error, no such position %d in this list \n", position);
        return;
    }else if((position == (L_list->Size+1)) || (L_list->Size == 0))
    {
        LinkedList_PushTail(L_list, stNewData);
        return;
    }else if(position == 1)
    {
        LinkedList_PushHead(L_list, stNewData);
        return;
    }
    str_LinkedList_Node *left=L_list->Head, *right=NULL_PTR;

    while(position != 2 && --position) left = left->next;
    right = left->next;

    str_LinkedList_Node * node = (str_LinkedList_Node *)malloc(sizeof(str_LinkedList_Node));
    node->stData = stNewData;
    node->next = right;
    left->next = node;
    L_list->Size++;
}

/************************************************************************************
* Service Name: LinkedList_positionFind
* Parameters (in): L_list -> Pointer to a Linked List.
                   position -> The position of the node that will be searched for.
* Parameters (inout): None
* Parameters (out):None
* Return value: str_LinkedList_Node -> Pointer to the node that located in this position.
* Description: Function used to search for a node in a given position.
************************************************************************************/
str_LinkedList_Node * LinkedList_positionFind(str_LinkedList * L_list, uint32_t position)
{
    if(L_list->Size == 0 || position > L_list->Size) return NULL_PTR;
    str_LinkedList_Node * node = L_list->Head;

    while(--position)
        node = node->next;

    return node;
}

/*********************************************/
/*** Special Functions For the Application ***/
/*********************************************/


/************************************************************************************
* Service Name: LinkedList_valueFind
* Parameters (in): L_list -> Pointer to a Linked List.
                   value -> The value that will be searched for.
* Parameters (inout): None
* Parameters (out):None
* Return value: str_LinkedList_Node -> Pointer to the node that holds the value.
* Description: Function used to search for a given value if it's in the linked list or not.
************************************************************************************/
/*str_LinkedList_Node * LinkedList_valueFind(str_LinkedList * L_list, str_LinkedList_Data_t stFindData)
{
    if(L_list->Size == 0) return NULL_PTR;
    str_LinkedList_Node * node = L_list->Head;

    while(node->stData != stFindData)
    {
        if(node->next == NULL_PTR) return NULL_PTR;
        node = node->next;
    }
    return node;
}*/


/************************************************************************************
* Service Name: LinkedList_InsertNode_SortedASC
* Parameters (in): L_list -> Pointer to a Linked List.
                   stNewData -> Structure contains the new Data of the node
* Parameters (inout): None
* Parameters (out):None
* Return value: None
* Description: Function used to insert a new node in an ascending sorted linked list.
************************************************************************************/
void LinkedList_InsertNode_PANSortedASC(str_LinkedList* L_list, str_LinkedList_Data_t stNewData)
{
    if(L_list->Size == 0)
    {
        LinkedList_PushTail(L_list, stNewData);
        return;
    }
    str_LinkedList_Node *node = L_list->Head;
    uint8_t maxValue = 0;
    maxValue = Max_String_Num(stNewData.strTranData.stCardD_user.au8_primaryAccountNumber,\
                              node->stData.strTranData.stCardD_user.au8_primaryAccountNumber);

    if(maxValue == 2)
    {
        LinkedList_PushHead(L_list, stNewData);
        return;
    }

    uint32_t index = 2;
    node = node->next;

    maxValue = Max_String_Num(stNewData.strTranData.stCardD_user.au8_primaryAccountNumber,\
                                  node->stData.strTranData.stCardD_user.au8_primaryAccountNumber);
    while(maxValue == 1)
    {
        maxValue = Max_String_Num(stNewData.strTranData.stCardD_user.au8_primaryAccountNumber,\
                                  node->stData.strTranData.stCardD_user.au8_primaryAccountNumber);
        index++;
        node = node->next;
        if(node == NULL_PTR) break;
    }
    LinkedList_InsertNode(L_list, index, stNewData);
}


/************************************************************************************
* Service Name: LinkedList_MergeLists_SortedASC
* Parameters (in): list1 -> Pointer to the first sorted linked list.
                   list2 -> Pointer to the second sorted linked list.
* Parameters (inout): None
* Parameters (out):None
* Return value: str_LinkedList* -> A pointer to the new sorted linked list.
* Description: Function used to merge two sorted linked lists to a new sorted list.
************************************************************************************/
/*str_LinkedList* LinkedList_MergeLists_SortedASC(str_LinkedList* list1, str_LinkedList* list2)
{
    if((list1 == NULL_PTR) || (list1->Size == 0)) return list2;
    else if((list2 == NULL_PTR)  || (list2->Size == 0)) return list1;
    else if(((list1 == NULL_PTR) && (list2 == NULL_PTR))
            || ((list1->Size == 0) && (list2->Size == 0)))
                return NULL_PTR;

    str_LinkedList *merged = LinkedList_Create();
    int merged_index=1;
    int merged_size= list1->Size + list2->Size;

    str_LinkedList_Node* node1 = list1->Head;
    str_LinkedList_Node* node2 = list2->Head;

    while(--merged_size)
    {

        if((node1->data) < (node2->data))
        {
            LinkedList_InsertNode(merged, merged_index++, node1->data);
            node1=node1->next;
        }else
        {
            LinkedList_InsertNode(merged, merged_index++, node2->data);
            node2=node2->next;
        }
    }
}*/

sint8_t LinkedList_print(str_LinkedList* L_list)
{
    if(L_list == NULL_PTR)
    {
        return -1;
    }else if(L_list->Head == NULL_PTR)
    {
        return -2;
    }
    str_LinkedList_Node * strTempNode = L_list->Head;
    do
    {
        printf("%s\n", strTempNode->stData.strTranData.stCardD_user.au8_cardHolderName);
        strTempNode = strTempNode->next;
    }while(strTempNode != NULL_PTR);
    return 0;
}
