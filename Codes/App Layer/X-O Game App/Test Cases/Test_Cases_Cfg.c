
#include "Test_Cases.h"


/************************************************************************************
 * Description: Structures holds the test cases of the function X_O_displayShape.
************************************************************************************/
str_TC_XOGame_displayShape_t  astr_TC_XOGame_displayShape_TestData[TC_XO_DISPLAY_SHAPE_NUM] =
{ /**       au8_TC_ID             u8_TC_ExpectedResult   u8_TC_ActualResult            pau8_TC_ARG_XOCellsData         u8_TC_Status **/
    {"TC_XOGame_displayShape_01",    X_O_ERROR_OK,               NULL,          {'0','1','2','3','4','5','6','7','8'},     NULL},
    {"TC_XOGame_displayShape_02",    X_O_ERROR_OK,               NULL,          {'0','1','2','X','4','X','6','X','8'},     NULL},
    {"TC_XOGame_displayShape_03",    X_O_ERROR_OK,               NULL,          {'0','O','O','3','4','5','O','7','8'},     NULL},
    {"TC_XOGame_displayShape_04", X_O_ERROR_INVALID_ARG,         NULL,          {'2','3','4','5','6','7','8','9','10'},    NULL},
    {"TC_XOGame_displayShape_05", X_O_ERROR_INVALID_ARG,         NULL,          {'-2','-1','0','1','2','3','4','5','6'},   NULL},
    {"TC_XOGame_displayShape_06", X_O_ERROR_INVALID_ARG,         NULL,          {'0','1','A','3','C','5','6','7','8'},     NULL}
};


/************************************************************************************
 * Description: Structures holds the test cases of the function X_O_getPlayerInput.
************************************************************************************/
uint8_t u8_XOplayerInput; /** Player Input Variable to hold the player's input if it's correct **/
str_TC_XOGame_getPlayerInput_t  astr_TC_XOGame_getPlayerInput_TestData[TC_XO_DISPLAY_SHAPE_NUM] =
{ /**       au8_TC_ID                u8_TC_ExpectedResult       u8_TC_ActualResult   u8_XOplayerID    *pu8_XOplayerInput   u8_TC_Status **/
    {"TC_XOGame_getPlayerInput_01",    X_O_ERROR_INVALID_ARG,          NULL,            'W',         &u8_XOplayerInput,       NULL},
    {"TC_XOGame_getPlayerInput_02",    X_O_ERROR_NULL,                 NULL,            'X',              NULL_PTR,           NULL},
    {"TC_XOGame_getPlayerInput_03",    X_O_ERROR_INVALID_INPUT,        NULL,            'O',         &u8_XOplayerInput,       NULL},
    {"TC_XOGame_getPlayerInput_04",    X_O_ERROR_INVALID_INPUT,        NULL,            'X',         &u8_XOplayerInput,       NULL},
    {"TC_XOGame_getPlayerInput_05",    X_O_ERROR_OK,                   NULL,            'O',         &u8_XOplayerInput,       NULL},
    {"TC_XOGame_getPlayerInput_06",    X_O_ABORT_GAME,                 NULL,            'X',         &u8_XOplayerInput,       NULL},
};
