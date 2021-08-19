
#include "Test_Cases.h"


/************************************************************************************
 * Description: Structures holds the test cases of the function Alg_checkSorted.
************************************************************************************/
str_TC_Algorithm_checkSorted_t  astr_TC_Algorithm_checkSorted_TestData[TC_ALGO_CHK_SORTED_NUM] =
{ /**       au8_TC_ID             u8_TC_ExpectedResult   u8_TC_ActualResult   pau32_array   u8_arraySize    u8_TC_Status **/
    {"TC_Algorithm_checkSorted_01",    ARRAY_SORTED,               NULL,       {1,2,3,4},        4,             NULL},
    {"TC_Algorithm_checkSorted_02",    ARRAY_UNSORTED,             NULL,       {2,4,1,3},        4,             NULL},

};


/************************************************************************************
 * Description: Structures holds the test cases of the function Alg_insertionSort.
************************************************************************************/
str_TC_Algorithm_insertionSort_t  astr_TC_Algorithm_insertionSort_TestData[TC_ALGO_INS_SORT_NUM] =
{ /**       au8_TC_ID             u8_TC_ExpectedResult   u8_TC_ActualResult   pau32_array   u8_arraySize    u8_TC_Status **/
    {"TC_Algorithm_insertionSort_01",    ARRAY_SORTED,           NULL,         {2,4,1,3},        4,             NULL},
    {"TC_Algorithm_insertionSort_02",    ARRAY_SORTED,           NULL,         {1,2,3,4},        4,             NULL},

};


/************************************************************************************
 * Description: Structures holds the test cases of the function Alg_binarySearch.
************************************************************************************/
str_TC_Algorithm_binarySearch_t  astr_TC_Algorithm_binarySearch_TestData[TC_ALGO_BIN_SEARCH_NUM] =
{ /**       au8_TC_ID               u8_TC_ExpectedResult   u8_TC_ActualResult   pau32_array   u8_arraySize    u32_number      u8_TC_Status **/
    {"TC_Algorithm_binarySearch_01",       2,                     NULL,         {1,2,3,4},        4,              3,              NULL},
    {"TC_Algorithm_binarySearch_02",      -1,                     NULL,         {1,2,3,4},        4,              5,              NULL},
    {"TC_Algorithm_binarySearch_03",       2,                     NULL,         {2,4,1,3},        4,              3,              NULL},
    {"TC_Algorithm_binarySearch_04",      -1,                     NULL,         {2,4,1,3},        4,              5,              NULL}

};
