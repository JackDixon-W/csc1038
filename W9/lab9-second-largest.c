/*
Author: Jack Dixon
Description: Grabs input from command line, runs all values through a check function.
Two largest variables are sorted into a new array in ascending order. 
Prints the first of these two variables (meaning the second largest variable).
Date: 07-11-2024
*/

// Included Libraries
#include <stdlib.h>
#include <stdio.h>

// Function Prototypes
float* grabInput(char *argv[], int length, int pos);
void checkLargest(float *largest, float val);
float findSecondLargest(float *largest, float *floatArray, int length);

// Main program
int main(int argc, char *argv[])
{
    float *floatArray = grabInput(argv, argc-1, 1);

    // This array contains the two largest elements in the array
    // In ascending order
    float largest[2];
    largest[0] = floatArray[0];
    largest[1] = floatArray[1];

    float answer = findSecondLargest(largest, floatArray, argc-1);
    printf("%.1f\n", answer);

    return 0;
}

// Build floatArray from command line input
float* grabInput(char *argv[], int length, int pos)
{
    float *floatArray = (float *)malloc(length * sizeof(float));
    for (int i = pos, j = 0; j < length; i++, j++)
    {
        floatArray[j] = atof(argv[i]);
    }
    return floatArray;
}

// Checks if val is 1st or 2nd largest
// Slots it into place if necessary
void checkLargest(float *largest, float val)
{
    if (val > largest[1])
    {
        largest[0] = largest[1];
        largest[1] = val;
    } else if (val > largest[0] && val != largest[1])
    {
        largest[0] = val;
    }
}

// Runs each value in floatArray through checkLargest to sort the 'largest' array
// When this array is finalised, it will return the second largest value of the array
float findSecondLargest(float *largest, float *floatArray, int length)
{
    for (int i = 0; i < length; i++)
    {
        checkLargest(largest, floatArray[i]);
    }

    return largest[0];
}
