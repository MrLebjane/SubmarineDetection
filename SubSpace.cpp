 #include "SubSpace.h"

namespace SubSpace{

    //To convert string to Integer
    int ArgToInt(string strArgument)
    {
        int intNum = 0;
        stringstream ss {strArgument};
        ss >> intNum;
        //if fail
        if(ss.fail())
        {
            cerr << "Could not convert to integer" << endl;
            exit(ERR_CONVERSION);
        }
        return intNum;
    }

    //Generate Random Numbers within Range
    int genRandomNum(int intLowerBound, int intUpperBound)
    {
        int intRange = intUpperBound - intLowerBound  + 1;
        return rand() % intRange + intLowerBound;
    }

    //Initialize the Game World
    void initGameWorld(game_Matrix gameWorld)
    {
        //Only Contains Normal Soil
        for(int r = 0; r < TOTAL_ROWS; r++)
        {
            for(int c = 0; c < TOTAL_COLS; c++)
            {
                gameWorld[r][c] = NORMAL_WATER;
            }
        }
                //Randomly place Player in Game World
        int intNoRows = TOTAL_ROWS;
        int intNoCols = TOTAL_COLS;
        //int intBombRow = genRandomNum(0, intNoRows - 1);
        //int intBombCol = genRandomNum(0, intNoCols - 1);
        int intLaunchRow = genRandomNum(0, intNoRows - 1);
        int intLaunchCol = genRandomNum(0, intNoCols - 1);

        //Randomly place Player in Game World
        int intPlayerRow = genRandomNum(0, intNoRows - 1);
        int intPlayerCol = genRandomNum(0, intNoCols - 1);
        gameWorld[intPlayerRow][intPlayerCol] = PLAYER;
        gameWorld[intLaunchRow][intLaunchCol]=LAUNCH;

    }
    void initGameWorld1(game_Matrix gameWorld,int intNumBombs)
    {
        int intNoRows = TOTAL_ROWS;
        int intNoCols = TOTAL_COLS;
        int intBombRow = genRandomNum(0, intNoRows - 1);
        int intBombCol = genRandomNum(0, intNoCols - 1);
        for(int i=0;i<=intNumBombs;i++)
        {
              gameWorld[intBombRow][intBombCol] = BOMBS;
              intBombRow = genRandomNum(0, intNoRows - 1);
              intBombCol = genRandomNum(0, intNoCols - 1);
            while(gameWorld[intBombRow+1][intBombCol+1]==BOMBS||gameWorld[intBombRow-1][intBombCol-1]==BOMBS||gameWorld[intBombRow+1][intBombCol]==BOMBS||gameWorld[intBombRow][intBombCol+1]==BOMBS||gameWorld[intBombRow-1][intBombCol]==BOMBS||gameWorld[intBombRow][intBombCol-1]==BOMBS||gameWorld[intBombRow][intBombCol]==BOMBS)
            {
                  gameWorld[intBombRow][intBombCol] = BOMBS;
                  intBombRow = genRandomNum(0, intNoRows - 1);
                  intBombCol = genRandomNum(0, intNoCols - 1);
            }

        }

    }

    void initGameWorld2(game_Matrix gameWorld,int intNumBombs)
    {
        int intNoRows = TOTAL_ROWS;
        int intNoCols = TOTAL_COLS;
        int intBombRow = genRandomNum(0, intNoRows - 1);
        int intBombCol = genRandomNum(0, intNoCols - 1);
        for(int i=0;i<=intNumBombs;i++)
        {
              gameWorld[intBombRow][intBombCol] = BOMBS;
              intBombRow = genRandomNum(0, intNoRows - 1);
              intBombCol = genRandomNum(0, intNoCols - 1);
            while(gameWorld[intBombRow+1][intBombCol+1]==BOMBS||gameWorld[intBombRow-1][intBombCol-1]==BOMBS||gameWorld[intBombRow+1][intBombCol]==BOMBS||gameWorld[intBombRow][intBombCol+1]==BOMBS||gameWorld[intBombRow-1][intBombCol]==BOMBS||gameWorld[intBombRow][intBombCol-1]==BOMBS||gameWorld[intBombRow][intBombCol]==BOMBS)
            {
                  gameWorld[intBombRow][intBombCol] = BOMBS;
                  intBombRow = genRandomNum(0, intNoRows - 1);
                  intBombCol = genRandomNum(0, intNoCols - 1);
            }

        }

    }

