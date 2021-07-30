
#include "Test_Cases.h"
#include "Test_Cases_Cfg.h"

extern str_TC_Algorithm_checkSorted_t  astr_TC_Algorithm_checkSorted_TestData[TC_ALGO_CHK_SORTED_NUM];
extern str_TC_Algorithm_insertionSort_t  astr_TC_Algorithm_insertionSort_TestData[TC_ALGO_INS_SORT_NUM];
extern str_TC_Algorithm_binarySearch_t  astr_TC_Algorithm_binarySearch_TestData[TC_ALGO_BIN_SEARCH_NUM];
TC_Error_t TC_ExecuteAndLog(void)
{
    volatile TC_Error_t returnError = TC_ERROR_OK;

    returnError = TC_Algorithm_checkSorted();
    returnError = TC_Algorithm_insertionSort();
    returnError = TC_Algorithm_binarySearch();

    return returnError;
}

TC_Error_t TC_Algorithm_checkSorted(void)
{
    uint16_t u16_loopIndex=0;
    str_TC_Algorithm_checkSorted_t* pstr_TC_Data= NULL_PTR;

    /*
     * Test Case Execution
     */
    for(u16_loopIndex=0; u16_loopIndex<TC_ALGO_CHK_SORTED_NUM; u16_loopIndex++)
    {
        pstr_TC_Data = &astr_TC_Algorithm_checkSorted_TestData[u16_loopIndex];


        pstr_TC_Data->s8_TC_ActualResult = Alg_checkSorted((pstr_TC_Data->pau32_array), pstr_TC_Data->u8_arraySize);
    }
    /*
     * Log the Results
     */
    for(u16_loopIndex=0; u16_loopIndex<TC_ALGO_CHK_SORTED_NUM; u16_loopIndex++)
    {
        pstr_TC_Data = &astr_TC_Algorithm_checkSorted_TestData[u16_loopIndex];
        /*
         * Test Case Result
         */
        if(pstr_TC_Data->s8_TC_ActualResult == pstr_TC_Data->s8_TC_ExpectedResult)
        {
            pstr_TC_Data->u8_TC_Status = TC_PASSED;
            printf("%s Passed\n", pstr_TC_Data->au8_TC_ID);
        }else{
            pstr_TC_Data->u8_TC_Status = TC_FAILED;
            printf("%s Failed\n", pstr_TC_Data->au8_TC_ID);
        }
    }

    return TC_ERROR_OK;
}


TC_Error_t TC_Algorithm_insertionSort(void)
{
    uint16_t u16_loopIndex=0;
    str_TC_Algorithm_insertionSort_t* pstr_TC_Data= NULL_PTR;

    /*
     * Test Case Execution
     */
    for(u16_loopIndex=0; u16_loopIndex<TC_ALGO_INS_SORT_NUM; u16_loopIndex++)
    {
        pstr_TC_Data = &astr_TC_Algorithm_insertionSort_TestData[u16_loopIndex];
        Alg_insertionSort(pstr_TC_Data->pau32_array, pstr_TC_Data->u8_arraySize);
        pstr_TC_Data->s8_TC_ActualResult = Alg_checkSorted(pstr_TC_Data->pau32_array, pstr_TC_Data->u8_arraySize);
    }
    /*
     * Log the Results
     */
    for(u16_loopIndex=0; u16_loopIndex<TC_ALGO_INS_SORT_NUM; u16_loopIndex++)
    {
        pstr_TC_Data = &astr_TC_Algorithm_insertionSort_TestData[u16_loopIndex];
        /*
         * Test Case Result
         */
        if(pstr_TC_Data->s8_TC_ActualResult == pstr_TC_Data->s8_TC_ExpectedResult)
        {
            pstr_TC_Data->u8_TC_Status = TC_PASSED;
            printf("%s Passed\n", pstr_TC_Data->au8_TC_ID);
        }else{
            pstr_TC_Data->u8_TC_Status = TC_FAILED;
            printf("%s Failed\n", pstr_TC_Data->au8_TC_ID);
        }
    }

    return TC_ERROR_OK;
}


TC_Error_t TC_Algorithm_binarySearch(void)
{
    uint16_t u16_loopIndex=0;
    str_TC_Algorithm_binarySearch_t* pstr_TC_Data= NULL_PTR;

    /*
     * Test Case Execution
     */
    for(u16_loopIndex=0; u16_loopIndex<TC_ALGO_BIN_SEARCH_NUM; u16_loopIndex++)
    {
        pstr_TC_Data = &astr_TC_Algorithm_binarySearch_TestData[u16_loopIndex];
        pstr_TC_Data->s8_TC_ActualResult = Alg_binarySearch(pstr_TC_Data->pau32_array, pstr_TC_Data->u8_arraySize, pstr_TC_Data->u32_number);
    }
    /*
     * Log the Results
     */
    for(u16_loopIndex=0; u16_loopIndex<TC_ALGO_BIN_SEARCH_NUM; u16_loopIndex++)
    {
        pstr_TC_Data = &astr_TC_Algorithm_binarySearch_TestData[u16_loopIndex];
        /*
         * Test Case Result
         */
        if(pstr_TC_Data->s8_TC_ActualResult == pstr_TC_Data->s8_TC_ExpectedResult)
        {
            pstr_TC_Data->u8_TC_Status = TC_PASSED;
            printf("%s Passed\n", pstr_TC_Data->au8_TC_ID);
        }else{
            pstr_TC_Data->u8_TC_Status = TC_FAILED;
            printf("%s Failed\n", pstr_TC_Data->au8_TC_ID);
        }
    }

    return TC_ERROR_OK;
}
