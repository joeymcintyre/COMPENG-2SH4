#include <stdio.h>
#include <stdlib.h>

#include "Questions.h"

void diag_scan(int mat [][N3], int arr [])
{
    int index = 0;

    for (int sum = 0; sum <= 2 * (N3-1); sum++)
    {
        for (int i = 0; i <= sum; i++)
        {
            int j = sum - i;

            if (i < N3 && j < N3)
            {
                arr[index++] = mat[i][j];
            }
        }
    }
}
