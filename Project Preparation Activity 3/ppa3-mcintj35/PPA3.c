#include <stdio.h>
#include "MacUILib.h"
#include "myStringLib.h"   // This is your first custom C library

#include <stdlib.h>
#include <time.h>

// [COPY AND PASTE FROM PPA2] Copy your additional preprocessor constants from PPA2 and paste them below
#define MAX_ROWS 10
#define MAX_COLUMNS 20
#define BOARDER_CHAR '#'
#define INITIAL_PLAYER_X 10
#define INITIAL_PLAYER_Y 5
#define PLAYER_SYMBOL '@'

// GLOBAL VARIABLES
const char* goalString = "McMaster-ECE";    //target string
char* mysteryString;    //partialy revealed string
struct objPos* itemBin;     
int moveCount;
// ================================

int exitFlag; // Program Exiting Flag

// [COPY AND PASTE FROM PPA2] Copy your additional global from PPA2 and paste them below
// For storing the user input - from PPA1
char input;

//objPos structure - represents position and symbol of objects on grid
struct objPos
{
    int x;
    int y;
    char symbol;
};

struct objPos player;

//Direction enumeration - defines enums for player movement directions
enum Direction
{
    STOP,
    UP,
    DOWN,
    LEFT,
    RIGHT,
};

enum Direction currentState;

// FUNCTION PROTOTYPES
// ================================
// Declare function prototypes here, so that we can organize the function implementation after the main function for code readability.

void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);

void GenerateItems(struct objPos list[], const int listSize, const struct objPos *playerPos, const int xRange, const int yRange, const char* str);

// MAIN PROGRAM
// ===============================
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
// ===============================
void Initialize(void)
{
    MacUILib_init();

    MacUILib_clearScreen();

    //Initializes the environment, player position and global var
    input = 0; // NULL 
   
    player.x = INITIAL_PLAYER_X;
    player.y = INITIAL_PLAYER_Y;
    player.symbol = PLAYER_SYMBOL;

    currentState = STOP;
    
    exitFlag = 0;  // 0 - do not exit, non-zero - exit the program
    moveCount = 0;
    
    //dynamically allocates memory for mysterystring
    mysteryString = (char*)malloc((my_strlen(goalString) + 1) * sizeof(char));

    if (mysteryString == NULL)
    {
        exitFlag = 1;
        return;
    }

    //initializes with ?
    for (int i = 0; i < my_strlen(goalString); i++)
    {
        mysteryString[i] = '?';
    }
    mysteryString[my_strlen(goalString)] = '\0';

    //dynamically allocates memory for itembin (5 objects)
    itemBin = (struct objPos*)malloc(5 * sizeof(struct objPos));

    if (itemBin == NULL)
    {
        free(mysteryString);
        exitFlag = 1;
        return;
    }

    //seeds the randome number generator with the current system time
    //ensures that each run produces different sequences of random nums
    srand(time(NULL));

    //generates initial grid items
    GenerateItems(itemBin, 5, &player, MAX_COLUMNS, MAX_ROWS, goalString);
}

// INPUT COLLECTION ROUTINE
// ===============================
void GetInput(void)
{
    // [COPY AND PASTE FROM PPA2] Copy your input collection routine from PPA2 and paste them below
    if (MacUILib_hasChar()) 
    {
        input = MacUILib_getChar();   
    }
    else
    {  
        input = '\0';     
    }
}

// MAIN LOGIC ROUTINE
// ===============================
void RunLogic(void)
{
    // [COPY AND PASTE FROM PPA2] Copy your main logic routine from PPA2 and paste them below
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
            moveCount++;
            break;
        
        case DOWN:
            player.y++;
            if (player.y >= MAX_ROWS - 1)
            {
                player.y = 1;   //wrap around feature (vertical)
            }
            moveCount++;
            break;

        case LEFT:
            player.x--;
            if (player.x < 1)
            {
                player.x = MAX_COLUMNS - 2;     //wrap around feature (horizontal)
            }
            moveCount++;
            break;

        case RIGHT:
            player.x++;
            if (player.x >= MAX_COLUMNS - 1)
            {
                player.x = 1;   //wrap around feature (horizontal)
            }
            moveCount++;
            break;

        default:
            break;
    }

    //object collision test
    for (int i = 0; i < 5; i++) 
    {
        if (player.x == itemBin[i].x && player.y == itemBin[i].y) 
        {
            //updates mystery string if collision matches a goal charcter
            char collidedSymbol = itemBin[i].symbol;
            for (int j = 0; j < my_strlen(goalString); j++) 
            {
                if (goalString[j] == collidedSymbol && mysteryString[j] == '?') 
                {
                    mysteryString[j] = collidedSymbol;
                }
            }

            //regenerates items
            GenerateItems(itemBin, 5, &player, MAX_COLUMNS, MAX_ROWS, goalString);
            break;
        }
    }

    // Check for game win condition
    if (my_strcmp(mysteryString, goalString) == 1) 
    {
        printf("You Win! The Mystery String matches the Goal String!\n");
        exitFlag = 1;
    }
}



