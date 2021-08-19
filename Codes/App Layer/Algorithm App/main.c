#include <stdio.h>
#include <stdlib.h>
#include "Test_Cases.h"


int main()
{
    TC_ExecuteAndLog();
    return 0;
}










#if 0
#define ARRAY_SIZE      11
int main()
{
    uint32_t au32_data[ARRAY_SIZE] = {2,20,28,9,15,45,36,12,4,6,65};//2,4,6,9,12,15,20,28,36,45,65
    sint16_t s16_numIndex = 0;
    uint32_t u32_numberToSearchFor = 0;
    uint32_t u32_loopCounter=0;

    /** Print the Original Array **/
    printf("The Original Array: ");
    for(u32_loopCounter=0; u32_loopCounter<ARRAY_SIZE; u32_loopCounter++)
    {
        printf("%d, ",au32_data[u32_loopCounter]);
    }

    /** Get Number to search for it **/
    printf("\nEnter a Number to search for: ");
    scanf("%d",&u32_numberToSearchFor);

    /** Binary Search for the given number **/
    s16_numIndex = Alg_binarySearch(au32_data, ARRAY_SIZE, u32_numberToSearchFor);

    /** Print the Sorted Array **/
    printf("The Sorted Array: ");
    for(u32_loopCounter=0; u32_loopCounter<ARRAY_SIZE; u32_loopCounter++)
    {
        printf("%d, ",au32_data[u32_loopCounter]);
    }

    /** Print the result **/
    if(s16_numIndex == -1)
        printf("\nNumber Not Found");
    else
        printf("\nNumber is at index %d",s16_numIndex);
    return 0;
}
#endif
