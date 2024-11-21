/*
Author: Jack Dixon
Description: Accepts input of up to 8 binary digits (1 or 0) as command line arguments.
Converts this into decimal representation.
Date: 21-11-24
*/

// Included Libraries
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Function Prototypes
int* grabInput(char *argv[], int length, int pos);
int bintoDec(int *binArray, int length);
int myPow(int base, int exponent);

// Main program
int main(int argc, char *argv[])
{
    // If number of inputs exceeds the max (8), quit program
    if (argc >= 10)
    {
        printf("Too many binary digits entered.\n");
        exit(0);
    }
    
    int *binArray = grabInput(argv, argc-1, 1);
    int dec = bintoDec(binArray, argc-1);
    printf("%d\n", dec);

    return 0;
}

// Build intArray from command line input
// Returns pointer to intArray
int* grabInput(char *argv[], int length, int pos)
{
    int *intArray = (int *)malloc(length * sizeof(int));
    for (int i = pos, j = 0; j < length; i++, j++)
    {
        // Really botched way of checking that all characters are 1 or 0
        if (!strcmp("0", argv[i]) || !strcmp("1", argv[i]))
        {
            intArray[j] = atoi(argv[i]);
        } else
        {
            printf("Only digits 1 and 0 are permitted.\n");
            exit(0);
        }
    }
    return intArray;
}

// Converts an integer array of 1 or 0 values into its decimal representation
int bintoDec(int *binArray, int length)
{
    int dec = 0;
    // Loop through binArray, increasing i and reducing j
    // i = position in array
    // j = exponent to multiply this binary value by
    for (int i = 0, j = length-1; i < length; i++, j--)
    {
        if (binArray[i])
        {
            dec += myPow(2, j);
        }
    }
    
    return dec;
}

// Finds the result of multiplying a base by itself exponent number of times
int myPow(int base, int exponent)
{
    // 1 is basecase to ensure the output is not continuously 0
    // Also allows it to return 1 if the exponent is set to 0
    int total = 1;
    // Loop for exponent number of times
    for (int i = 0; i < exponent; i++)
    {
        // Multiply total by the base
        total = total * base;
    }
    
    return total;
}
