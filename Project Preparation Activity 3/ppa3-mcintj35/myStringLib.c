#include <stdio.h>
#include <stdlib.h>

#include "myStringLib.h"

// [COPY AND PASTE] Copy and Paste your Lab 3 Q1 Solution Below
int my_strlen(const char * const str1)
{
	int length = 0;
	while (str1[length] != '\0')
	{
		length++;
	}
	return length;
}

int my_strcmp(const char * const str1, const char * const str2)
{
	int i = 0;
	while (str1[i] != '\0' && str2[i] != '\0')
	{
		if (str1[i] != str2[i])
		{
			return 0;
		}
		i++;
	}
	return (str1[i] == '\0' && str2[i] == '\0')? 1:0;
}


int my_strcmpOrder(const char * const str1, const char * const str2)
{
	int i = 0;
	while (str1[i] != '\0' && str2[i] != '\0')
	{
		if (str1[i] < str2[i])
		{
			return 0;
		}

		else if (str1[i] > str2[i])
		{
			return 1;
		}
		i++;
	}
	if (str1[i] == '\0' && str2[i] != '\0') 
	{
		return 0;
	}

    if (str1[i] != '\0' && str2[i] == '\0') 
	{
		return 1;
	}
	return -1;
}


char *my_strcat(const char * const str1, const char * const str2)\
{
	int len1 = my_strlen(str1);
	int len2 = my_strlen(str2);
	char *z = (char *)malloc((len1 + len2 + 1) * sizeof(char));

	if (z == NULL)
	{
		return NULL;
	}

	for (int i = 0; i < len1; i++)
	{
		z[i] = str1[i];
	}

	for (int j = 0; j < len2; j++)
	{
		z[len1+j] = str2[j];
	}

	z[len1 + len2] = '\0';

	return z;
}
//  This is then your very first reusable custom C library 