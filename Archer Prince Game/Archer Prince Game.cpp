#include <iostream>
#include <windows.h>
#include <conio.h>
#include <fstream>
#include <cstdlib>
#include <time.h>
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////

// front page
void story(bool &isPrintstory);
void control();

void stage1(int &rightmove, int &score, char &fruit, bool &checkbush, char &heart, bool &removeCharacter, int &wallX, int &wallY, int &wallsize, bool &GameExit, bool &isEnemy1Dead, int &princehealth, int &r1health, int &arrowCount, bool &R1presence, int &R1steps, string &R1direction, int &R1fireCount, int &R1collision, int &heroX, int &heroY, char &archerManArrow, int &R1X, int &R1Y, int R1fireX[], int R1fireY[], int arrowX[], int arrowY[], char Hero[][5], char maze[][107], char enemy1[][4], int &r2health, int &loadedArrow, bool &isFire, bool &R2presence, int &bomb);

void stage2(int &rightmove, int &score, char &fruit, bool &checkbush, char &heart, bool &removeCharacter, int &wallX, int &wallY, int &wallsize, bool &GameExit, bool &isEnemy2Dead, int &princehealth, int &r2health, int &arrowCount, bool &R2presence, int &R2steps, string &R2direction, int &R2fireCount, int &R2collision, int &heroX, int &heroY, char &archerManArrow, int &R2X, int &R2Y, int R2fireX[], int R2fireY[], int arrowX[], int arrowY[], bool &Move_to_stage3, char Hero[][5], char maze[][107], char enemy2[][5], int &r1health, int &loadedArrow, bool &isFire, bool &R1presence, int &bomb);

void stage3(int &rightmove, int &score, char &fruit, char &heart, bool &removeCharacter, int &wallX, int &wallY, int &wallsize, bool &GameExit, int &princehealth, int &heroX, int &heroY, char &archerManArrow, int &arrowCount, int arrowX[], int arrowY[], string &Up_enemy_direction, string &Down_enemy_direction, int &UpX, int &UpY, int &UpfireCount, int UpfireX[], int UpfireY[], int &DownX, int &DownY, int &DownfireCount, int DownfireX[], int DownfireY[], int &R1fireCount, int &R1X, int &R1Y, string &R1direction, int &R1steps, int R1fireX[], int R1fireY[], int &r1health, bool &isEnemy1Dead, bool &R1presence, int &R1collision, string side_enemy[][1], char Hero[][5], string maze2[][1], char enemy1[][4], int &r2health, int &loadedArrow, bool &isFire, bool &R2presence, int &bomb);

// Common Functions
void printstage1(char maze[][107]);
void printstage2(string maze2[][1]);
void gotoxy(int x, int y);
void loadingpage();
void gameheader();
void headerpic();
void textanimation(string a, bool &isPrintstory);
char getCharAtxy(short int x, short int y);
void printbush();
void removebush(char &fruit, bool &checkbush);
void wall(int &wallX, int &wallY, int &wallsize);
void wallremove(int &wallX, int &wallY, int &wallsize);
bool isprintR1(int &rightmove, int &R1collision);
bool isprintR2(int &rightmove, int &R2collision);
void gameover();
void youwin();
void reload(int &loadedArrow, bool &isFire);
void setColor(int color);
void printloadedArrows(int &loadedArrow, char &archerManArrow);
void credits();
void createBombs(int &r2health, int &bomb, bool &R2presence);

// score mechanism
void addscore(int &score);
void fruitscore(int &score);
void printscore(int &score);

// health mechanism
void herohealth(int &princehealth);
void printherohealth(char &heart, bool &GameExit, int &princehealth, int &r1health, int r2health);
void fruitrecoverhealth(int &princehealth);
void bombDamage(int &princehealth);
void R1health(bool &removeCharacter, int &r1health, bool &isEnemy1Dead);
void printR1health(char &heart, int &r1health, int &princehealth, int r2health);
void R2health(bool &removeCharacter, bool &isEnemy2Dead, int &r2health);
void printR2health(char &heart, int &r2health, int &princehealth, int &r1health);

// hero functions
void erasehero(int &heroX, int &heroY);
void printhero(int &heroX, int &heroY, char Hero[][5]);

// hero movement
void heroUp(int &score, char &fruit, int &princehealth, int &heroX, int &heroY, char Hero[][5], int &bomb);
void heroDown(int &score, char &fruit, int &princehealth, int &heroX, int &heroY, char Hero[][5], int &bomb);
void heroRight(int &rightmove, int &score, char &fruit, int &princehealth, int &heroX, int &heroY, char Hero[][5], int &bomb);
void heroLeft(int &score, char &fruit, int &princehealth, int &heroX, int &heroY, char Hero[][5], int &bomb);

// hero firing mechanism
void createArrow(int &arrowCount, int &heroX, int &heroY, char &archerManArrow, int arrowX[], int arrowY[]);
void moveArrow(int &arrowCount, char &archerManArrow, int arrowX[], int arrowY[]);
void eraseArrow(int x, int y);
void printArrow(int x, int y, char &archerManArrow);
void makeArrowInactive(int index, int &arrowCount, int arrowX[], int arrowY[]);

// robbers functions
void printR1(int &R1X, int &R1Y, char enemy1[][4]);
void printR2(int &R2X, int &R2Y, char enemy2[][5]);
void eraseR1(int &R1X, int &R1Y);
void eraseR2(int &R2X, int &R2Y);

// Robber movement
void R1move(int &R1steps, string &R1direction, int &R1X, int &R1Y, char enemy1[][4]);
void R2move(int &R2steps, string &R2direction, int &R2X, int &R2Y, char enemy2[][5]);

// Robber fire mechanism
void R1fire(int &R1fireCount, int &R1X, int &R1Y, int R1fireX[], int R1fireY[]);
void R1fireMove(int &R1fireCount, char &archerManArrow, int R1fireX[], int R1fireY[]);
void R1fireInActive(int index, int &R1fireCount, int R1fireX[], int R1fireY[]);

// Robber 2
void R2fire(int &R2fireCount, int &R2X, int &R2Y, int R2fireX[], int R2fireY[]);
void R2fireMove(int &R2fireCount, char &archerManArrow, int R2fireX[], int R2fireY[]);
void printRfire(int x, int y);
void eraseRfire(int x, int y);
void R2fireInActive(int index, int &R2fireCount, int R2fireX[], int R2fireY[]);

// hero fire Collisions
void collisionwithbush(char &fruit, bool &checkbush, int &arrowCount, int arrowX[], int arrowY[]);
void collisionwithR1(int &score, bool &removeCharacter, int &r1health, bool &isEnemy1Dead, int &arrowCount, bool &R1presence, int &R1collision, int &R1X, int &R1Y, int arrowX[], int arrowY[]);
void collisionwithR2(int &score, bool &removeCharacter, bool &isEnemy2Dead, int &r2health, int &arrowCount, bool &R2presence, int &R2collision, int &R2X, int &R2Y, int arrowX[], int arrowY[]);

// robbers fire collisions
void R1firecollisions(int &princehealth, bool &R1presence, int &R1fireCount, int &heroX, int &heroY, int R1fireX[], int R1fireY[]);
void R2firecollisions(int &princehealth, bool &R2presence, int &R2fireCount, int &heroX, int &heroY, int R2fireX[], int R2fireY[]);

// up enemy fires
void Upfire(int &UpfireCount, int &UpX, int &UpY, int UpfireX[], int UpfireY[]);
void UpfireMove(int &UpfireCount, char &archerManArrow, int UpfireX[], int UpfireY[]);
void UpfireInActive(int index, int &UpfireCount, int UpfireX[], int UpfireY[]);
void printUfire(int x, int y);
void eraseUfire(int x, int y);

// down enemy fire
void Downfire(int &DownfireCount, int &DownX, int &DownY, int DownfireX[], int DownfireY[]);
void DownfireMove(int &DownfireCount, char &archerManArrow, int DownfireX[], int DownfireY[]);
void DownfireInActive(int index, int &DownfireCount, int DownfireX[], int DownfireY[]);
void printDfire(int x, int y);
void eraseDfire(int x, int y);

// printing side enemies
void print_side_enemy(int X_axis, int Y_axis, string side_enemy[][1]);
void erase_side_enemy(int X_axis, int Y_axis);

// movement functions of side enemies
void side_enemy1_move(int &UpX, int &UpY, string &Up_enemy_direction, string side_enemy[][1]);
void side_enemy2_move(int &DownX, int &DownY, string &Down_enemy_direction, string side_enemy[][1]);

// fire collision functions of side enemies
void Upfirecollisions(int &princehealth, bool &R1presence, int &UpfireCount, int &heroX, int &heroY, int UpfireX[], int UpfireY[]);
void Downfirecollisions(int &princehealth, bool &R1presence, int &DownfireCount, int &heroX, int &heroY, int DownfireX[], int DownfireY[]);

////////////////////////////////////////////////////////////////////////////////////////////////

// Data storing functions

// data separating
string parseRecord(string line, int field);

// stage storing
void storemaze1(char maze[][107], int &maze1row);
void loadmaze1(char maze[][107]);

// score storing
void loadScoreData(int &score);
void updateScoreData(int score);

// storing steps data
void loadSteps(int &rightmove);
void updateSteps(int &rightmove);

// health data storing
void loadHealthData(int &princehealth, int &r1health, int &r2health);
void updateHealthData(int princehealth, int r1health, int r2health);

// move to next stage
void loadMoveNextStage(bool &Move_to_stage3);
void updateMoveNextStage(bool Move_to_stage3);

// hero Coordinates
void loadHeroCoordinate(int &heroX, int &heroY);
void updateHeroCoordinate(int heroX, int heroY);

// enemy1 coordinates
void loadR1Coordinate(int &R1X, int &R1Y);
void updateR1Coordinate(int R1X, int R1Y);

// enemy2 coordinates
void loadR2Coordinate(int &R2X, int &R2Y);
void updateR2Coordinate(int R2X, int R2Y);

// storing enemies presence
void loadenemypresence(bool &R1presence, bool &R2presence);
void updateEnemypresence(bool R1presence, bool R2presence);

////////////////////////////////////////////////////////////////////////////////////////////////

