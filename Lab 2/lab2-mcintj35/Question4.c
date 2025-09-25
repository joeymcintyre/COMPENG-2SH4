#include <stdio.h>
#include <stdlib.h>
#include "Questions.h"


void sortDatabyBubble(struct Q4Struct array[], int size)
{
    struct Q4Struct temp;
    temp.intData = 0;
    temp.charData = 0;

    int i;
    int curr, next;
    int done = 0;

    while(!done)
    {
        done = 1;
               
        for(i = 0; i < size - 1; i++)        
        { 
            curr = array[i].intData;
            next = array[i + 1].intData;

            if(curr > next)
            {
                temp.intData = array[i].intData;
                temp.charData = array[i].charData;

                array[i].intData = array[i + 1].intData;
                array[i].charData = array[i + 1].charData;

                array[i + 1].intData = temp.intData;
                array[i + 1].charData = temp.charData;

                done = 0;
            }
        }
    }    
}


void sortDatabySelection(struct Q4Struct array[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        int min_index = i;
        for (int j = i + 1; j < size; j++)
        {
            if (array[j].intData < array[min_index].intData)
            {
                min_index = j;
            }
        }
        if (min_index != i)
        {
            struct Q4Struct temp = array[i];
            array[i] = array[min_index];
            array[min_index] = temp;
        }
    }
}