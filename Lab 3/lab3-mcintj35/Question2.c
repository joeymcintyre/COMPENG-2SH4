#include <stdio.h>
#include <stdlib.h>
#include "Questions.h"


char **read_words(const char *input_filename, int *nPtr)
{       
    FILE *file = fopen(input_filename, "r");
    if (file == NULL) 
    {
        return NULL;
    }
    
    fscanf(file, "%d\n", nPtr);
    int word_count = *nPtr;

    char **word_list = (char **)malloc(word_count * sizeof(char *));

    if (word_list == NULL)
    {
        fclose(file);
        return NULL;
    }

    for (int i = 0; i < word_count; i++)
    {
        word_list[i] = (char *)malloc(50 * sizeof(char));

        if (word_list[i] == NULL) 
        {
            fclose(file);
            return NULL; 
        }

        if (fgets(word_list[i], 50, file) != NULL)
        {
            for (int j = 0; word_list[i][j] != '\0'; j++)
            {
                if (word_list[i][j] == '\n')
                {
                    word_list[i][j] = '\0';
                    break;
                }
            }
        }
    }

    fclose(file);
    return word_list;
}

void swap(char **str1, char **str2)
{    
    char *temp = *str1;
    *str1 = *str2;
    *str2 = temp;
}

void delete_wordlist(char **word_list, int size)
{
    if (word_list == NULL) return;

    for (int i = 0; i < size; i++)
    {
        free(word_list[i]);
    }

    free(word_list);
}

void sort_words_Bubble(char **words, int size)
{   
    if (words == NULL)
    {
        return;
    }

    int swapped;

    for (int i = 0; i < size - 1; i++)
    {
        swapped = 0;

        for (int j = 0; j < size - i - 1; j++)
        {
            if (my_strcmpOrder(words[j], words[j + 1]) == 1)
            {
                swap(&words[j], &words[j + 1]);
                swapped = 1;
            };
        }

        if (!swapped)
        {
        break;
        }
    }
}



void sort_words_Selection(char **words, int size)
{    
    int i, j;    
    int min, minIndex;
    
    for(i = 0; i < size; i++)
    {
        minIndex = i;

        for(j = i + 1; j < size; j++)
        {
            if(my_strcmpOrder(words[minIndex], words[j]) == 1)
            {
                minIndex = j;
            }                        
        }
       
        if(minIndex != j)
        {
            swap(&words[i], &words[minIndex]);
        }
    }
}