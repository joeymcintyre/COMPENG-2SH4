#include <stdio.h>
#include "MacUILib.h"

//defines the string size for display and the max charcters the user can input
#define string_size 21
#define max_characters 16

char cmd;       
char display_text[string_size];
int starting_position = 0;
int input_length = 0;

int direction = 1;      //for the advanced feature (toggling the roling direction of the marquee display)

int exitFlag;
void Initialize(void);
void GetInput(void);
void RunLogic(void);
void DrawScreen(void);
void LoopDelay(void);
void CleanUp(void);


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

    return 0;
}


void Initialize(void)
{
    MacUILib_init();    //Initializes the McMaster UI library

    exitFlag = 0;   //Sets exit to false
    input_length = 0;   //Resewts the input length

    snprintf(display_text, string_size, ">><<                ");    //Initializes the text displayed

}


void GetInput(void)
{

    if (MacUILib_hasChar()) 
    {
        cmd = MacUILib_getChar();   //Gets a charcter input
    }
    else
    {  
        cmd = '\0';     //sets cmd to null if no charcter is inputed
    }
}


void RunLogic(void)
{
    if (cmd == '\e')     //sets exit to true if escape key is pressed
    {
        exitFlag = 1;
    }

    else if ((cmd >= 'a' && cmd <= 'z') || (cmd >= 'A' && cmd <= 'Z') || (cmd >= '0' && cmd <= '9'))    //makes sure the input is a number or letter
    {
        if (input_length < max_characters)      //stays below the character limit
        {
            int insert_index = 2 + input_length;    //inserts the typed character between >> and <<
            display_text[insert_index] = cmd;
            input_length++;

            display_text[0] = '>';
            display_text[1] = '>';
            display_text[2 + input_length] = '<';
            display_text[2 + input_length + 1] = '<';

            for (int i = 2 + input_length + 2; i < string_size - 1; i++)    //fills the remaining area with spaces
            {
                display_text[i] = ' ';
            }

            display_text[string_size - 1] = '\0';
        }
    }

    else if (cmd == '?')    //uses ? to change the direction
    {
        direction *= -1;
    }

    cmd = '\0';     //resets cmd
    
    if (direction == 1)
    {
        starting_position = (starting_position + 1) % (string_size - 1);    //scrolling effect (right)
    }
    else
    {
        starting_position = (starting_position - 1 + (string_size - 1)) % (string_size - 1);    //scrolling effect (left)
    }
}   


void DrawScreen(void)
{
    MacUILib_clearScreen();     //clears screen
    MacUILib_printf("McMaster Marquee Display\n");      //line 1 - title
    MacUILib_printf("====================\n");      //line 2 - formatting

    char c;     //line 3 - movint text
    for (int i = 0; i < string_size - 1; i++)                          
    {
        int index = (starting_position + i) % (string_size - 1);
        c = display_text[index];
        MacUILib_printf("%c", c);
    }
    MacUILib_printf("\n");

    MacUILib_printf("====================\n");      //line 4 - formatting
}


void LoopDelay(void)
{
    MacUILib_Delay(100000);     //delays time between iterations to make it controllable
}


void CleanUp(void)
{
    MacUILib_uninit();      //uninitializes the McMaster UI library
}