#include <stdio.h>
#include <stdlib.h>
#include "Questions.h"

void efficient(const int source[], struct Q3Struct effVector[], int size)
{
    int k = 0;
    
    for (int i = 0; i < size; i++)
    {
        if (source[i] != 0)
        {
            effVector[k].val = source[i];
            effVector[k].pos = i;
            k++;
        }
    }
}

void reconstruct(int source[], int m, const struct Q3Struct effVector[], int n)
{
    for (int i = 0; i < m; i++)
    {
        source[i] = 0;
    }

    for (int j = 0; j < n; j++)
    {
        source[effVector[j].pos] = effVector[j].val;
    }
}
