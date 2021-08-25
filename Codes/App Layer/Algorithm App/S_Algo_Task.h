/*******************************************************************************
 * File : S_Algo_Task.h
 * Header File for Task_03 in Sprint_02 S_ALGO_01
 * Binary Search + Insertion Sort
 * Description: Check for the Array if sorted or not
                If not sorted then use Insertion Sorting to sort the array
                Search for number inside an array using Binary Search Algorithm
 *******************************************************************************/

#ifndef _S_ALGO_TASK_H_
#define _S_ALGO_TASK_H_


/**------------------**
 **---- Includes ----**
 **------------------**/
#include <stdlib.h>
#include "Platform_Types.h"


#define ARRAY_UNSORTED      0
#define ARRAY_SORTED        1










/*********************************
 **---- Functions Prototype ----**
 *********************************/

/**** Binary Search ****/
sint16_t Alg_binarySearch(uint32_t* u32_array, uint8_t u8_arraySize, uint32_t u32_number);

/**** Insertion Sort****/
void Alg_insertionSort(uint32_t* pau32_array,uint8_t u8_arraySize);

/**** Check Sorted ****/
uint8_t Alg_checkSorted(uint32_t* pau32_array,uint8_t u8_arraySize);

#endif // _S_ALGO_TASK_H_




