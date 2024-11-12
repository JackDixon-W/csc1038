/*
Author: Jack Dixon
Description: Takes input of a length and then two identical length vectors.
Argv is converted into two integer arrays before the dot product is found and printed.
Date: 07-11-2024
*/

// Included Libraries
#include <stdlib.h>
#include <stdio.h>

// Function Prototypes
int* grabInput(char *argv[], int length, int pos);
int dotProduct(int *vector1, int *vector2, int length);

// Main program
int main(int argc, char *argv[])
{
    int vectorLength = atoi(argv[1]);
    int *vector1 = grabInput(argv, vectorLength, 2);
    int *vector2 = grabInput(argv, vectorLength, 2 + vectorLength);
    int prod = dotProduct(vector1, vector2, vectorLength);

    printf("%d\n", prod);

    free(vector1);
    free(vector2);
    
    return 0;
}

// Build intArray from command line input
// Returns pointer to intArray
int* grabInput(char *argv[], int length, int pos)
{
    int *intArray = (int *)malloc(length * sizeof(int));
    for (int i = pos, j = 0; j < length; i++, j++)
    {
        intArray[j] = atoi(argv[i]);
    }
    return intArray;
}

// Takes two vector arrays of identical length and outputs the dot product
int dotProduct(int *vector1, int *vector2, int length)
{
    int prod = 0;
    for (int i = 0; i < length; i++)
    {
        prod += vector1[i]*vector2[i];
    }
    return prod;
}

