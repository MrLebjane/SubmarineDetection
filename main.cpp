 #include <iostream>
#include "SubSpace.h"

using namespace std;
using namespace SubSpace;
//void sub(int gameWorld,int& i,int intNumBombs);

int main(int argc, char* argv[])
{
    //Seed the random number generator
    srand(time(0));

    //No Wells
    int intNoBombs = 0;
    intNoBombs = ArgToInt(argv[1]);

    //Check the argument count
    if(argc != 2)
    {
        cerr << "Wrong number of arguments or second argument has uneven number" << endl;
        exit(ERR_ARGS);
    }

    //intNoWells = ArgToInt(argv[1]);

    //cout << "No Wells: " << intNoWells << endl;

    int GameMatrix[TOTAL_ROWS][TOTAL_COLS];

    //Initialize Game World
    initGameWorld(GameMatrix);
    int i=1;
    int m=0;

    //The main Loop
    bool blnContinue = true;
    char chInput = '\0';
    char chInput1='\0';

    do{
        //Clear the screen
        system("cls");
        //Print Game World
        //while(tolower(chInput)=='p')
        //SubArea(GameMatrix);
        //Menu
        cout << "No of Bouys and sea mines: " << intNoBombs << endl;

        cout << "T - Surface" << endl;
        cout << "B - Submerge " << endl;
        cout << "X - Exit the Game" << endl;
        cin>>chInput1;

        while(tolower(chInput1)=='t')
        {
            system("cls");
            cout<<"M = BOUYS"<<endl;
            cout<<"L = LAUNCH POSITION"<<endl;

            if( i==1)
            {
                sub1(GameMatrix,i,intNoBombs/2);

            }
            SubArea(GameMatrix);
            cout << "PLEASE CHOOSE AN OPTION" << endl;
            cout << "W - Move Up" << endl;
            cout << "S - Move Down" << endl;
            cout << "A - Move Left" << endl;
            cout << "D - Move Right" << endl;
            cout << "R - Return to submerge,float or exit the game option" << endl;
            cin >> chInput;

            switch(tolower(chInput))
            {
            case 'w':
            case 's':
            case 'a':
            case 'd':
                movePlayer(GameMatrix, chInput);
                break;
            default:
                cerr << "Incorrect Entry, Please Retry" << endl;
                cin.ignore(100, '\n');
            }
            if(tolower(chInput)=='r')
                break;
        }

        while(tolower(chInput1)=='b')
        {
            system("cls");
            cout<<"O = SEA MINES"<<endl;
            cout<<"L = LAUNCH POSITION"<<endl;

            if( m==1)
            {
                sub2(GameMatrix,m,intNoBombs/2);
            }

            SurfArea(GameMatrix);
            cout << "PLEASE CHOOSE AN OPTION" << endl;
            cout << "W - Move Up" << endl;
            cout << "S - Move Down" << endl;
            cout << "A - Move Left" << endl;
            cout << "D - Move Right" << endl;
            cout << "R - Return to submerge,float or exit the game option" << endl;
            cin >> chInput;

            switch(tolower(chInput))
            {
            case 'w':
            case 's':
            case 'a':
            case 'd':
                movePlayer(GameMatrix, chInput);
                break;
            default:
                cerr << "Incorrect Entry, Please Retry" << endl;
                cin.ignore(100, '\n');
            }
            if(tolower(chInput)=='r')
                break;
        }

        if(tolower(chInput1)=='x')
        {
                cout << "Thanks for playing the Game" << endl;
                blnContinue = false;
                break;
        }

    }
    while(blnContinue);

    return 0;
}


