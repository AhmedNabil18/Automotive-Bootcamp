
#include "Test_Cases.h"
#include "Test_Cases_Cfg.h"

extern str_TC_XOGame_displayShape_t  astr_TC_XOGame_displayShape_TestData[TC_XO_DISPLAY_SHAPE_NUM];
extern str_TC_XOGame_getPlayerInput_t  astr_TC_XOGame_getPlayerInput_TestData[TC_XO_DISPLAY_SHAPE_NUM];

TC_Error_t TC_ExecuteAndLog(void)
{
    TC_Error_t returnError = TC_ERROR_OK;

    returnError = TC_XOGame_displayShape();
    returnError = TC_XOGame_getPlayerInput();

    return TC_ERROR_OK;
}

TC_Error_t TC_XOGame_displayShape(void)
{
    uint16_t u16_loopIndex=0;
    str_TC_XOGame_displayShape_t* pstr_TC_Data= NULL_PTR;

    /*
     * Test Case Execution
     */
    for(u16_loopIndex=0; u16_loopIndex<TC_XO_DISPLAY_SHAPE_NUM; u16_loopIndex++)
    {
        pstr_TC_Data = &astr_TC_XOGame_displayShape_TestData[u16_loopIndex];


        pstr_TC_Data->u8_TC_ActualResult = X_O_displayShape(pstr_TC_Data->au8_TC_ARG_XOCellsData);
    }
    system("cls");
    /*
     * Log the Results
     */
    for(u16_loopIndex=0; u16_loopIndex<TC_XO_DISPLAY_SHAPE_NUM; u16_loopIndex++)
    {
        pstr_TC_Data = &astr_TC_XOGame_displayShape_TestData[u16_loopIndex];
        /*
         * Test Case Result
         */
        if(pstr_TC_Data->u8_TC_ActualResult == pstr_TC_Data->u8_TC_ExpectedResult)
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


TC_Error_t TC_XOGame_getPlayerInput(void)
{
    uint16_t u16_loopIndex=0;
    str_TC_XOGame_getPlayerInput_t* pstr_TC_Data= NULL_PTR;

    /*
     * Test Case Execution
     */
    for(u16_loopIndex=0; u16_loopIndex<TC_XO_GET_PLAYER_INPUT_NUM; u16_loopIndex++)
    {
        pstr_TC_Data = &astr_TC_XOGame_getPlayerInput_TestData[u16_loopIndex];


        pstr_TC_Data->u8_TC_ActualResult = X_O_getPlayerInput(pstr_TC_Data->u8_XOplayerID,\
                                                            pstr_TC_Data->pu8_XOplayerInput);
    }
    system("cls");
    /*
     * Log the Results
     */
    for(u16_loopIndex=0; u16_loopIndex<TC_XO_GET_PLAYER_INPUT_NUM; u16_loopIndex++)
    {
        pstr_TC_Data = &astr_TC_XOGame_getPlayerInput_TestData[u16_loopIndex];
        /*
         * Test Case Result
         */
        if(pstr_TC_Data->u8_TC_ActualResult == pstr_TC_Data->u8_TC_ExpectedResult)
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
