#ifndef _X_O_APPLICATION_H_
#define _X_O_APPLICATION_H_

#include <stdio.h>
#include <stdlib.h>
#include "../../Lib/Platform_Types.h"

#define X_O_ERROR_OK                0
#define X_O_ERROR_INVALID_INPUT    -1
#define X_O_ERROR_NULL             -2
#define X_O_ERROR_INVALID_ARG      -3

#define X_O_ABORT_GAME              -6
#define X_O_PLAYER_WON              1
#define X_O_GAME_CONTINUE           2
#define X_O_GAME_END                3

#define X_O_WIN_PROBABIITIES        8
#define X_O_WIN_POSITIONS_NUM       3
#define X_O_PLAYERS_NUM             2
#define X_O_FIRST_ROW_CELLS         3
#define X_O_SECOND_ROW_CELLS        6
#define X_O_THIRD_ROW_CELLS         9
#define X_O_SHAPE_CELLS_NUM         9
#define X_O_MAX_PLAYS_NUM           9
#define X_O_MIN_PLAYS_CHECK_WIN     5

typedef sint8_t X_O_Error_t;

X_O_Error_t X_O_LaunchGame(void);
X_O_Error_t X_O_StartGame(void);
X_O_Error_t X_O_displayShape(uint8_t* pau8_XOCellsData);
X_O_Error_t   X_O_checkWinner(uint8_t u8_XOplayerID, uint8_t* pau8_XOCellsData);
X_O_Error_t   X_O_getPlayerInput(uint8_t u8_XOplayerID, uint8_t* pu8_playerInput);
#endif // _X_O_APPLICATION_H_
