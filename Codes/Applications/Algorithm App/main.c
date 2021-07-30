#include <stdio.h>
#include <stdlib.h>
#include "S_Algo_Task.h"

#define ARRAY_SIZE      11
int main()
{
    uint32_t au32_data[ARRAY_SIZE] = {2,20,28,9,15,45,36,12,4,6,65};//2,4,6,9,12,15,20,28,36,45,65
    sint16_t s16_numIndex = 0;

    s16_numIndex = Alg_binarySearch(au32_data, ARRAY_SIZE, 18);
    if(s16_numIndex == -1)
        printf("Number Not Found");
    else
        printf("Number is at index %d",s16_numIndex);
    return 0;
}
