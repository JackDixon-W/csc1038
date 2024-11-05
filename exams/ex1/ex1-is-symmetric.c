/*
Author: Jack Dixon
Description: Takes an input string as a command line argument and outputs "yes" or "no"
depending on if the string is symmetrical or not.
Date: 31/10/2024
*/

#include <string.h>
#include <stdlib.h>
#include <stdio.h>

// Function Prototypes
int checkSymmetry(char *word, int length);
int evenCheck(int num);

int main(int argc, char *argv[])
{
    int length = strlen(argv[1]);

    int tmp = checkSymmetry(argv[1], length);
    if (tmp == 1)
    {
        printf("yes\n");
    } else
    {
        printf("no\n");
    }
    
    
    return 0;
}

// This will only work if the length is odd
int checkSymmetry(char *word, int length)
{
    int symCheck = 1;
    //printf("%d\n", length);
    int isOdd = evenCheck(length);
    for (int i = (length / 2) - isOdd, j = length / 2; i > 0, j < length; i--, j++)
    {
        //printf("%d = %c\t%d = %c\n", i, word[i], j, word[j]);
        if ((int)word[i] != (int)word[j])
        {
            symCheck = 0;
            break;
        }
    }
    return symCheck;
}

int evenCheck(int num)
{
    if(num % 2 == 0)
    {
        return 1;
    } else
    {
        return 0;
    }
    
}