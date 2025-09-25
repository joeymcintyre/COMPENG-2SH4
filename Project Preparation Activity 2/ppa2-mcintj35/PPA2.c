#include <stdio.h>
#include "MacUILib.h"

// PREPROCESSOR CONSTANTS DEFINITION HERE
/////////////////////////////////////////
#define MAX_ROWS 10
#define MAX_COLUMNS 20
#define BOARDER_CHAR '#'
#define INITIAL_PLAYER_X 10
#define INITIAL_PLAYER_Y 5
#define PLAYER_SYMBOL '@'

//Advanced feature - changing the game speed (5 different levels)
#define SPEED_LEVELS_COUNT 5
int speedLevels[SPEED_LEVELS_COUNT] = {200000, 150000, 100000, 50000, 25000};
int currentSpeedIndex;

// Program Exiting Flag - old stuff
int exitFlag;

// For storing the user input - from PPA1
char input;

//objPos structure 
struct objPos
{
    int x;
    int y;
    char symbol;
};

struct objPos player;

//Direction enumeration
enum Direction
{
    STOP,
    UP,
    DOWN,
    LEFT,
    RIGHT,
};

enum Direction currentState;

// FUNCTION PROTOTYPING DEFINITION HERE
/////////////////////////////////////////

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);

// MAIN PROGRAM LOOP
/////////////////////////////////////////

int main(void)
{

    Initialize();

    while(!exitFlag)  
    {
        GetInput();

        RunLogic();

        DrawScreen();

        LoopDelay();
    }

    CleanUp();

}


// INITIALIZATION ROUTINE
/////////////////////////////////////////
void Initialize(void)
{
    MacUILib_init();
    MacUILib_clearScreen();

    input = 0; // NULL
    exitFlag = 0;  // not exiting    
   
    //initializeing player position and symbol
    player.x = INITIAL_PLAYER_X;
    player.y = INITIAL_PLAYER_Y;
    player.symbol = PLAYER_SYMBOL;

    currentState = STOP;

    //starts at 100000 us (reasonably average speed)
    currentSpeedIndex = 2;
}


// INPUT PROCESSING ROUTINE
/////////////////////////////////////////
void GetInput(void)
{
    if (MacUILib_hasChar()) 
    {
        input = MacUILib_getChar();   
    }
    else
    {  
        input = '\0';     
    }
}


// PROGRAM LOGIC ROUTINE
/////////////////////////////////////////
void RunLogic(void)
{
    if(input != 0)  // if not null character
    {
        switch(input)
        {                      
            case ' ':  // exit
                exitFlag = 1;
                break;

            case 'w':   //move up
                if (currentState == STOP || currentState == LEFT || currentState == RIGHT)
                {
                    currentState = UP;
                }
                break;

            case 's':   //move down
                if (currentState == STOP || currentState == LEFT || currentState == RIGHT)
                {
                    currentState = DOWN;
                }
                break;
            
            case 'a':   //move left
                if (currentState == STOP || currentState == UP || currentState == DOWN)
                {
                    currentState = LEFT;
                }
                break;
            
            case 'd':   //move right
                if (currentState == STOP || currentState == UP || currentState == DOWN)
                {
                    currentState = RIGHT;
                }
                break;
            
            case '+':   //increase game speed (by decreasing delay)
                if (currentSpeedIndex < SPEED_LEVELS_COUNT - 1)
                {
                    currentSpeedIndex++;
                }
                break;

            case '-':   //decrease game speed (by increasing delay)
                if (currentSpeedIndex > 0)
                {
                    currentSpeedIndex--;
                }
                break;

            default:
                break;
        }
        input = 0;
    }

    //update the player location depending on direction
    switch (currentState)
    {
        case UP:
            player.y--;
            if (player.y < 1)
            {
                player.y = MAX_ROWS - 2;    //wrap around feature (vertical)
            }
            break;
        
        case DOWN:
            player.y++;
            if (player.y >= MAX_ROWS - 1)
            {
                player.y = 1;   //wrap around feature (vertical)
            }
            break;

        case LEFT:
            player.x--;
            if (player.x < 1)
            {
                player.x = MAX_COLUMNS - 2;     //wrap around feature (horizontal)
            }
            break;

        case RIGHT:
            player.x++;
            if (player.x >= MAX_COLUMNS - 1)
            {
                player.x = 1;   //wrap around feature (horizontal)
            }
            break;

        default:
            break;
    }
}

// SCREEN DRAWING ROUTINE
/////////////////////////////////////////
void DrawScreen(void)
{
    MacUILib_clearScreen();

    //draw the board
    for (int y = 0; y < MAX_ROWS; y++)
    {
        for (int x = 0; x < MAX_COLUMNS; x++)
        {
            if (x == 0 || x == MAX_COLUMNS - 1 || y == 0 || y == MAX_ROWS - 1)
            {
                printf("%c", BOARDER_CHAR);
            }

            else if (x == player.x && y == player.y)
            {
                printf("%c", player.symbol);
            }

            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }

    //display the current speed level and instructions for how to change speed
    printf("Current Speed Level: %d (Delay: %d us)\n", currentSpeedIndex + 1, speedLevels[currentSpeedIndex]);
    printf("Use '+' to increase game speed (decrease delay) and use '-' to decrease game speed (increase delay).\n");
}

// PROGRAM LOOOP DELAYER ROUTINE
/////////////////////////////////////////
void LoopDelay(void)
{
    // Change the delaying constant to vary the movement speed.
    MacUILib_Delay(speedLevels[currentSpeedIndex]);    
}

// PROGRAM CLEANUP ROUTINE
/////////////////////////////////////////
// Recall from PPA1 - this is run only once at the end of the program
// for garbage collection and exit messages.
void CleanUp(void)
{
    MacUILib_uninit();
}