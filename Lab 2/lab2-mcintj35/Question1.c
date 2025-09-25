#include <stdio.h>
#include <stdlib.h>

#include <math.h>
#include "Questions.h"



void add_vectors(double vector1[],double vector2[],double vector3[],int size)
{
    for (int i = 0; i < size; i++)
	{
		vector3[i] = vector1[i] + vector2[i];
	}
}

double scalar_prod(double vector1[],double vector2[],int size)
{
    double prod=0;

	for (int i = 0; i < size; i++)
	{
		prod += vector1[i] * vector2[i];
	}
	
    return prod;
}

double norm2(double vector1[], int size)
{
	double L2 = sqrt(scalar_prod(vector1, vector1, size));
	
    return L2;
}