// DRAW ROUTINE
// ===============================
void DrawScreen(void)
{ 
    // [COPY AND PASTE FROM PPA2] Copy your draw logic routine from PPA2 and paste them below
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
                int itemFound = 0;
                for (int i = 0; i < 5; i++)
                {
                    if (itemBin[i].x == x && itemBin[i].y == y)
                    {
                        printf("%c", itemBin[i].symbol);
                        itemFound = 1;
                        break;
                    }
                }
                if (!itemFound)
                {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }

    printf("Mystery String: %s\n", mysteryString);
    printf("Move Count %d\n", moveCount);

    if (my_strcmp(mysteryString, goalString) == 1) 
    {
        printf("\nYou Win! You found the mystery string!!\n");
    }
}



// DELAY ROUTINE
// ===============================
void LoopDelay(void)
{
    MacUILib_Delay(100000); // 0.1s delay
}

// TEAR-DOWN ROUTINE
// ===============================
void CleanUp(void)
{
    if (mysteryString != NULL)
    {
        free(mysteryString);
        mysteryString = NULL;
    }

    if (itemBin != NULL)
    {
        free(itemBin);
        itemBin = NULL;
    }

    MacUILib_uninit();
}

// The Item Generation Routine
////////////////////////////////////
void GenerateItems(struct objPos list[], const int listSize, const struct objPos *playerPos, const int xRange, const int yRange, const char* str)
{
    int goalStringLength = my_strlen(str);
    char usedChars[goalStringLength + 3]; 
    int usedCount = 0;

    //choose 2 random characters from the goalString
    for (int i = 0; i < 2; i++) 
    {
        char randomChar = str[rand() % goalStringLength];
        
        //ensure this character has not been used
        int isCharUsed = 0;
        for (int k = 0; k < usedCount; k++) 
        {
            if (usedChars[k] == randomChar) 
            {
                isCharUsed = 1;
                break;
            }
        }

        if (isCharUsed) 
        {
            i--;  //retry if used
        } 

        else 
        {
            usedChars[usedCount++] = randomChar;    //mark char as used
        }
    }

    //choose 3 characters excluding @, # and ' '
    for (int i = 0; i < 3; i++) 
    {
        char randomChar;
        int isValid = 0;

        //randomly generate characters until valid
        while (!isValid) 
        {
            randomChar = (char)(33 + rand() % (126 - 33 + 1)); 

            //chacks ig char is already used or restricted
            int isCharUsed = 0;
            for (int k = 0; k < usedCount; k++) 
            {
                if (usedChars[k] == randomChar) 
                {
                    isCharUsed = 1;  
                    break;
                }
            }

            if (randomChar == PLAYER_SYMBOL || randomChar == BOARDER_CHAR || randomChar == ' ' || isCharUsed) 
            {
                continue;   //retry if invalid
            }

            usedChars[usedCount++] = randomChar;
            isValid = 1;        //valid charcter found
        }
    }

    //place the 5 characters on  game board
    for (int i = 0; i < listSize; i++)
    {
        int x, y;
        int uniquePosition = 0;

        //finds unique position for the item
        while (!uniquePosition) 
        {
            x = 1 + rand() % (xRange - 2); 
            y = 1 + rand() % (yRange - 2);

            //check if it overlaps with any existing item or the player
            uniquePosition = 1;
            for (int j = 0; j < i; j++) {
                if (list[j].x == x && list[j].y == y || (playerPos->x == x && playerPos->y == y)) 
                {
                    uniquePosition = 0;
                    break;
                }
            }

            //assigns position if unique
            if (uniquePosition) 
            {
                list[i].x = x;
                list[i].y = y;
                list[i].symbol = usedChars[i];
            }
        }
    }
}
