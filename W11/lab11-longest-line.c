/*
Author: Jack Dixon
Description: Parses a file of sentences separated by newline characters.
Finds the sentence with the longest length, outputs the length of the sentence
as well as the sentence itself.
Date: 21-11-24
*/

// Included Libraries
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Function Prototypes
char *parseLines(char *filename);

// Main program
int main(int argc, char *argv[])
{
    char *filename = "paragraph.txt";
    char *strLongest = parseLines(filename);
    int lenLongest = strlen(strLongest);
    printf("%d\n%s\n", lenLongest, strLongest);
    return 0;
}

char *parseLines(char *filename)
{
    // Declare file pointer and read file
    FILE *pFile = NULL;
    pFile = fopen(filename, "r");

    // Check if file read was successful
    if (!pFile)
    {
        printf("Error opening %s\tProgram terminating\n", filename);
        exit(-1);
    }

    // Declare temp variables for testing as we run through the file
    char tmp[200];
    int lenLongest = 0;
    // At this point, the str is of length 1 since we run realloc before assigning anything
    char *strLongest = (char *)calloc(1, sizeof(char));
    // Loop runs until fgets returns NULL (reaches EOF)
    while (fgets(tmp, sizeof(tmp), pFile))
    {
        // If the current line is longer than prior stored
        if (strlen(tmp) > lenLongest)
        {
            // Save its length
            lenLongest = strlen(tmp);
            // Reallocate memory for storing the string and store it
            strLongest = realloc(strLongest, lenLongest * sizeof(char));
            strcpy(strLongest, tmp);
        }
    }
    return strLongest;
}

