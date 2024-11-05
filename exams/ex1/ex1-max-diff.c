/*
Author: Jack Dixon
Description: Takes input of integers through command line arguments.
The difference between the largest and smallest value in the array is found and output to STDOUT.
Date: 31/10/2024
*/

// Included Libraries
#include <stdlib.h>
#include <stdio.h>

// Function Prototypes
int findMax(int *intArray, int length);
int findMin(int *intArray, int length);
int findDiff(int a, int b);

int main(int argc, char *argv[])
{
    // Integer array is declared with length to fit all argv values
    int intArray[argc-1];

    // Convert values from argv to an array of integers
    // This makes later handling easier
    for (int i = 1; i < argc; i++) {
        intArray[i-1] = atoi(argv[i]);
    }
    
    // Variable for output is stored temporarily
    // findDiff has the max and min value of the integer array passed into it, and returns the absolute difference
    int output = findDiff(findMax(intArray, argc-1), findMin(intArray, argc-1));
    
    printf("%d\n", output);
    return 0;
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

// Returns the absolute difference between two values
int findDiff(int a, int b)
{
    // Checks which is larger before subtracting
    // This ensures a positive value is always returned
    if (a > b) {
        return a - b;
    } else {
        return b - a;
    }
}