    //Print the Game World
    void SubArea(const game_Matrix gameWorld)
    {

        for(int r = 0; r < TOTAL_ROWS; r++)
        {
            for(int c = 0; c < TOTAL_COLS; c++)
            {
                cout << FEATURES1[gameWorld[r][c]] << "";
            }
            cout << endl;
        }
    }

    void SurfArea(const game_Matrix gameWorld)
    {
        for(int r = 0; r < TOTAL_ROWS; r++)
        {
            for(int c = 0; c < TOTAL_COLS; c++)
            {
                cout << FEATURES2[gameWorld[r][c]] << "";
            }
            cout << endl;
        }
    }

    //Move the Player
    void movePlayer(game_Matrix gameWorld, char chInput)
    {
        //Find the player's current position
        int intPlayerRow = -1;
        int intPlayerCol = -1;
        findPlayer(intPlayerRow, intPlayerCol, gameWorld);
        //Destination Row and Col
        int intPlayerDRow = intPlayerRow;
        int intPlayerDCol = intPlayerCol;
        LoseOrWin(gameWorld,intPlayerRow,intPlayerCol);

        //Change / Define Destination
        switch(tolower(chInput))
        {
        case 'w':   //Move Up
            intPlayerDRow--;
            break;
        case 's':   //Move Down
            intPlayerDRow++;
            break;
        case 'a':   //Move Left
            intPlayerDCol--;
            break;
        case 'd':   //Move Right
            intPlayerDCol++;
            break;
        }


         LoseOrWin(gameWorld,intPlayerRow,intPlayerCol);
        //Actual Movement of the Player
        if(validMove(intPlayerDRow, intPlayerDCol))
        {
            gameWorld[intPlayerDRow][intPlayerDCol] = PLAYER;
            gameWorld[intPlayerRow][intPlayerCol] = NORMAL_WATER;
        }

    }


    //Find the Player
    void findPlayer(int &intPlayerRow, int &intPlayerCol, game_Matrix gameWorld)
    {
        for(int r = 0; r < TOTAL_ROWS; r++)
        {
            for(int c = 0; c < TOTAL_COLS; c++)
            {
                if(gameWorld[r][c] == PLAYER)
                {
                    intPlayerRow = r;
                    intPlayerCol = c;
                    return;
                }
            }
        }
    }

    //Is Move Valid
    bool validMove(int intDRow, int intDCol)
    {
        if(intDRow >= 0 && intDRow < TOTAL_ROWS && intDCol >= 0 && intDCol < TOTAL_COLS)
        {
            return true;
        }
        return false;
    }

    void LoseOrWin(const game_Matrix gameWorld,int &intDRow, int &intDCol)
    {
        if(gameWorld[intDRow+1][intDCol+1]==BOMBS||gameWorld[intDRow-1][intDCol-1]==BOMBS||gameWorld[intDRow+1][intDCol]==BOMBS||gameWorld[intDRow][intDCol+1]==BOMBS||gameWorld[intDRow-1][intDCol]==BOMBS||gameWorld[intDRow][intDCol-1]==BOMBS)
        {
            cout<<"**************"<<endl;
            cout<<"*  YOU LOSE  *"<<endl;
            cout<<"**************"<<endl;
            system("pause");
            exit(0);
        }
        else if(gameWorld[intDRow+1][intDCol+1]==LAUNCH||gameWorld[intDRow-1][intDCol-1]==LAUNCH||gameWorld[intDRow+1][intDCol]==LAUNCH||gameWorld[intDRow][intDCol+1]==LAUNCH||gameWorld[intDRow-1][intDCol]==LAUNCH||gameWorld[intDRow][intDCol-1]==LAUNCH)
        {
            cout<<"*************"<<endl;
            cout<<"*  YOU WIN  *"<<endl;
            cout<<"*************"<<endl;
            system("pause");
            exit(0);
        }
    }
    void sub1(game_Matrix gameWorld,int &i,int intNumBombs)
    {
        initGameWorld1(gameWorld,intNumBombs);
        i++;
    }
    void sub2(game_Matrix gameWorld,int &i,int intNumBombs)
    {
        initGameWorld2(gameWorld,intNumBombs);
        i++;
    }
}
