
#include "X_O_Application.h"




static const uint8_t aau8_winPositions[X_O_WIN_PROBABIITIES][X_O_WIN_POSITIONS_NUM]={{0,1,2},{0,3,6},{0,4,8},{3,4,5},{1,4,7},{2,4,6},{6,7,8},{2,5,8}};


X_O_Error_t X_O_LaunchGame(void)
{
    uint8_t u8_playerAnswer= 'N';
    X_O_Error_t returnError = X_O_ERROR_OK;
    do{
        returnError = X_O_StartGame();
        if(X_O_GAME_END == returnError)
        {
            printf("Do you want to play again ? Y/N");
            scanf(" %c",&u8_playerAnswer);
        }else if(X_O_ABORT_GAME == returnError){
            return 0;
        }else
        {
            return 0;
        }
    }while(u8_playerAnswer == 'Y');
    return 0;
}

X_O_Error_t X_O_StartGame(void)
{
    uint8_t au8_XOCellsData[X_O_SHAPE_CELLS_NUM] = {'0','1','2','3','4','5','6','7','8'};
    uint8_t u8_playerInput = 0;
    uint8_t u8_playerID[X_O_PLAYERS_NUM] = {'X','O'};
    uint8_t u8_playerIDIndex = 0;
    uint8_t u8_dataIndex = 0;
    uint8_t u8_loopIndex = 0;
    X_O_Error_t returnError = X_O_ERROR_OK;

    X_O_displayShape(au8_XOCellsData);
    for(u8_loopIndex=0 ; u8_loopIndex<X_O_MAX_PLAYS_NUM ; u8_loopIndex++)
    {
        do
        {
            returnError = X_O_getPlayerInput(u8_playerID[u8_playerIDIndex], &u8_playerInput);
            if(returnError == X_O_ERROR_INVALID_INPUT)
            {
                printf("BUZZ! This input is out of range, please choose a valid input number\n");
                continue;
            }else if(returnError == X_O_ABORT_GAME)
            {
                return X_O_ABORT_GAME;
            }
            u8_dataIndex = u8_playerInput - '0';

            if((au8_XOCellsData[u8_dataIndex] == 'X') || (au8_XOCellsData[u8_dataIndex] == 'O'))
            {
                printf("BUZZ!! This Cell has already been taken, please choose another empty cell\n");
                continue;
            }else
            {
                break;
            }
        }while(1);
        au8_XOCellsData[u8_dataIndex] = u8_playerID[u8_playerIDIndex];
        returnError = X_O_displayShape(au8_XOCellsData);
        if(returnError == X_O_ERROR_INVALID_ARG)
            return X_O_ERROR_INVALID_ARG;
        if(u8_loopIndex >= X_O_MIN_PLAYS_CHECK_WIN-1)
        {
            if(X_O_PLAYER_WON == X_O_checkWinner(u8_playerID[u8_playerIDIndex], au8_XOCellsData))
            {
                printf("Winner Winner Chicken Dinner\nCongratulations Player %c\n", u8_playerID[u8_playerIDIndex]);
                return X_O_GAME_END;
            }
        }
        u8_playerIDIndex = !u8_playerIDIndex;
    }


    return X_O_ERROR_OK;
}

X_O_Error_t   X_O_checkWinner(uint8_t u8_XOplayerID, uint8_t* pau8_XOCellsData)
{
    uint8_t u8_loopIndex=0;

    for(u8_loopIndex=0 ; u8_loopIndex<X_O_WIN_PROBABIITIES ; u8_loopIndex++)
    {
        if( ( (pau8_XOCellsData[aau8_winPositions[u8_loopIndex][0]])\
           &(pau8_XOCellsData[aau8_winPositions[u8_loopIndex][1]])\
           &(pau8_XOCellsData[aau8_winPositions[u8_loopIndex][2]]) )\
           == u8_XOplayerID)
        {
            return X_O_PLAYER_WON;
        }
    }
    return X_O_GAME_CONTINUE;
}

X_O_Error_t   X_O_displayShape(uint8_t* pau8_XOCellsData)
{
    uint8_t u8_loopIndex=0;

    for(u8_loopIndex=0; u8_loopIndex<X_O_SHAPE_CELLS_NUM; u8_loopIndex++)
    {
        if(((pau8_XOCellsData[u8_loopIndex] > '8'))\
           && (pau8_XOCellsData[u8_loopIndex] != 'X')\
           && (pau8_XOCellsData[u8_loopIndex] != 'O'))
        {
            return X_O_ERROR_INVALID_ARG;
        }
    }
    system("cls");
    printf("Enter -1 to quit game\n");
    printf("- - - - - - -\n|");
    for(u8_loopIndex=0; u8_loopIndex<X_O_FIRST_ROW_CELLS; u8_loopIndex++)
    {
        printf(" %c |",pau8_XOCellsData[u8_loopIndex]);
    }
    printf("\n- - - - - - -\n|");
    for(; u8_loopIndex<X_O_SECOND_ROW_CELLS; u8_loopIndex++)
    {
        printf(" %c |",pau8_XOCellsData[u8_loopIndex]);
    }
    printf("\n- - - - - - -\n|");
    for(; u8_loopIndex<X_O_THIRD_ROW_CELLS; u8_loopIndex++)
    {
        printf(" %c |",pau8_XOCellsData[u8_loopIndex]);
    }
    printf("\n- - - - - - -\n");
    return X_O_ERROR_OK;
}

X_O_Error_t   X_O_getPlayerInput(uint8_t u8_XOplayerID, uint8_t* pu8_XOplayerInput)
{
    if(u8_XOplayerID != 'X' && u8_XOplayerID != 'O')
        return X_O_ERROR_INVALID_ARG;

    if(pu8_XOplayerInput == NULL_PTR)
        return X_O_ERROR_NULL;
    sint32_t input=0;
    printf("Player %c , choose your position: ", u8_XOplayerID);
    scanf(" %d",(int*) &input);
    if(input == -1)
        return X_O_ABORT_GAME;
    *pu8_XOplayerInput = input+48;
    if((*pu8_XOplayerInput < '0') || (*pu8_XOplayerInput > '8'))
        return X_O_ERROR_INVALID_INPUT;

    return X_O_ERROR_OK;
}