// Main Function
int main()
{
    ////////////////////////////////////////////////////////////////////////////////////////////

    // Variables
    string option;
    srand(time(NULL));
    bool checkbush = true;
    char fruit = 147;
    int score = 0;
    int rightmove = 0;
    int wallX = 0;
    int wallY = 0;
    int wallsize = 0;
    char heart = 3;
    int loadedArrow = 9;
    bool removeCharacter = false;
    bool GameExit = true;
    bool isEnemy1Dead = false;
    bool isEnemy2Dead = false;
    bool isPrintstory = true;
    int princehealth = 10;
    int r1health = 10;
    int r2health = 10;
    int arrowCount = 0;
    bool R1presence = true;
    bool R2presence = true;
    int R1steps = 0;
    int R2steps = 0;
    string R1direction = "Up";
    string R2direction = "Down";
    string Up_enemy_direction = "Left";
    string Down_enemy_direction = "Right";
    int R1fireCount = 0;
    int R2fireCount = 0;
    int UpfireCount = 0;
    int DownfireCount = 0;
    int R1collision = 0;
    int R2collision = 0;
    bool Move_to_stage3 = false;
    bool isFire = true;
    int bomb = 0;

    ////////////////////////////////////////////////////////////////////////////////////////////

    // Arrays
    int arrowX[100];
    int arrowY[100];
    int R1fireX[100];
    int R1fireY[100];
    int R2fireX[100];
    int R2fireY[100];
    int UpfireX[100];
    int UpfireY[100];
    int DownfireX[100];
    int DownfireY[100];

    ////////////////////////////////////////////////////////////////////////////////////////////

    // 2D arrays

    // side_enemy
    string side_enemy[2][1] = {{"/***\\"},
                               {"\\___/ "}};

    // Prince (Hero)
    char archerManHead = 1;
    char archerManBody = 178;
    char archerManArrow = 26;
    char Hero[3][5] = {{' ', archerManHead, ' ', ' ', ' '},
                       {'<', archerManBody, '-', 'D', archerManArrow},
                       {'/', ' ', '\\', ' ', ' '}};

    // Robber 1
    char face1 = 162;
    char body1 = 219;
    char legs1 = 19;
    char enemy1[3][4] = {{' ', ' ', face1, ' '},
                         {'<', '-', body1, '>'},
                         {' ', ' ', legs1, ' '}};

    // Robber 2
    char face2 = 2;
    char body2 = 219;
    char enemy2[3][5] = {{' ', ' ', ' ', face2, ' '},
                         {'<', '(', '-', body2, '>'},
                         {' ', ' ', '/', ' ', '\\'}};

    ////////////////////////////////////////////////////////////////////////////////////////////

    // Hero's Coordinates
    int heroX = 3;
    int heroY = 17;

    // Enemies coordinates
    int R1X = 80;
    int R1Y = 16;
    int R2X = 80;
    int R2Y = 24;

    // side enemies coordinates
    int UpX = 14;
    int UpY = 16;
    int DownX = 24;
    int DownY = 33;

    ////////////////////////////////////////////////////////////////////////////////////////////

    // games stages
    int maze1row = 14;
    char maze[maze1row][107] = {{'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
                                {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
                                {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
                                {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
                                {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
                                {'#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
                                {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
                                {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                                {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                                {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                                {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                                {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                                {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
                                {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', '#', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}};

    // stage 2
    int maze2row = 22;
    string maze2[maze2row][1] = {{"            ################################################################################"},
                                 {"            #                                                                              #"},
                                 {"            #                                                                              #"},
                                 {"            #______________________________________________________________________________#"},
                                 {"            #                                                                              #"},
                                 {"            #                                                                              #"},
                                 {"            #                                                                              #"},
                                 {"#############                                                                              ################"},
                                 {"#           #                                                                              #              #"},
                                 {"#           #                                                                              #              #"},
                                 {"#           #                                                                              #              #"},
                                 {"#           #                                                                              #              #"},
                                 {"#           #                                                                              #              #"},
                                 {"#############                                                                              ################"},
                                 {"            #                                                                              #"},
                                 {"            #                                                                              #"},
                                 {"            #                                                                              #"},
                                 {"            #______________________________________________________________________________#"},
                                 {"            #                                                                              #"},
                                 {"            #                                                                              #"},
                                 {"            #                                                                              #"},
                                 {"            ################################################################################"}};

    // storing the mazes
    storemaze1(maze, maze1row);

    ////////////////////////////////////////////////////////////////////////////////////////////

    // Working

    loadingpage();
    bool gamerunning = true;
    while (gamerunning)
    {
        system("cls");
        gameheader();
        cout << endl
             << endl;
        cout << "1. Resume Game" << endl;
        cout << "2. New Game " << endl;
        cout << "3. Practice " << endl;
        cout << "4. Story Of Game " << endl;
        cout << "5. Controls " << endl;
        cout << "6. Exit " << endl
             << endl;
        cout << "Select option : ";
        cin >> option;

        if (option == "1")
        {
            loadHeroCoordinate(heroX, heroY);
            if (heroX < 6)
            {
                system("cls");
                gameheader();
                gotoxy(15, 15);
                cout << "NO previous Record ";
                gotoxy(15, 17);
                cout << "Press any key to continue";
                getch();
            }
            else
            {
                loadenemypresence(R1presence, R2presence);
                loadScoreData(score);
                loadHealthData(princehealth, r1health, r2health);
                loadMoveNextStage(Move_to_stage3);
                loadR1Coordinate(R1X, R1Y);
                loadR2Coordinate(R2X, R2Y);
                loadmaze1(maze);
                loadSteps(rightmove);
                GameExit = true;
                if (Move_to_stage3 == true)
                {
                    stage3(rightmove, score, fruit, heart, removeCharacter, wallX, wallY, wallsize, GameExit, princehealth, heroX, heroY, archerManArrow, arrowCount, arrowX, arrowY, Up_enemy_direction, Down_enemy_direction, UpX, UpY, UpfireCount, UpfireX, UpfireY, DownX, DownY, DownfireCount, DownfireX, DownfireY, R1fireCount, R1X, R1Y, R1direction, R1steps, R1fireX, R1fireY, r1health, isEnemy1Dead, R1presence, R1collision, side_enemy, Hero, maze2, enemy1, r2health, loadedArrow, isFire, R2presence, bomb);
                }
                else
                {
                    stage2(rightmove, score, fruit, checkbush, heart, removeCharacter, wallX, wallY, wallsize, GameExit, isEnemy2Dead, princehealth, r2health, arrowCount, R2presence, R2steps, R2direction, R2fireCount, R2collision, heroX, heroY, archerManArrow, R2X, R2Y, R2fireX, R2fireY, arrowX, arrowY, Move_to_stage3, Hero, maze, enemy2, r1health, loadedArrow, isFire, R1presence, bomb);

                    if (Move_to_stage3 == true)
                    {
                        heroX = 3;
                        heroY = 24;
                        rightmove = 0;
                        arrowCount = 0;
                        R1Y = 20;
                        r1health = 200;
                        R1presence = false;
                        loadedArrow = 9;
                        stage3(rightmove, score, fruit, heart, removeCharacter, wallX, wallY, wallsize, GameExit, princehealth, heroX, heroY, archerManArrow, arrowCount, arrowX, arrowY, Up_enemy_direction, Down_enemy_direction, UpX, UpY, UpfireCount, UpfireX, UpfireY, DownX, DownY, DownfireCount, DownfireX, DownfireY, R1fireCount, R1X, R1Y, R1direction, R1steps, R1fireX, R1fireY, r1health, isEnemy1Dead, R1presence, R1collision, side_enemy, Hero, maze2, enemy1, r2health, loadedArrow, isFire, R2presence, bomb);
                    }
                }
            }
        }

        else if (option == "2")
        {
            GameExit = true;
            score = 0;
            princehealth = 100;
            r2health = 100;
            arrowCount = 0;
            R2fireCount = 0;
            rightmove = 0;
            R2steps = 0;
            wallX = 0;
            wallY = 0;
            wallsize = 0;
            R2presence = false;
            loadedArrow = 9;
            checkbush = true;
            R2collision = 0;
            heroX = 3;
            heroY = 17;
            bomb = 0;
            stage2(rightmove, score, fruit, checkbush, heart, removeCharacter, wallX, wallY, wallsize, GameExit, isEnemy2Dead, princehealth, r2health, arrowCount, R2presence, R2steps, R2direction, R2fireCount, R2collision, heroX, heroY, archerManArrow, R2X, R2Y, R2fireX, R2fireY, arrowX, arrowY, Move_to_stage3, Hero, maze, enemy2, r1health, loadedArrow, isFire, R1presence, bomb);

            if (Move_to_stage3 == true)
            {
                heroX = 3;
                heroY = 24;
                rightmove = 0;
                arrowCount = 0;
                R1Y = 20;
                r1health = 200;
                R1presence = false;
                loadedArrow = 9;
                stage3(rightmove, score, fruit, heart, removeCharacter, wallX, wallY, wallsize, GameExit, princehealth, heroX, heroY, archerManArrow, arrowCount, arrowX, arrowY, Up_enemy_direction, Down_enemy_direction, UpX, UpY, UpfireCount, UpfireX, UpfireY, DownX, DownY, DownfireCount, DownfireX, DownfireY, R1fireCount, R1X, R1Y, R1direction, R1steps, R1fireX, R1fireY, r1health, isEnemy1Dead, R1presence, R1collision, side_enemy, Hero, maze2, enemy1, r2health, loadedArrow, isFire, R2presence, bomb);
            }
        }

        else if (option == "3")
        {
            GameExit = true;
            score = 0;
            princehealth = 100;
            r1health = 100;
            arrowCount = 0;
            R1fireCount = 0;
            rightmove = 0;
            loadedArrow = 9;
            R1steps = 0;
            wallX = 0;
            wallY = 0;
            wallsize = 0;
            R1presence = false;
            checkbush = true;
            R1collision = 0;
            heroX = 3;
            heroY = 17;
            stage1(rightmove, score, fruit, checkbush, heart, removeCharacter, wallX, wallY, wallsize, GameExit, isEnemy1Dead, princehealth, r1health, arrowCount, R1presence, R1steps, R1direction, R1fireCount, R1collision, heroX, heroY, archerManArrow, R1X, R1Y, R1fireX, R1fireY, arrowX, arrowY, Hero, maze, enemy1, r2health, loadedArrow, isFire, R2presence, bomb);
        }

        else if (option == "4")
        {
            story(isPrintstory);
        }

        else if (option == "5")
        {
            control();
        }

        else if (option == "6")
        {
            gamerunning = false;
        }

        else
        {
            cout << endl;
            cout << "Invalid Option." << endl;
            cout << "Press any key to Continue...";
            getch();
        }
    }
}

// Front page
void story(bool &isPrintstory)
{
    system("cls");
    gameheader();
    setColor(15);
    cout << endl
         << endl;
    textanimation("          In a kingdom long ago, there lived a Prince skilled in archery named Alexander. One day, the kingdom was invaded by an army of evil creatures lead by Lady Night and Lord shadow.", isPrintstory);
    cout << endl
         << endl;
    textanimation("          Prince found himself facing a daunting task - he was the only one left to defend the kingdom. So, he gathered information about the enemy and comes to know that the Lady Night has known some magic and the Lord Shadow is always with its twin bodyguards named as Blade and Devi. ", isPrintstory);
    cout << endl
         << endl;
    textanimation("          Despite the overwhelming odds, Prince refused to back down. With his bow and arrow, he stood tall and prepared for battle. As the enemy charged towards him, Prince calmly took aim and let fly his arrows, taking down one enemy after another.", isPrintstory);
    cout << endl
         << endl;
    textanimation("          With every arrow he loosed, Prince grew more confident in his abilities. His movements became fluid and graceful, and soon he was dodging incoming attacks with ease. The battle continued for hours, but Prince refused to give up. Finally, the Lord Shadow fell before his arrows. The kingdom was saved, and Prince emerged victorious, hailed as a hero by the people.", isPrintstory);
    cout << endl
         << endl;
    cout << "Press any key to Continue...";
    isPrintstory = true;
    getch();
}
void control()
{
    system("cls");
    gameheader();
    setColor(15);
    cout << endl
         << endl;
    cout << "  Move UP  .............  Up arrow key " << endl;
    cout << "  Move Down ............  Down arrow key " << endl;
    cout << "  Move Right ...........  Right arrow key " << endl;
    cout << "  Move Left ............  Left arrow key " << endl;
    cout << "  Firing   .............  SpaceBar " << endl;
    cout << "  Exit Game ............  Escape key " << endl
         << endl;
    cout << "Press Any key to Continue...";
    getch();
}

void stage1(int &rightmove, int &score, char &fruit, bool &checkbush, char &heart, bool &removeCharacter, int &wallX, int &wallY, int &wallsize, bool &GameExit, bool &isEnemy1Dead, int &princehealth, int &r1health, int &arrowCount, bool &R1presence, int &R1steps, string &R1direction, int &R1fireCount, int &R1collision, int &heroX, int &heroY, char &archerManArrow, int &R1X, int &R1Y, int R1fireX[], int R1fireY[], int arrowX[], int arrowY[], char Hero[][5], char maze[][107], char enemy1[][4], int &r2health, int &loadedArrow, bool &isFire, bool &R2presence, int &bomb)
{
    system("cls");
    gameheader();
    printstage1(maze);
    printhero(heroX, heroY, Hero);
    printbush();
    while (GameExit)
    {
        collisionwithbush(fruit, checkbush, arrowCount, arrowX, arrowY);
        if (rightmove == 2)
        {
            rightmove++;
            wallX = 12;
            wallY = 16;
            wallsize = 5;
            wallremove(wallX, wallY, wallsize);
        }
        if (isprintR2(rightmove, R1collision) == true)
        {
            wallX = 12;
            wallY = 16;
            wallsize = 5;
            wall(wallX, wallY, wallsize);
            R1presence = true;
            updateEnemypresence(R1presence, R2presence);
            printR1(R1X, R1Y, enemy1);
            R1move(R1steps, R1direction, R1X, R1Y, enemy1);
            if (R1steps == 8)
            {
                R1fire(R1fireCount, R1X, R1Y, R1fireX, R1fireY);
                R1steps = 0;
            }
            collisionwithR1(score, removeCharacter, r1health, isEnemy1Dead, arrowCount, R1presence, R1collision, R1X, R1Y, arrowX, arrowY);
            R1firecollisions(princehealth, R1presence, R1fireCount, heroX, heroY, R1fireX, R1fireY);
        }
        if (removeCharacter == true)
        {
            eraseR1(R1X, R1Y);
            R1presence = false;
            updateEnemypresence(R1presence, R2presence);
            removeCharacter = false;
        }

        R1fireMove(R1fireCount, archerManArrow, R1fireX, R1fireY);
        moveArrow(arrowCount, archerManArrow, arrowX, arrowY);
        printscore(score);
        printherohealth(heart, GameExit, princehealth, r1health, r2health);
        printR1health(heart, r1health, princehealth, r2health);
        reload(loadedArrow, isFire);
        printloadedArrows(loadedArrow, archerManArrow);

        // move into stage 2
        if (isEnemy1Dead == true)
        {
            wallX = 91;
            wallY = 16;
            wallsize = 5;
            wallremove(wallX, wallY, wallsize);
            isEnemy1Dead = false;
        }
        if (heroX > 92)
        {
            youwin();
            break;
        }

        if (GetAsyncKeyState(VK_LEFT))
        {
            heroLeft(score, fruit, princehealth, heroX, heroY, Hero, bomb);
        }
        if (GetAsyncKeyState(VK_RIGHT))
        {
            heroRight(rightmove, score, fruit, princehealth, heroX, heroY, Hero, bomb);
        }
        if (GetAsyncKeyState(VK_UP))
        {
            heroUp(score, fruit, princehealth, heroX, heroY, Hero, bomb);
        }
        if (GetAsyncKeyState(VK_DOWN))
        {
            heroDown(score, fruit, princehealth, heroX, heroY, Hero, bomb);
        }
        if (GetAsyncKeyState(VK_SPACE))
        {
            if (isFire == true)
            {
                createArrow(arrowCount, heroX, heroY, archerManArrow, arrowX, arrowY);
                loadedArrow--;
            }
        }
        if (GetAsyncKeyState(VK_ESCAPE))
        {

            GameExit = false;
        }
        Sleep(100);
    }
}

void stage2(int &rightmove, int &score, char &fruit, bool &checkbush, char &heart, bool &removeCharacter, int &wallX, int &wallY, int &wallsize, bool &GameExit, bool &isEnemy2Dead, int &princehealth, int &r2health, int &arrowCount, bool &R2presence, int &R2steps, string &R2direction, int &R2fireCount, int &R2collision, int &heroX, int &heroY, char &archerManArrow, int &R2X, int &R2Y, int R2fireX[], int R2fireY[], int arrowX[], int arrowY[], bool &Move_to_stage3, char Hero[][5], char maze[][107], char enemy2[][5], int &r1health, int &loadedArrow, bool &isFire, bool &R1presence, int &bomb)
{
    system("cls");
    gameheader();
    printstage1(maze);
    printhero(heroX, heroY, Hero);
    printbush();
    Move_to_stage3 = false;
    updateMoveNextStage(Move_to_stage3);
    while (GameExit)
    {
        collisionwithbush(fruit, checkbush, arrowCount, arrowX, arrowY);
        if (rightmove == 2)
        {
            wallX = 12;
            wallY = 16;
            wallsize = 5;
            rightmove++;
            wallremove(wallX, wallY, wallsize);
        }
        if (isprintR2(rightmove, R2collision) == true)
        {
            wallX = 12;
            wallY = 16;
            wallsize = 5;
            wall(wallX, wallY, wallsize);
            R2presence = true;
            updateEnemypresence(R1presence, R2presence);
            printR2(R2X, R2Y, enemy2);
            R2move(R2steps, R2direction, R2X, R2Y, enemy2);
            if (R2steps == 5)
            {
                R2fire(R2fireCount, R2X, R2Y, R2fireX, R2fireY);
                R2steps = 0;
            }
            collisionwithR2(score, removeCharacter, isEnemy2Dead, r2health, arrowCount, R2presence, R2collision, R2X, R2Y, arrowX, arrowY);
            R2firecollisions(princehealth, R2presence, R2fireCount, heroX, heroY, R2fireX, R2fireY);
            createBombs(r2health, bomb, R2presence);
        }
        if (removeCharacter == true)
        {
            eraseR2(R2X, R2Y);
            R2presence = false;
            updateEnemypresence(R1presence, R2presence);
            removeCharacter = false;
        }

        moveArrow(arrowCount, archerManArrow, arrowX, arrowY);
        R2fireMove(R2fireCount, archerManArrow, R2fireX, R2fireY);
        printR2health(heart, r2health, princehealth, r1health);
        printscore(score);
        printherohealth(heart, GameExit, princehealth, r1health, r2health);
        printR2health(heart, r2health, princehealth, r1health);
        printloadedArrows(loadedArrow, archerManArrow);
        reload(loadedArrow, isFire);

        if (isEnemy2Dead == true)
        {
            wallX = 91;
            wallY = 16;
            wallsize = 5;
            wallremove(wallX, wallY, wallsize);
            isEnemy2Dead = false;
        }
        if (heroX > 92)
        {
            Move_to_stage3 = true;
            updateMoveNextStage(Move_to_stage3);
            break;
        }

        if (GetAsyncKeyState(VK_LEFT))
        {
            heroLeft(score, fruit, princehealth, heroX, heroY, Hero, bomb);
        }
        if (GetAsyncKeyState(VK_RIGHT))
        {
            heroRight(rightmove, score, fruit, princehealth, heroX, heroY, Hero, bomb);
        }
        if (GetAsyncKeyState(VK_UP))
        {
            heroUp(score, fruit, princehealth, heroX, heroY, Hero, bomb);
        }
        if (GetAsyncKeyState(VK_DOWN))
        {
            heroDown(score, fruit, princehealth, heroX, heroY, Hero, bomb);
        }
        if (GetAsyncKeyState(VK_SPACE))
        {
            if (isFire == true)
            {
                createArrow(arrowCount, heroX, heroY, archerManArrow, arrowX, arrowY);
                loadedArrow--;
            }
        }
        if (GetAsyncKeyState(VK_ESCAPE))
        {
            GameExit = false;
        }
        Sleep(100);
    }
}

void stage3(int &rightmove, int &score, char &fruit, char &heart, bool &removeCharacter, int &wallX, int &wallY, int &wallsize, bool &GameExit, int &princehealth, int &heroX, int &heroY, char &archerManArrow, int &arrowCount, int arrowX[], int arrowY[], string &Up_enemy_direction, string &Down_enemy_direction, int &UpX, int &UpY, int &UpfireCount, int UpfireX[], int UpfireY[], int &DownX, int &DownY, int &DownfireCount, int DownfireX[], int DownfireY[], int &R1fireCount, int &R1X, int &R1Y, string &R1direction, int &R1steps, int R1fireX[], int R1fireY[], int &r1health, bool &isEnemy1Dead, bool &R1presence, int &R1collision, string side_enemy[][1], char Hero[][5], string maze2[][1], char enemy1[][4], int &r2health, int &loadedArrow, bool &isFire, bool &R2presence, int &bomb)
{
    system("cls");
    gameheader();
    printstage2(maze2);
    printhero(heroX, heroY, Hero);
    while (GameExit)
    {
        if (rightmove == 2)
        {
            rightmove++;
            wallX = 12;
            wallY = 23;
            wallsize = 5;
            wallremove(wallX, wallY, wallsize);
        }
        if (isprintR1(rightmove, R1collision) == true)
        {
            wallX = 12;
            wallY = 23;
            wallsize = 5;
            wall(wallX, wallY, wallsize);
            R1presence = true;
            updateEnemypresence(R1presence, R2presence);
            printR1(R1X, R1Y, enemy1);
            R1move(R1steps, R1direction, R1X, R1Y, enemy1);
            if (R1steps == 8)
            {
                R1fire(R1fireCount, R1X, R1Y, R1fireX, R1fireY);
                R1steps = 0;
            }
            collisionwithR1(score, removeCharacter, r1health, isEnemy1Dead, arrowCount, R1presence, R1collision, R1X, R1Y, arrowX, arrowY);
            R1firecollisions(princehealth, R1presence, R1fireCount, heroX, heroY, R1fireX, R1fireY);

            if (r1health <= 150)
            {
                print_side_enemy(UpX, UpY, side_enemy);
                side_enemy1_move(UpX, UpY, Up_enemy_direction, side_enemy);
                if (R1steps == 5)
                {
                    Upfire(UpfireCount, UpX, UpY, UpfireX, UpfireY);
                }
                Upfirecollisions(princehealth, R1presence, UpfireCount, heroX, heroY, UpfireX, UpfireY);
            }
            if (r1health <= 100)
            {
                print_side_enemy(DownX, DownY, side_enemy);
                side_enemy2_move(DownX, DownY, Down_enemy_direction, side_enemy);
                if (R1steps == 5)
                {
                    Downfire(DownfireCount, DownX, DownY, DownfireX, DownfireY);
                }
                Downfirecollisions(princehealth, R1presence, DownfireCount, heroX, heroY, DownfireX, DownfireY);
            }
        }

        R1fireMove(R1fireCount, archerManArrow, R1fireX, R1fireY);
        UpfireMove(UpfireCount, archerManArrow, UpfireX, UpfireY);
        DownfireMove(DownfireCount, archerManArrow, DownfireX, DownfireY);
        moveArrow(arrowCount, archerManArrow, arrowX, arrowY);
        printscore(score);
        printherohealth(heart, GameExit, princehealth, r1health, r2health);
        printR1health(heart, r1health, princehealth, r2health);
        reload(loadedArrow, isFire);
        printloadedArrows(loadedArrow, archerManArrow);

        if (removeCharacter == true)
        {
            eraseR1(R1X, R1Y);
            erase_side_enemy(UpX, UpY);
            erase_side_enemy(DownX, DownY);
            R1presence = false;
            updateEnemypresence(R1presence, R2presence);
            removeCharacter = false;
        }
        // exiting from game
        if (isEnemy1Dead == true)
        {
            wallX = 91;
            wallY = 23;
            wallsize = 5;
            wallremove(wallX, wallY, wallsize);
            isEnemy1Dead = false;
        }
        if (heroX > 94)
        {
            credits();
            break;
        }

        if (GetAsyncKeyState(VK_LEFT))
        {
            heroLeft(score, fruit, princehealth, heroX, heroY, Hero, bomb);
        }
        if (GetAsyncKeyState(VK_RIGHT))
        {
            heroRight(rightmove, score, fruit, princehealth, heroX, heroY, Hero, bomb);
        }
        if (GetAsyncKeyState(VK_UP))
        {
            heroUp(score, fruit, princehealth, heroX, heroY, Hero, bomb);
        }
        if (GetAsyncKeyState(VK_DOWN))
        {
            heroDown(score, fruit, princehealth, heroX, heroY, Hero, bomb);
        }
        if (GetAsyncKeyState(VK_SPACE))
        {
            if (isFire == true)
            {
                createArrow(arrowCount, heroX, heroY, archerManArrow, arrowX, arrowY);
                loadedArrow--;
            }
        }
        if (GetAsyncKeyState(VK_ESCAPE))
        {

            GameExit = false;
        }
        Sleep(100);
    }
}

// Common Functions
void loadingpage()
{
    system("cls");
    gameheader();
    headerpic();
    char load = 219;
    int load1 = 0;
    setColor(15);
    gotoxy(108, 15);
    cout << "Loading.....";
    gotoxy(108, 17);
    while (load1 < 200)
    {
        cout << load;
        load1 = load1 + 10;
        Sleep(200);
    }
    gotoxy(108, 19);
    cout << "Press any key to continue....";
    getch();
}
void gotoxy(int x, int y)
{
    COORD coordinates;
    coordinates.X = x;
    coordinates.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coordinates);
}
void printstage1(char maze[][107])
{
    setColor(5);
    gotoxy(0, 15);
    for (int x = 0; x < 14; x++)
    {
        for (int y = 0; y < 107; y++)
        {
            cout << maze[x][y];
        }
        cout << endl;
        Sleep(100);
    }
}
void printstage2(string maze2[][1])
{
    setColor(5);
    gotoxy(0, 15);
    for (int x = 0; x < 22; x++)
    {
        for (int y = 0; y < 1; y++)
        {
            Sleep(100);
            cout << maze2[x][y];
        }
        cout << endl;
    }
}
void printbush()
{
    setColor(2);
    gotoxy(50, 16);
    cout << "(________)" << endl;
    gotoxy(50, 17);
    cout << " (______)" << endl;
    gotoxy(50, 18);
    cout << "  (____)" << endl;
}
void removebush(char &fruit, bool &checkbush)
{
    gotoxy(50, 16);
    cout << "          " << endl;
    gotoxy(50, 17);
    cout << "         " << endl;
    gotoxy(50, 18);
    cout << "        " << endl;
    setColor(6);
    gotoxy(53, 18);
    cout << fruit << endl;
    checkbush = false;
}
char getCharAtxy(short int x, short int y)
{
    CHAR_INFO ci;
    COORD xy = {0, 0};
    SMALL_RECT rect = {x, y, x, y};
    COORD coordBufSize;
    coordBufSize.X = 1;
    coordBufSize.Y = 1;
    return ReadConsoleOutput(GetStdHandle(STD_OUTPUT_HANDLE), &ci, coordBufSize, xy, &rect) ? ci.Char.AsciiChar
                                                                                            : ' ';
}
void gameheader()
{
    setColor(11);
    cout << endl;
    gotoxy(7, 0);
    cout << "   _____                .__                   __________        .__                                  " << endl;
    gotoxy(7, 1);
    cout << "  /  _  \\_______   ____ |  |__   ___________  \\______   \\_______|__| ____   ____  ____            " << endl;
    gotoxy(7, 2);
    cout << " /  /_\\  \\_  __ \\_/ ___\\|  |  \\_/ __ \\_  __ \\  |     ___/\\_  __ \\  |/    \\_/ ___\\/ __ \\  " << endl;
    gotoxy(7, 3);
    cout << "/    |    \\  | \\/\\  \\___|   Y  \\  ___/|  | \\/  |    |     |  | \\/  |   |  \\  \\__\\  ___/    " << endl;
    gotoxy(7, 4);
    cout << "\\____|__  /__|    \\___  >___|  /\\___  >__|     |____|     |__|  |__|___|  /\\___  >___  >         " << endl;
    gotoxy(7, 5);
    cout << "        \\/            \\/     \\/     \\/                                  \\/     \\/    \\/       " << endl;
    gotoxy(7, 6);
    cout << endl;
    gotoxy(7, 7);
    cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
    cout << endl;
}
void wall(int &wallX, int &wallY, int &wallsize)
{
    setColor(5);
    for (int j = 0; j < wallsize; j++)
    {
        gotoxy(wallX, wallY + j);
        cout << "#" << endl;
    }
}
void wallremove(int &wallX, int &wallY, int &wallsize)
{
    for (int j = 0; j < wallsize; j++)
    {
        gotoxy(wallX, wallY + j);
        for (double k = 0; k < 12000000; k++)
            ;
        cout << " " << endl;
    }
}
void headerpic()
{
    setColor(10);
    cout << "                     :*%%%#########@@@@@@####@@@:.-.                                     " << endl;
    cout << "                         *                     :=#@@@@*-                  :=+*-          " << endl;
    cout << "                         *                             :+%@@@#=.      .:%@@@%%.          " << endl;
    cout << "                         *                                 .=*@@@#=    .-*+@*.           " << endl;
    cout << "                         =.                                    -#@@@+=*-                 " << endl;
    cout << "                         -:                                     .+%**@***:               " << endl;
    cout << "                          +                                  .+*: *@@@@@@@+              " << endl;
    cout << "                          +                               :*=  .+@@@@@@*+@@#             " << endl;
    cout << "                          =.                           =*=  :=#@@@@@@%-  +@@#            " << endl;
    cout << "                      -+#%%%#@@@@@@%@@@%%#-        .+*:  .#@@@@@@@@@=     *@@#           " << endl;
    cout << "                   :*@@@@@@@@@@@@@@@@@*=:        :*+.  +@@@@@@@@@#.        %@@=          " << endl;
    cout << "                 -%@@@@@@@@@@@@@@@@#-         :*=  .=#@@@@@@@@@@-          .@@@.         " << endl;
    cout << "                +@@@@@@@@@@@@@@@@-.       =*-    *#@@@@@@@@@@*              +@@*         " << endl;
    cout << "            -*@%#@@@@@@@@@@@@@@@@@+   -*=   :=*%@@@@@@@@@@@*                 .@@+        " << endl;
    cout << "          =%%=-. .#@@@@@@@@@@@@@@@@==*==*@@@@@@@@@@@@@@**                     #@*        " << endl;
    cout << "        :%@+      :@@@@@@@@@@@@@%*#@*#@@@@@@@@@@@@@#+@*.                      =@%        " << endl;
    cout << "       =@*.       =@@@@@@@@@@@%*#@@@@@@@@@@@@@@@@@#:*.                        :@%        " << endl;
    cout << "      +@-        :@@@@@@@@@@@**=@@@@@@@@@@@@@@@@@@:                           .@%        " << endl;
    cout << "           :+%@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*::::                           %%         " << endl;
    cout << "        .=#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@*    :::-:                     .@=         " << endl;
    cout << "      .#@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@.        :---.                *@          " << endl;
    cout << "    *@@@@@@@@@@@@@@@%*=+%@@%@@@@@@@@@@@@@@@@@@%#=            :----.         *%           " << endl;
    cout << "   .#@@@@@@@@@@@@@#-       :*@@@@@@@@@@@@@@@@@@@%                    :---: .@+           " << endl
         << endl;
}
void textanimation(string a, bool &isPrintstory)
{
    int i;
    double k;
    for (i = 0; a[i] != '\0'; i++)
    {
        if (GetAsyncKeyState(VK_SHIFT))
        {
            isPrintstory = false;
        }
        if (isPrintstory == true)
        {
            for (k = 0; k < 6000000; k++)
                ;
            cout << a[i];
        }
        else
        {
            cout << a[i];
        }
    }
}
bool isprintR1(int &rightmove, int &R1collision)
{
    if (rightmove == 25 && R1collision < 20)
    {
        return true;
    }
    return false;
}
bool isprintR2(int &rightmove, int &R2collision)
{
    if (rightmove == 25 && R2collision < 10)
    {
        return true;
    }
    return false;
}
void gameover()
{
    setColor(12);
    string num;
    gotoxy(15, 16);
    cout << "    ______                                ___                                 " << endl;
    gotoxy(15, 17);
    cout << "  .' ___  |                             .'   `.                               " << endl;
    gotoxy(15, 18);
    cout << " / .'   \\_|  ,--.   _ .--..--.  .---.  /  .-.  \\ _   __  .---.  _ .--.      " << endl;
    gotoxy(15, 19);
    cout << " | |   ____ `'_\\ : [ `.-. .-. |/ /__\\\\ | |   | |[ \\ [  ]/ /__\\[ `/'`\\]   " << endl;
    gotoxy(15, 20);
    cout << " \\ `.___]  |// | |, | | | | | || \\__., \\  `-'  / \\ \\/ / | \\__., | |     " << endl;
    gotoxy(15, 21);
    cout << "  `._____.' \\'-;__/[___||__||__]'.__.'  `.___.'   \\__/   '.__.'[___]        " << endl;
    gotoxy(15, 23);
    cout << "Press any digit key to continue...";
    cin >> num;
}
void youwin()
{
    setColor(10);
    string num;
    gotoxy(15, 16);
    cout << " ____  ____                 ____      ____  _                   " << endl;
    gotoxy(15, 17);
    cout << "|_  _||_  _|               |_  _|    |_  _|(_)                  " << endl;
    gotoxy(15, 18);
    cout << "  \\ \\  / / .--.   __   _     \\ \\  /\\  / /  __   _ .--.     " << endl;
    gotoxy(15, 19);
    cout << "   \\ \\/ // .'`\\ \\[  | | |     \\ \\/  \\/ /  [  | [ `.-. |  " << endl;
    gotoxy(15, 20);
    cout << "   _|  |_| \\__. | | \\_/ |,     \\  /\\  /    | |  | | | |     " << endl;
    gotoxy(15, 21);
    cout << "  |______|'.__.'  '.__.'_/      \\/  \\/    [___][___||__]      " << endl;
    gotoxy(15, 23);
    cout << "Press Any digit key to continue....";
    cin >> num;
}
void setColor(int color)
{
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, color);
}
void reload(int &loadedArrow, bool &isFire)
{
    if (loadedArrow <= 0)
    {
        isFire = false;
    }
    if (isFire == false)
    {
        loadedArrow++;
    }
    if (loadedArrow == 9)
    {
        isFire = true;
    }
}
void printloadedArrows(int &loadedArrow, char &archerManArrow)
{
    gotoxy(84, 13);
    cout << "Arrows : " << archerManArrow << " X " << loadedArrow;
}
void credits()
{
    system("cls");
    gameheader();
    gotoxy(46, 10);
    setColor(1);
    cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";
    gotoxy(55, 12);
    setColor(9);
    cout << "    Credits      ";
    gotoxy(55, 14);
    setColor(9);
    cout << "  Game  Designer ";
    gotoxy(55, 16);
    setColor(11);
    cout << "   Abdul Rehman  ";
    gotoxy(55, 19);
    setColor(9);
    cout << "  Story  Writing ";
    setColor(11);
    gotoxy(55, 21);
    cout << "   Abdul Rehman  ";
    gotoxy(55, 24);
    setColor(9);
    cout << "Special Thanks to";
    setColor(11);
    gotoxy(55, 26);
    cout << "   Anas  Mustafa ";
    setColor(11);
    gotoxy(55, 27);
    cout << "    Wali Ahmad   ";
    setColor(11);
    gotoxy(55, 28);
    cout << "   Abdul  Sabur   ";
    gotoxy(46, 30);
    setColor(1);
    cout << "XXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXXX";
    gotoxy(0, 32);
    string num;
    cout << "Press any key(+ Enter) to continue..";
    cin >> num;
}
void createBombs(int &r2health, int &bomb, bool &R2presence)
{
    if ((r2health < 60 && bomb < 4) && R2presence == true)
    {
        int x = 0, y = 0;
        x = 14 + rand() % 40;
        y = 16 + rand() % 10;
        gotoxy(x, y);
        setColor(4);
        cout << "0";
        bomb++;
    }
}

// score functions
void addscore(int &score)
{
    score = score + 5;
}
void fruitscore(int &score)
{
    score = score + 2;
}
void printscore(int &score)
{
    setColor(15);
    gotoxy(35, 13);
    cout << "Score : " << score;
    updateScoreData(score);
}

// health functions
void herohealth(int &princehealth)
{
    princehealth = princehealth - 10;
}
void printherohealth(char &heart, bool &GameExit, int &princehealth, int &r1health, int r2health)
{
    if (princehealth <= 0)
    {
        GameExit = false;
        princehealth = 0;
        gotoxy(5, 13);
        cout << "Prince : " << princehealth << " " << heart << " " << endl;
        updateHealthData(princehealth, r1health, r2health);
        gameover();
    }
    else
    {
        gotoxy(5, 13);
        cout << "Prince : " << princehealth << " " << heart << " " << endl;
        updateHealthData(princehealth, r1health, r2health);
    }
}
void fruitrecoverhealth(int &princehealth)
{
    princehealth = princehealth + 50;
    if (princehealth > 100)
    {
        princehealth = 100;
    }
}
void bombDamage(int &princehealth)
{
    princehealth = princehealth - 20;
    if (princehealth < 0)
    {
        princehealth = 0;
    }
}
void R1health(bool &removeCharacter, int &r1health, bool &isEnemy1Dead)
{
    r1health = r1health - 10;
    if (r1health == 0)
    {
        isEnemy1Dead = true;
        removeCharacter = true;
    }
}
void printR1health(char &heart, int &r1health, int &princehealth, int r2health)
{
    if (r1health < 0)
    {
        r1health = 0;
    }
    gotoxy(60, 13);
    setColor(15);
    cout << "Robber 1 : " << r1health << " " << heart << " " << endl;
    updateHealthData(princehealth, r1health, r2health);
}
void R2health(bool &removeCharacter, bool &isEnemy2Dead, int &r2health)
{
    r2health = r2health - 10;
    if (r2health == 0)
    {
        isEnemy2Dead = true;
        removeCharacter = true;
    }
}
void printR2health(char &heart, int &r2health, int &princehealth, int &r1health)
{
    if (r2health < 0)
    {
        r2health = 0;
    }
    gotoxy(60, 13);
    setColor(15);
    cout << "Robber 2 : " << r2health << " " << heart << " " << endl;
    updateHealthData(princehealth, r1health, r2health);
}

// hero fire Collision Functions
void collisionwithbush(char &fruit, bool &checkbush, int &arrowCount, int arrowX[], int arrowY[])
{
    for (int x = 0; x < arrowCount; x++)
    {
        if (checkbush == true)
        {
            if (arrowX[x] == 40 && (arrowY[x] == 16 || arrowY[x] == 17 || arrowY[x] == 18))
            {
                removebush(fruit, checkbush);
            }
        }
    }
}
void collisionwithR1(int &score, bool &removeCharacter, int &r1health, bool &isEnemy1Dead, int &arrowCount, bool &R1presence, int &R1collision, int &R1X, int &R1Y, int arrowX[], int arrowY[])
{
    for (int x = 0; x < arrowCount; x++)
    {
        if (R1presence == true)
        {
            if (arrowX[x] + 1 == R1X && (arrowY[x] == R1Y || arrowY[x] == R1Y + 2))
            {
                R1collision++;
                addscore(score);
                R1health(removeCharacter, r1health, isEnemy1Dead);
            }
            if (R1X - 1 == arrowX[x] && R1Y + 1 == arrowY[x])
            {
                R1collision++;
                addscore(score);
                R1health(removeCharacter, r1health, isEnemy1Dead);
            }
        }
    }
}
void collisionwithR2(int &score, bool &removeCharacter, bool &isEnemy2Dead, int &r2health, int &arrowCount, bool &R2presence, int &R2collision, int &R2X, int &R2Y, int arrowX[], int arrowY[])
{
    for (int x = 0; x < arrowCount; x++)
    {
        if (R2presence == true)
        {
            if (arrowX[x] + 1 == R2X && (arrowY[x] == R2Y || arrowY[x] == R2Y + 2))
            {
                R2collision++;
                addscore(score);
                R2health(removeCharacter, isEnemy2Dead, r2health);
            }
            if (R2X - 1 == arrowX[x] && R2Y + 1 == arrowY[x])
            {
                R2collision++;
                addscore(score);
                R2health(removeCharacter, isEnemy2Dead, r2health);
            }
        }
    }
}

// Hero print
void printhero(int &heroX, int &heroY, char Hero[][5])
{
    int x = heroX;
    int y = heroY;
    setColor(9);
    for (int i = 0; i < 3; i++)
    {
        gotoxy(x, y);
        for (int j = 0; j < 5; j++)
        {
            cout << Hero[i][j];
        }
        y++;
    }
}
// Hero remove
void erasehero(int &heroX, int &heroY)
{
    int x = heroX;
    int y = heroY;

    for (int i = 0; i < 3; i++)
    {
        gotoxy(x, y);
        for (int j = 0; j < 5; j++)
        {
            cout << " ";
        }
        y++;
    }
}

// hero movement
void heroUp(int &score, char &fruit, int &princehealth, int &heroX, int &heroY, char Hero[][5], int &bomb)
{
    char next1 = getCharAtxy(heroX, heroY - 1);
    char next2 = getCharAtxy(heroX + 1, heroY - 1);
    char next3 = getCharAtxy(heroX + 2, heroY - 1);
    char next4 = getCharAtxy(heroX + 3, heroY - 1);
    char next5 = getCharAtxy(heroX + 4, heroY - 1);
    if (next1 == ' ' && next2 == ' ' && next3 == ' ' && next4 == ' ' && next5 == ' ')
    {
        erasehero(heroX, heroY);
        heroY--;
        updateHeroCoordinate(heroX, heroY);
        printhero(heroX, heroY, Hero);
    }
    else if (next1 == fruit || next2 == fruit || next3 == fruit || next4 == fruit || next5 == fruit)
    {
        erasehero(heroX, heroY);
        heroY--;
        updateHeroCoordinate(heroX, heroY);
        printhero(heroX, heroY, Hero);
        fruitscore(score);
        fruitrecoverhealth(princehealth);
    }
    else if (next1 == '<' || next2 == '<' || next3 == '<' || next4 == '<' || next5 == '<')
    {
        erasehero(heroX, heroY);
        heroY--;
        updateHeroCoordinate(heroX, heroY);
        printhero(heroX, heroY, Hero);
    }
    else if (next1 == '0' || next2 == '0' || next3 == '0' || next4 == '0' || next5 == '0')
    {
        erasehero(heroX, heroY);
        heroY--;
        updateHeroCoordinate(heroX, heroY);
        printhero(heroX, heroY, Hero);
        bombDamage(princehealth);
        bomb--;
    }
}
void heroDown(int &score, char &fruit, int &princehealth, int &heroX, int &heroY, char Hero[][5], int &bomb)
{
    char next1 = getCharAtxy(heroX, heroY + 3);
    char next2 = getCharAtxy(heroX + 1, heroY + 3);
    char next3 = getCharAtxy(heroX + 2, heroY + 3);
    char next4 = getCharAtxy(heroX + 3, heroY + 3);
    char next5 = getCharAtxy(heroX + 4, heroY + 3);
    if (next1 == ' ' && next2 == ' ' && next3 == ' ' && next4 == ' ' && next5 == ' ')
    {
        erasehero(heroX, heroY);
        heroY++;
        updateHeroCoordinate(heroX, heroY);
        printhero(heroX, heroY, Hero);
    }
    else if (next1 == fruit || next2 == fruit || next3 == fruit || next4 == fruit || next5 == fruit)
    {
        erasehero(heroX, heroY);
        heroY++;
        updateHeroCoordinate(heroX, heroY);
        printhero(heroX, heroY, Hero);
        fruitscore(score);
        fruitrecoverhealth(princehealth);
    }
    else if (next1 == '<' || next2 == '<' || next3 == '<' || next4 == '<' || next5 == '<')
    {
        erasehero(heroX, heroY);
        heroY++;
        updateHeroCoordinate(heroX, heroY);
        printhero(heroX, heroY, Hero);
    }
    else if (next1 == '0' || next2 == '0' || next3 == '0' || next4 == '0' || next5 == '0')
    {
        erasehero(heroX, heroY);
        heroY++;
        updateHeroCoordinate(heroX, heroY);
        printhero(heroX, heroY, Hero);
        bombDamage(princehealth);
        bomb--;
    }
}
void heroRight(int &rightmove, int &score, char &fruit, int &princehealth, int &heroX, int &heroY, char Hero[][5], int &bomb)
{
    char next1 = getCharAtxy(heroX + 5, heroY);
    char next2 = getCharAtxy(heroX + 5, heroY + 1);
    char next3 = getCharAtxy(heroX + 5, heroY + 2);
    if (next1 == ' ' && next2 == ' ' && next3 == ' ')
    {
        erasehero(heroX, heroY);
        heroX++;
        updateHeroCoordinate(heroX, heroY);
        printhero(heroX, heroY, Hero);
        rightmove++;
    }
    else if (next1 == fruit || next2 == fruit || next3 == fruit)
    {
        erasehero(heroX, heroY);
        heroX++;
        updateHeroCoordinate(heroX, heroY);
        printhero(heroX, heroY, Hero);
        fruitscore(score);
        fruitrecoverhealth(princehealth);
        rightmove++;
        updateSteps(rightmove);
    }
    else if (next1 == '<' || next2 == '<' || next3 == '<')
    {
        erasehero(heroX, heroY);
        heroX++;
        updateHeroCoordinate(heroX, heroY);
        printhero(heroX, heroY, Hero);
        rightmove++;
    }
    else if (next1 == '0' || next2 == '0' || next3 == '0')
    {
        erasehero(heroX, heroY);
        heroX++;
        updateHeroCoordinate(heroX, heroY);
        printhero(heroX, heroY, Hero);
        bombDamage(princehealth);
        rightmove++;
        bomb--;
    }
    if (rightmove >= 25)
    {
        rightmove = 25;
        updateSteps(rightmove);
    }
}
void heroLeft(int &score, char &fruit, int &princehealth, int &heroX, int &heroY, char Hero[][5], int &bomb)
{
    char next1 = getCharAtxy(heroX - 1, heroY);
    char next2 = getCharAtxy(heroX - 1, heroY + 1);
    char next3 = getCharAtxy(heroX - 1, heroY + 2);
    if (next1 == ' ' && next2 == ' ' && next3 == ' ')
    {
        erasehero(heroX, heroY);
        heroX--;
        updateHeroCoordinate(heroX, heroY);
        printhero(heroX, heroY, Hero);
    }
    else if (next1 == fruit || next2 == fruit || next3 == fruit)
    {
        erasehero(heroX, heroY);
        heroX--;
        updateHeroCoordinate(heroX, heroY);
        printhero(heroX, heroY, Hero);
        fruitscore(score);
        fruitrecoverhealth(princehealth);
    }
    else if (next1 == '<' || next2 == '<' || next3 == '<')
    {
        erasehero(heroX, heroY);
        heroX--;
        updateHeroCoordinate(heroX, heroY);
        printhero(heroX, heroY, Hero);
    }
    else if (next1 == '0' || next2 == '0' || next3 == '0')
    {
        erasehero(heroX, heroY);
        heroX--;
        updateHeroCoordinate(heroX, heroY);
        printhero(heroX, heroY, Hero);
        bombDamage(princehealth);
        bomb--;
    }
}

// hero firing mechanism
void createArrow(int &arrowCount, int &heroX, int &heroY, char &archerManArrow, int arrowX[], int arrowY[])
{
    setColor(15);
    arrowX[arrowCount] = heroX + 4;
    arrowY[arrowCount] = heroY + 1;
    gotoxy(heroX + 4, heroY + 1);
    cout << archerManArrow;
    arrowCount++;
}
void moveArrow(int &arrowCount, char &archerManArrow, int arrowX[], int arrowY[])
{
    for (int x = 0; x < arrowCount; x++)
    {
        char next = getCharAtxy(arrowX[x] + 1, arrowY[x]);
        if (next != ' ')
        {
            eraseArrow(arrowX[x], arrowY[x]);
            makeArrowInactive(x, arrowCount, arrowX, arrowY);
        }
        else
        {
            eraseArrow(arrowX[x], arrowY[x]);
            arrowX[x] = arrowX[x] + 1;
            printArrow(arrowX[x], arrowY[x], archerManArrow);
        }
    }
}
void eraseArrow(int x, int y)
{
    gotoxy(x, y);
    cout << " ";
}
void printArrow(int x, int y, char &archerManArrow)
{
    setColor(15);
    gotoxy(x, y);
    cout << archerManArrow;
}
void makeArrowInactive(int index, int &arrowCount, int arrowX[], int arrowY[])
{
    for (int x = index; x < arrowCount; x++)
    {
        arrowX[x] = arrowX[x + 1];
        arrowY[x] = arrowY[x + 1];
    }
    arrowCount--;
}

// Robbers print
void printR1(int &R1X, int &R1Y, char enemy1[][4])
{
    setColor(12);
    int x_axis = R1X;
    int y_axis = R1Y;

    for (int x = 0; x < 3; x++)
    {
        gotoxy(x_axis, y_axis);
        for (int y = 0; y < 4; y++)
        {
            cout << enemy1[x][y];
        }
        y_axis++;
    }
}
void printR2(int &R2X, int &R2Y, char enemy2[][5])
{
    setColor(12);
    int x_axis = R2X;
    int y_axis = R2Y;

    for (int x = 0; x < 3; x++)
    {
        gotoxy(x_axis, y_axis);
        for (int y = 0; y < 5; y++)
        {
            cout << enemy2[x][y];
        }
        y_axis++;
    }
}
// Robbers remove
void eraseR1(int &R1X, int &R1Y)
{
    int x_axis = R1X;
    int y_axis = R1Y;

    for (int x = 0; x < 3; x++)
    {
        gotoxy(x_axis, y_axis);
        for (int y = 0; y < 4; y++)
        {
            cout << " ";
        }
        y_axis++;
    }
}
void eraseR2(int &R2X, int &R2Y)
{
    int x_axis = R2X;
    int y_axis = R2Y;

    for (int x = 0; x < 3; x++)
    {
        gotoxy(x_axis, y_axis);
        for (int y = 0; y < 5; y++)
        {
            cout << " ";
        }
        y_axis++;
    }
}

// Robbers movement
void R1move(int &R1steps, string &R1direction, int &R1X, int &R1Y, char enemy1[][4])
{
    if (R1direction == "Up")
    {
        char next = getCharAtxy(R1X, R1Y - 1);
        if (next == ' ')
        {
            R1steps++;
            eraseR1(R1X, R1Y);
            R1Y--;
            printR1(R1X, R1Y, enemy1);
            updateR1Coordinate(R1X, R1Y);
        }
        else if (next == '#' || next == '_')
        {
            R1direction = "Down";
        }
    }
    else if (R1direction == "Down")
    {
        char next = getCharAtxy(R1X, R1Y + 3);
        if (next == ' ')
        {
            R1steps++;
            eraseR1(R1X, R1Y);
            R1Y++;
            printR1(R1X, R1Y, enemy1);
            updateR1Coordinate(R1X, R1Y);
        }
        else if (next == '#' || next == '_')
        {
            R1direction = "Up";
        }
    }
}
void R2move(int &R2steps, string &R2direction, int &R2X, int &R2Y, char enemy2[][5])
{
    if (R2direction == "Up")
    {
        char next = getCharAtxy(R2X, R2Y - 1);
        if (next == ' ')
        {
            R2steps++;
            eraseR2(R2X, R2Y);
            R2Y--;
            printR2(R2X, R2Y, enemy2);
            updateR2Coordinate(R2X, R2Y);
        }
        else if (next == '#')
        {
            R2direction = "Down";
        }
    }
    else if (R2direction == "Down")
    {
        char next = getCharAtxy(R2X, R2Y + 4);
        if (next == ' ')
        {
            R2steps++;
            eraseR2(R2X, R2Y);
            R2Y++;
            printR2(R2X, R2Y, enemy2);
            updateR2Coordinate(R2X, R2Y);
        }
        else if (next == '#')
        {
            R2direction = "Up";
        }
    }
}

// Robbers fire mechanism
void R1fire(int &R1fireCount, int &R1X, int &R1Y, int R1fireX[], int R1fireY[])
{
    R1fireX[R1fireCount] = R1X - 1;
    R1fireY[R1fireCount] = R1Y + 1;
    gotoxy(R1X - 2, R1Y + 1);
    cout << "<";
    R1fireCount++;
}
void R1fireMove(int &R1fireCount, char &archerManArrow, int R1fireX[], int R1fireY[])
{
    for (int x = 0; x < R1fireCount; x++)
    {
        char next = getCharAtxy(R1fireX[x] - 2, R1fireY[x]);
        if (next == archerManArrow)
        {
            eraseRfire(R1fireX[x], R1fireY[x]);
            R1fireX[x] = R1fireX[x] - 1;
            printRfire(R1fireX[x], R1fireY[x]);
        }
        else if (next != ' ')
        {
            eraseRfire(R1fireX[x], R1fireY[x]);
            R1fireInActive(x, R1fireCount, R1fireX, R1fireY);
        }
        else
        {
            eraseRfire(R1fireX[x], R1fireY[x]);
            R1fireX[x] = R1fireX[x] - 1;
            printRfire(R1fireX[x], R1fireY[x]);
        }
    }
}
void R1fireInActive(int index, int &R1fireCount, int R1fireX[], int R1fireY[])
{
    for (int x = index; x < R1fireCount; x++)
    {
        R1fireX[x] = R1fireX[x + 1];
        R1fireY[x] = R1fireY[x + 1];
    }
    R1fireCount--;
}
// Robber 2
void R2fire(int &R2fireCount, int &R2X, int &R2Y, int R2fireX[], int R2fireY[])
{
    R2fireX[R2fireCount] = R2X - 1;
    R2fireY[R2fireCount] = R2Y + 1;
    gotoxy(R2X - 2, R2Y + 1);
    cout << "<";
    R2fireCount++;
}
void R2fireMove(int &R2fireCount, char &archerManArrow, int R2fireX[], int R2fireY[])
{
    for (int x = 0; x < R2fireCount; x++)
    {
        char next = getCharAtxy(R2fireX[x] - 2, R2fireY[x]);
        if (next == archerManArrow)
        {
            eraseRfire(R2fireX[x], R2fireY[x]);
            R2fireX[x] = R2fireX[x] - 1;
            printRfire(R2fireX[x], R2fireY[x]);
        }
        else if (next != ' ')
        {
            eraseRfire(R2fireX[x], R2fireY[x]);
            R2fireInActive(x, R2fireCount, R2fireX, R2fireY);
        }
        else
        {
            eraseRfire(R2fireX[x], R2fireY[x]);
            R2fireX[x] = R2fireX[x] - 1;
            printRfire(R2fireX[x], R2fireY[x]);
        }
    }
}
void R2fireInActive(int index, int &R2fireCount, int R2fireX[], int R2fireY[])
{
    for (int x = index; x < R2fireCount; x++)
    {
        R2fireX[x] = R2fireX[x + 1];
        R2fireY[x] = R2fireY[x + 1];
    }
    R2fireCount--;
}

// same R1 & R2
void printRfire(int x, int y)
{
    setColor(4);
    gotoxy(x, y);
    cout << "<";
}
void eraseRfire(int x, int y)
{
    gotoxy(x, y);
    cout << "  ";
}

// robbers fire collision functions
void R1firecollisions(int &princehealth, bool &R1presence, int &R1fireCount, int &heroX, int &heroY, int R1fireX[], int R1fireY[])
{
    for (int x = 0; x < R1fireCount; x++)
    {
        if (R1presence == true)
        {
            if (R1fireX[x] == heroX + 5 && (R1fireY[x] == heroY || R1fireY[x] == heroY + 2))
            {
                herohealth(princehealth);
            }
            if (R1fireX[x] == heroX + 7 && R1fireY[x] == heroY + 1)
            {
                herohealth(princehealth);
            }
        }
    }
}
void R2firecollisions(int &princehealth, bool &R2presence, int &R2fireCount, int &heroX, int &heroY, int R2fireX[], int R2fireY[])
{
    for (int x = 0; x < R2fireCount; x++)
    {
        if (R2presence == true)
        {
            if (R2fireX[x] == heroX + 5 && (R2fireY[x] == heroY || R2fireY[x] == heroY + 1 || R2fireY[x] == heroY + 2))
            {
                herohealth(princehealth);
            }
            if (R2fireX[x] == heroX + 7 && R2fireY[x] == heroY + 1)
            {
                herohealth(princehealth);
            }
        }
    }
}

// stage 2 enemies firing mechanism (upward)
void Upfire(int &UpfireCount, int &UpX, int &UpY, int UpfireX[], int UpfireY[])
{
    UpfireX[UpfireCount] = UpX + 2;
    UpfireY[UpfireCount] = UpY + 3;
    gotoxy(UpX + 2, UpY + 3);
    cout << "v";
    UpfireCount++;
}
void UpfireMove(int &UpfireCount, char &archerManArrow, int UpfireX[], int UpfireY[])
{
    for (int x = 0; x < UpfireCount; x++)
    {
        char next = getCharAtxy(UpfireX[x], UpfireY[x] + 1);
        if (next == archerManArrow || next == 'v')
        {
            eraseUfire(UpfireX[x], UpfireY[x]);
            UpfireY[x] = UpfireY[x] + 1;
            printUfire(UpfireX[x], UpfireY[x]);
        }
        else if (next != ' ')
        {
            eraseUfire(UpfireX[x], UpfireY[x]);
            UpfireInActive(x, UpfireCount, UpfireX, UpfireY);
        }
        else
        {
            eraseUfire(UpfireX[x], UpfireY[x]);
            UpfireY[x] = UpfireY[x] + 1;
            printUfire(UpfireX[x], UpfireY[x]);
        }
    }
}
void UpfireInActive(int index, int &UpfireCount, int UpfireX[], int UpfireY[])
{
    for (int x = index; x < UpfireCount; x++)
    {
        UpfireX[x] = UpfireX[x + 1];
        UpfireY[x] = UpfireY[x + 1];
    }
    UpfireCount--;
}
void printUfire(int x, int y)
{
    setColor(8);
    gotoxy(x, y);
    cout << "v";
}
void eraseUfire(int x, int y)
{
    gotoxy(x, y);
    cout << "  ";
}

// stage 2 enemies firing mechanism (downward)
void Downfire(int &DownfireCount, int &DownX, int &DownY, int DownfireX[], int DownfireY[])
{
    DownfireX[DownfireCount] = DownX + 2;
    DownfireY[DownfireCount] = DownY - 2;
    gotoxy(DownX + 2, DownY - 2);
    cout << "^";
    DownfireCount++;
}
void DownfireMove(int &DownfireCount, char &archerManArrow, int DownfireX[], int DownfireY[])
{
    for (int x = 0; x < DownfireCount; x++)
    {
        char next = getCharAtxy(DownfireX[x], DownfireY[x] - 1);
        if (next == archerManArrow || next == 'v')
        {
            eraseDfire(DownfireX[x], DownfireY[x]);
            DownfireY[x] = DownfireY[x] - 1;
            printDfire(DownfireX[x], DownfireY[x]);
        }
        else if (next != ' ')
        {
            eraseDfire(DownfireX[x], DownfireY[x]);
            DownfireInActive(x, DownfireCount, DownfireX, DownfireY);
        }
        else
        {
            eraseDfire(DownfireX[x], DownfireY[x]);
            DownfireY[x] = DownfireY[x] - 1;
            printDfire(DownfireX[x], DownfireY[x]);
        }
    }
}
void DownfireInActive(int index, int &DownfireCount, int DownfireX[], int DownfireY[])
{
    for (int x = index; x < DownfireCount; x++)
    {
        DownfireX[x] = DownfireX[x + 1];
        DownfireY[x] = DownfireY[x + 1];
    }
    DownfireCount--;
}
void printDfire(int x, int y)
{
    setColor(8);
    gotoxy(x, y);
    cout << "^";
}
void eraseDfire(int x, int y)
{
    gotoxy(x, y);
    cout << "  ";
}

// printing side enemies of stage 2
void print_side_enemy(int X_axis, int Y_axis, string side_enemy[][1])
{
    setColor(14);
    for (int x = 0; x < 2; x++)
    {
        gotoxy(X_axis, Y_axis + x);
        for (int y = 0; y < 1; y++)
        {
            cout << side_enemy[x][y];
        }
    }
}

// removing side enemies of stage 2
void erase_side_enemy(int X_axis, int Y_axis)
{
    for (int x = 0; x < 2; x++)
    {
        gotoxy(X_axis, Y_axis + x);
        cout << "     ";
    }
}

// stage 2 side enemies movement (Up_enemy)
void side_enemy1_move(int &UpX, int &UpY, string &Up_enemy_direction, string side_enemy[][1])
{
    if (Up_enemy_direction == "Left")
    {
        char next = getCharAtxy(UpX - 1, UpY);
        if (next == ' ')
        {
            erase_side_enemy(UpX, UpY);
            UpX--;
            print_side_enemy(UpX, UpY, side_enemy);
        }
        else if (next == '#')
        {
            Up_enemy_direction = "Right";
        }
    }
    else if (Up_enemy_direction == "Right")
    {
        char next = getCharAtxy(UpX + 6, UpY);
        if (next == ' ')
        {
            erase_side_enemy(UpX, UpY);
            UpX++;
            print_side_enemy(UpX, UpY, side_enemy);
        }
        else if (next == '#')
        {
            Up_enemy_direction = "Left";
        }
    }
}
// stage 2 side enemies movement (Down_enemy)
void side_enemy2_move(int &DownX, int &DownY, string &Down_enemy_direction, string side_enemy[][1])
{
    if (Down_enemy_direction == "Left")
    {
        char next = getCharAtxy(DownX - 1, DownY);
        if (next == ' ')
        {
            erase_side_enemy(DownX, DownY);
            DownX--;
            print_side_enemy(DownX, DownY, side_enemy);
        }
        else if (next == '#')
        {
            Down_enemy_direction = "Right";
        }
    }
    else if (Down_enemy_direction == "Right")
    {
        char next = getCharAtxy(DownX + 6, DownY);
        if (next == ' ')
        {
            erase_side_enemy(DownX, DownY);
            DownX++;
            print_side_enemy(DownX, DownY, side_enemy);
        }
        else if (next == '#')
        {
            Down_enemy_direction = "Left";
        }
    }
}

// side enemies bullets collisions
void Upfirecollisions(int &princehealth, bool &R1presence, int &UpfireCount, int &heroX, int &heroY, int UpfireX[], int UpfireY[])
{
    for (int x = 0; x < UpfireCount; x++)
    {
        if (R1presence == true)
        {
            if ((UpfireX[x] == heroX || UpfireX[x] == heroX + 1 || UpfireX[x] == heroX + 2 || UpfireX[x] == heroX + 3 || UpfireX[x] == heroX + 4) && UpfireY[x] == heroY)
            {
                herohealth(princehealth);
            }
        }
    }
}
void Downfirecollisions(int &princehealth, bool &R1presence, int &DownfireCount, int &heroX, int &heroY, int DownfireX[], int DownfireY[])
{
    for (int x = 0; x < DownfireCount; x++)
    {
        if (R1presence == true)
        {
            if ((DownfireX[x] == heroX || DownfireX[x] == heroX + 1 || DownfireX[x] == heroX + 2 || DownfireX[x] == heroX + 3 || DownfireX[x] == heroX + 4) && DownfireY[x] == heroY)
            {
                herohealth(princehealth);
            }
        }
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////

// Data Parsing Function
string parseRecord(string line, int field)
{
    int commaCount = 1;
    string item;
    for (int i = 0; line[i] != '\0'; i++)
    {
        if (line[i] == ',')
        {
            commaCount = commaCount + 1;
        }
        else if (commaCount == field)
        {
            item = item + line[i];
        }
    }
    return item;
}

// stage storing
void storemaze1(char maze[][107], int &maze1row)
{
    fstream Maze1;
    Maze1.open("Maze1.txt", ios::out);
    for (int x = 0; x < maze1row; x++)
    {
        for (int y = 0; y < 107; y++)
        {
            Maze1 << maze[x][y];
        }
        cout << endl;
    }
    Maze1.close();
}
void loadmaze1(char maze[][107])
{
    int maze1row = 0;
    string line;
    fstream Maze1;
    Maze1.open("Maze1.txt", ios::in);
    while (getline(Maze1, line))
    {
        if (line != "")
        {
            for (int x = 0; x < 80; x++)
            {
                maze[maze1row][x] = line[x];
            }
            maze1row++;
        }
    }
    Maze1.close();
}

// storing score Data
void loadScoreData(int &score)
{
    string line;
    fstream scoreFile;
    scoreFile.open("ScoreData.txt", ios::in);
    while (getline(scoreFile, line))
    {
        if (line != "")
        {
            score = stoi(line);
        }
    }
    scoreFile.close();
}
void updateScoreData(int score)
{
    fstream scoreFile;
    scoreFile.open("ScoreData.txt", ios::out);
    scoreFile << score;
    scoreFile.close();
}

// storing next stage data
void loadMoveNextStage(bool &Move_to_stage3)
{
    string line;
    fstream nextStage;
    nextStage.open("NextStage.txt", ios::in);
    while (getline(nextStage, line))
    {
        if (line != "")
        {
            Move_to_stage3 = stoi(line);
        }
    }
    nextStage.close();
}
void updateMoveNextStage(bool Move_to_stage3)
{
    fstream nextStage;
    nextStage.open("NextStage.txt", ios::out);
    nextStage << Move_to_stage3;
    nextStage.close();
}

//  storing health Data
void loadHealthData(int &princehealth, int &r1health, int &r2health)
{
    string line;
    fstream healthData;
    healthData.open("HealthData.txt", ios::in);
    while (getline(healthData, line))
    {
        if (line != "")
        {
            princehealth = stoi(parseRecord(line, 1));
            r1health = stoi(parseRecord(line, 2));
            r2health = stoi(parseRecord(line, 3));
        }
    }
    healthData.close();
}
void updateHealthData(int princehealth, int r1health, int r2health)
{
    if (princehealth == 0)
    {
        princehealth = 100;
    }
    fstream healthData;
    healthData.open("HealthData.txt", ios::out);
    healthData << princehealth << ",";
    healthData << r1health << ",";
    healthData << r2health;
    healthData.close();
}

// storing coordinates of hero
void loadHeroCoordinate(int &heroX, int &heroY)
{
    string line;
    fstream heroCoordinates;
    heroCoordinates.open("HeroData.txt", ios::in);
    while (getline(heroCoordinates, line))
    {
        if (line != "")
        {
            heroX = stoi(parseRecord(line, 1));
            heroY = stoi(parseRecord(line, 2));
        }
    }
    heroCoordinates.close();
}
void updateHeroCoordinate(int heroX, int heroY)
{
    fstream heroCoordinates;
    heroCoordinates.open("HeroData.txt", ios::out);
    heroCoordinates << heroX << ",";
    heroCoordinates << heroY;
    heroCoordinates.close();
}

// storing enemy1 coordinates
void loadR1Coordinate(int &R1X, int &R1Y)
{
    string line;
    fstream R1Coordinates;
    R1Coordinates.open("R1Data.txt", ios::in);
    while (getline(R1Coordinates, line))
    {
        if (line != "")
        {
            R1X = stoi(parseRecord(line, 1));
            R1Y = stoi(parseRecord(line, 2));
        }
    }
    R1Coordinates.close();
}
void updateR1Coordinate(int R1X, int R1Y)
{
    fstream R1Coordinates;
    R1Coordinates.open("R1Data.txt", ios::out);
    R1Coordinates << R1X << ",";
    R1Coordinates << R1Y;
    R1Coordinates.close();
}

// storing enemy2 coordinates
void loadR2Coordinate(int &R2X, int &R2Y)
{
    string line;
    fstream R2Coordinates;
    R2Coordinates.open("R2Data.txt", ios::in);
    while (getline(R2Coordinates, line))
    {
        if (line != "")
        {
            R2X = stoi(parseRecord(line, 1));
            R2Y = stoi(parseRecord(line, 2));
        }
    }
    R2Coordinates.close();
}
void updateR2Coordinate(int R2X, int R2Y)
{
    fstream R2Coordinates;
    R2Coordinates.open("R2Data.txt", ios::out);
    R2Coordinates << R2X << ",";
    R2Coordinates << R2Y;
    R2Coordinates.close();
}

// storing enemies presence
void loadenemypresence(bool &R1presence, bool &R2presence)
{
    string line;
    fstream presence;
    presence.open("EnemyPresence.txt", ios::in);
    while (getline(presence, line))
    {
        if (line != "")
        {
            R1presence = stoi(parseRecord(line, 1));
            R2presence = stoi(parseRecord(line, 2));
        }
    }
    presence.close();
}
void updateEnemypresence(bool R1presence, bool R2presence)
{
    fstream presence;
    presence.open("EnemyPresence.txt", ios::out);
    presence << R1presence << ",";
    presence << R2presence;
    presence.close();
}

// storing the steps of the hero
void loadSteps(int &rightmove)
{
    string line;
    fstream steps;
    steps.open("HeroSteps.txt", ios::in);
    while(getline(steps, line))
    {
        if (line != "")
        {
            rightmove = stoi(line);
        }
    }
    steps.close();
}
void updateSteps(int &rightmove)
{
    fstream steps;
    steps.open("HeroSteps", ios::out);
    steps << rightmove;
    steps.close();
}