#ifndef _TEST_CASES_H_
#define _TEST_CASES_H_

#include "../X_O_Application.h"
#include "Test_Cases_Cfg.h"

#define TC_PASSED       1
#define TC_FAILED       0
#define TC_ERROR_OK     1



typedef uint8_t TC_Error_t;

/************************************************************************************
 * Description: Structure type holds the test case parameters of the
 *              function X_O_displayShape.
************************************************************************************/
typedef struct
{
    uint8_t au8_TC_ID[50];
    sint8_t u8_TC_ExpectedResult;
    sint8_t u8_TC_ActualResult;
    uint8_t au8_TC_ARG_XOCellsData[X_O_SHAPE_CELLS_NUM];
    uint8_t u8_TC_Status;
}str_TC_XOGame_displayShape_t;


/************************************************************************************
 * Description: Structure type holds the test case parameters of the
 *              function X_O_getPlayerInput.
************************************************************************************/
typedef struct
{
    uint8_t au8_TC_ID[50];
    sint8_t u8_TC_ExpectedResult;
    sint8_t u8_TC_ActualResult;
    uint8_t u8_XOplayerID;
    uint8_t *pu8_XOplayerInput;
    uint8_t u8_TC_Status;
}str_TC_XOGame_getPlayerInput_t;



TC_Error_t TC_ExecuteAndLog(void);
TC_Error_t TC_XOGame_displayShape(void);
TC_Error_t TC_XOGame_getPlayerInput(void);

#endif // _TEST_CASES_H_
