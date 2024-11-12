/*
Author: Jack Dixon
Description: Takes input of integer array from command line, and outputs the largest
value if it is at least twice the min value of the array.
Date: 11-11-2024
*/

// Included Libraries
#include <stdlib.h>
#include <stdio.h>

// Function Prototypes
int* grabInput(char *argv[], int length, int pos);
int findMin(int *intArray, int length);
int findMax(int *intArray, int length);

// Main program
int main(int argc, char *argv[])
{
    int *intArray = grabInput(argv, argc-1, 1);
    int min = findMin(intArray, argc-1);
    int max = findMax(intArray, argc-1);

    if (max >= (min * 2))
    {
        printf("%d\n", max);
    } else
    {
        printf("0\n");
    }

    free(intArray);

    return 0;
}

// Build intArray from command line input
int* grabInput(char *argv[], int length, int pos)
{
    int *intArray = (int *)malloc(length * sizeof(int));
    for (int i = pos, j = 0; j < length; i++, j++)
    {
        intArray[j] = atoi(argv[i]);
    }
    return intArray;
}

// An array of integers along with that array's length is passed in
// Function finds smallest value in the integer array and returns that value
int findMin(int *intArray, int length)
{
    int min = intArray[0];
    // Iterates through the array, comparing 'min' to each
    for (int i = 0; i < length; i++) {
        // If min is bigger than the current value in the array
        // Set this value as the new min
       if (min > intArray[i]) {
           min = intArray[i];
       }
    }
    return min;
}

// An array of integers along with that array's length is passed in
// Function finds largest value in the integer array and returns that value
int findMax(int *intArray, int length)
{
    int max = intArray[0];
    // Iterates through the array, comparing 'max' to each
    for (int i = 0; i < length; i++) {
        // If max is smaller than the current value in the array
        // Set this value as the new max
       if (max < intArray[i]) {
           max = intArray[i];
       }
    }
    return max;
}
