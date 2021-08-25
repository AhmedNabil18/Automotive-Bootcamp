#ifndef _TEST_CASES_H_
#define _TEST_CASES_H_

#include <stdio.h>
#include "S_Algo_Task.h"
#include "Test_Cases_Cfg.h"

#define TC_PASSED       1
#define TC_FAILED       0
#define TC_ERROR_OK     1



typedef uint8_t TC_Error_t;

/************************************************************************************
 * Description: Structure type holds the test case parameters of the
 *              function Alg_checkSorted.
************************************************************************************/
typedef struct
{
    uint8_t au8_TC_ID[50];
    sint8_t s8_TC_ExpectedResult;
    sint8_t s8_TC_ActualResult;
    uint32_t pau32_array[255];
    uint8_t u8_arraySize;
    uint8_t u8_TC_Status;
}str_TC_Algorithm_checkSorted_t;


/************************************************************************************
 * Description: Structure type holds the test case parameters of the
 *              function Alg_insertionSort.
************************************************************************************/
typedef struct
{
    uint8_t au8_TC_ID[50];
    sint8_t s8_TC_ExpectedResult;
    sint8_t s8_TC_ActualResult;
    uint32_t pau32_array[255];
    uint8_t u8_arraySize;
    uint8_t u8_TC_Status;
}str_TC_Algorithm_insertionSort_t;


/************************************************************************************
 * Description: Structure type holds the test case parameters of the
 *              function Alg_binarySearch.
************************************************************************************/
typedef struct
{
    uint8_t au8_TC_ID[50];
    sint8_t s8_TC_ExpectedResult;
    sint8_t s8_TC_ActualResult;
    uint32_t pau32_array[255];
    uint8_t u8_arraySize;
    uint32_t u32_number;
    uint8_t u8_TC_Status;
}str_TC_Algorithm_binarySearch_t;

TC_Error_t TC_ExecuteAndLog(void);
TC_Error_t TC_Algorithm_checkSorted(void);
TC_Error_t TC_Algorithm_insertionSort(void);
TC_Error_t TC_Algorithm_binarySearch(void);

#endif // _TEST_CASES_H_
