/*******************************************************************************
 * File : S_Algo_Task.c
 * Source File for Task_03 in Sprint_02 S_ALGO_01
 * Binary Search + Insertion Sort
 * Description: Check for the Array if sorted or not
                If not sorted then use Insertion Sorting to sort the array
                Search for number inside an array using Binary Search Algorithm
 *******************************************************************************/


/**------------------**
 **---- Includes ----**
 **------------------**/
#include "S_Algo_Task.h"




/**************************************
 **---- Functions Implementation ----**
 **************************************/

/*************************************************************************************
* Service Name: Alg_binarySearch
* Parameters (in): pau32_array -> Pointer to array of data to search in.
*                  u8_arraySize -> Size of the array pau32_array.
*                  u32_number -> The number to be searched.
* Parameters (inout): None
* Parameters (out):None
* Return value: uint8_t -> unsigned character returns the index of the u32_number.
*                          (-1) returned if the u32_number not found.
* Description: Function to search for u32_number inside the pau32_array and return its index
*              if found, otherwise returns (-1).
* *************************************************************************************/
sint16_t Alg_binarySearch(uint32_t* pau32_array, uint8_t u8_arraySize, uint32_t u32_number)
{
    if(Alg_checkSorted(pau32_array, u8_arraySize) == ARRAY_UNSORTED)
    {
        Alg_insertionSort(pau32_array, u8_arraySize);

    }else
    {
        /*
         * Array is already sorted
         * Start Search
         */
    }

    /*
     * Binary Searching
     *///12345678910

    if(u8_arraySize<2 && u32_number!=pau32_array[0]) return -1;

    uint8_t u8_middleIndex;
    uint8_t u8_startIndex,u8_endIndex,u8_newSize;
    sint16_t s8_returnValue;

    if(u8_arraySize%2 == 0) u8_middleIndex=u8_arraySize/2;
    else u8_middleIndex=(u8_arraySize-1)/2;

    if(u32_number == pau32_array[u8_middleIndex]) return u8_middleIndex;
    else if(u32_number<pau32_array[u8_middleIndex])
    {

        u8_startIndex=0;
        u8_endIndex=u8_middleIndex-1;
        u8_newSize=u8_endIndex+1;

        return Alg_binarySearch(&pau32_array[0],u8_newSize,u32_number);
    }
    else
    {
        if(u8_arraySize == 2) return -1;
        u8_startIndex=u8_middleIndex+1;
        u8_endIndex=u8_arraySize-1;
        u8_newSize=u8_endIndex-u8_startIndex+1;

        s8_returnValue = Alg_binarySearch(&pau32_array[u8_middleIndex+1],u8_newSize,u32_number);
        if(s8_returnValue==-1) return s8_returnValue;
        return s8_returnValue+u8_startIndex;
    }
    return 0;
}


/*************************************************************************************
* Service Name: Alg_insertionSort
* Parameters (in): pau32_array -> Pointer to array of data to be sorted.
*                  u8_arraySize -> Size of the array pau32_array.
* Parameters (inout): None
* Parameters (out):None
* Return value: None
* Description: Function to sort the array pau32_array according to Insertion Sorting Algorithm.
* *************************************************************************************/
void Alg_insertionSort(uint32_t* pau32_array,uint8_t u8_arraySize)
{
    sint16_t s16_tempIndex,s16_loopIndex;
    uint32_t u32_tempNum=0;
    for(s16_tempIndex=1;  s16_tempIndex<u8_arraySize;  s16_tempIndex++)
    {
        u32_tempNum = pau32_array[s16_tempIndex];
        for(s16_loopIndex=s16_tempIndex-1; s16_loopIndex>=0; s16_loopIndex--)
        {
            if(u32_tempNum<pau32_array[s16_loopIndex])
            {
                pau32_array[s16_loopIndex+1]=pau32_array[s16_loopIndex];
                pau32_array[s16_loopIndex] = u32_tempNum;
            }
            else
                break;
        }
    }
}

/*************************************************************************************
* Service Name: Alg_checkSorted
* Parameters (in): pau32_array -> Pointer to array of data to be checked.
*                  u8_arraySize -> Size of the array pau32_array.
* Parameters (inout): None
* Parameters (out):None
* Return value: uint8_t -> Return the status of the array (1)=Sorted or (0)=Unsorted
* Description: Function to check if the the pau32_array sorted or not.
* *************************************************************************************/
uint8_t Alg_checkSorted(uint32_t* pau32_array,uint8_t u8_arraySize)
{
    uint8_t u8_loopIndex=0;
    for(u8_loopIndex=0; u8_loopIndex<u8_arraySize-1; u8_loopIndex++)
    {
        if(pau32_array[u8_loopIndex] > pau32_array[u8_loopIndex+1])
            return ARRAY_UNSORTED;
    }
    return ARRAY_SORTED;
}






