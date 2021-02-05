#ifndef SUBSPACE_H
#define SUBSPACE_H

#include <sstream>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

namespace SubSpace{
    //The game World dimensions
    const int TOTAL_ROWS = 20;
    const int TOTAL_COLS = 20;

    //Error Constants
    const int ERR_ARGS = -1;
    const int ERR_RANGE = -2;
    const int ERR_CONVERSION = -3;

    //Store Features
    const int PLAYER = 0;
    const int NORMAL_WATER = 1;
    const int BOMBS = 2;
    const int LAUNCH = 3;

    //Feature Characters
    const char FEATURES1[] = {'P', '.', 'M','L'};
    const char FEATURES2[] = {'p', '.', '0','L'};


    typedef int game_Matrix[TOTAL_ROWS][TOTAL_COLS];

    //Functions
    int ArgToInt(string strArgument);   //To convert string to Integer
    int genRandomNum(int intLowerBound, int intUpperBound); //Generate Random Numbers within Range
    void initGameWorld(game_Matrix gameWorld);  //Initialize the Game World
    void initGameWorld1(game_Matrix gameWorld,int intNumBombs);
    void initGameWorld2(game_Matrix gameWorld,int intNumBombs);
    void SubArea(const game_Matrix gameWorld);   //Print the Game World
    void SurfArea(const game_Matrix gameWorld);
    void movePlayer(game_Matrix gameWorld, char chInput);   //Move the Player
    void findPlayer(int &intPlayerRow, int &intPlayerCol, game_Matrix gameWorld);   //Find the Player
    bool validMove(int intDRow, int intDCol); //Is Move Valid
    void LoseOrWin(const game_Matrix gameWorld,int &intDRow, int &intDCol);
    void sub1(game_Matrix gameWorld,int &i,int intNumBombs);
    void sub2(game_Matrix gameWorld,int &i,int intNumBombs);

}

#endif // SUBSPACE_H
