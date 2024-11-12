/*
Author: Jack Dixon
Description: Takes an input of an array of strings, finds the length of the longest string.
Then finds all strings of that length and prints them in a separate array.
Date: 11-11-2024
*/

// Included Libraries
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Function Prototypes
char **grabStringArray(char *argv[], int startPos, int endPos);
int findLargestStringLength(char **stringArray, int length);
char **findEquilengthStr(char **stringArray, int arrayLength, int wordLength);
void printAllStrings(char **strArray, int length);

// Main program
int main(int argc, char *argv[])
{
    char **strArray = grabStringArray(argv, 1, argc-1);
    int longestLen = findLargestStringLength(strArray, argc-1);
    char **longStrArray = findEquilengthStr(strArray, argc-1, longestLen);
    printAllStrings(longStrArray, argc-1);

    free(strArray);
    free(longStrArray);

    return 0;
}

// Grabs array of strings from argv input
// Returns a pointer to an array of pointers to strings
char **grabStringArray(char *argv[], int startPos, int endPos)
{
    // +1 is needed to mark end of array
    char **stringArray = (char **)malloc((endPos - startPos + 1) * sizeof(char *));
    
    for (int i = startPos, j = 0; i <= endPos; i++, j++)
    {
        stringArray[j] = (char *)malloc(strlen(argv[i]) + 1);
        strcpy(stringArray[j], argv[i]);
    }
    return stringArray;
}

// Returns the length of the largest string
int findLargestStringLength(char **stringArray, int length)
{
    int largestLength = strlen(stringArray[0]);
    int temp;
    for (int i = 0; i < length; i++)
    {
        temp = strlen(stringArray[i]);
        if (temp > largestLength)
        {
            largestLength = temp;
        }
    }
    
    return largestLength;
}

// Returns a pointer to an array of pointers to strings
// These strings are all of length wordLength
char **findEquilengthStr(char **stringArray, int arrayLength, int wordLength)
{
    char **equilStrArray = (char **)calloc(arrayLength, sizeof(char *));

    for (int i = 0, j = 0; i < arrayLength; i++)
    {
        if (strlen(stringArray[i]) == wordLength)
        {
            // Memory must be allocated for equilStrArray[j]
            // Prior to this, it points to nothing and causes a Seg Fault
            equilStrArray[j] = (char *)malloc(strlen(stringArray[i]) + 1);
            strcpy(equilStrArray[j], stringArray[i]);
            j++;
            equilStrArray[j] = NULL;
        }
    }
    return equilStrArray;
}

// Prints all strings in strArray
void printAllStrings(char **strArray, int length)
{
    for (int i = 0; strArray[i] != NULL; i++)
    {   
        printf("%s\n", strArray[i]);
    }
}