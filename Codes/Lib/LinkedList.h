#ifndef _LINKED_LIST_H_
#define _LINKED_LIST_H_

#include "S_PaymentSys.h"
/****************************************************************
 ********************* Linked List Partition ********************
 ****************************************************************/

typedef struct
{
    strTransactionData_t strTranData;
}str_LinkedList_Data_t;

typedef struct LinkedList_Node
{
    str_LinkedList_Data_t stData;
    struct LinkedList_Node* next;
}str_LinkedList_Node;

typedef struct
{
    str_LinkedList_Node* Head;
    uint32_t Size;
}str_LinkedList;

uint32_t LinkedList_getSize(str_LinkedList * L_list);
str_LinkedList * LinkedList_Create(void);
void LinkedList_Clear(str_LinkedList *L_list);
void LinkedList_PushHead(str_LinkedList* L_list, str_LinkedList_Data_t stNewData);
str_LinkedList_Data_t LinkedList_PopHead(str_LinkedList* L_list);
void LinkedList_PushTail(str_LinkedList* L_list, str_LinkedList_Data_t stNewData);
str_LinkedList_Data_t LinkedList_PopTail(str_LinkedList* L_list);
void LinkedList_InsertNode(str_LinkedList * L_list, uint32_t position, str_LinkedList_Data_t stNewData);
str_LinkedList_Node * LinkedList_positionFind(str_LinkedList * L_list, uint32_t position);

/*********************************************/
/*** Special Functions For the Application ***/
/*********************************************/
str_LinkedList_Node * LinkedList_valueFind(str_LinkedList * L_list, str_LinkedList_Data_t stNewData);
void LinkedList_InsertNode_PANSortedASC(str_LinkedList* L_list, str_LinkedList_Data_t stNewData);
str_LinkedList* LinkedList_MergeLists_SortedASC(str_LinkedList* list1, str_LinkedList* list2);
sint8_t LinkedList_print(str_LinkedList* L_list);




#endif
