/*******************************************************************************
 * File : StringManipulation.c
 * Source File for String Manipulation
 * Description: Various of Functions that serve and manipulate with strings.
 *******************************************************************************/


/**------------------**
 **---- Includes ----**
 **------------------**/
#include "StringManipulation.h"


/**************************************
 **---- Functions Implementation ----**
 **************************************/

/*************************************************************************************
* Service Name: stringLength
* Parameters (in): string1 -> Pointer to string.
* Parameters (inout): None
* Parameters (out):None
* Return value: uint8_t -> unsigned character returns the length of the string + NULL Terminator
* Description: Function to count the number of elements in the string including the NULL Terminator
* *************************************************************************************/
uint8_t stringLength(uint8_t* string1)
{
    uint8_t u8_loopIndex=0;
    while(string1[u8_loopIndex] != '\0')
    {
        u8_loopIndex++;
    }
    return u8_loopIndex+1;
}

uint8_t stringCompare(uint8_t* string1, uint8_t* string2)
{
    uint8_t u8_loopIndex=0;
    if(stringLength(string1) != stringLength(string2))
        return 0;
    while(string1[u8_loopIndex] != '\0')
    {
        if(string1[u8_loopIndex] != string2[u8_loopIndex])
            return 0;
        u8_loopIndex++;
    }
    return 1;
}

void stringCopy(uint8_t* stringSource, uint8_t* stringDestination)
{
    uint8_t u8_loopIndex=0;
    while(stringSource[u8_loopIndex] != '\0')
    {
        stringDestination[u8_loopIndex] = stringSource[u8_loopIndex];
        u8_loopIndex++;
    }
    stringDestination[u8_loopIndex] = '\0';
}

/*
uint16_t arrayToInteger(uint8_t* pu8_Array)
{
    uint8_t u8_arrLength = stringLength(pu8_Array);
    uint8_t u8_loopIndex=0;
    for(u8_loopIndex=0; u8_loopIndex<u8_arrLength; u8_loopIndex++)
    {

    }
}*/
