/*
Author: Jack Dixon
Description: Takes input of command line arguments (argv). Argv[1] indicates whether to find
the smallest or largest of all the following argv.
Date: 31/10/2024
*/

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Function Prototypes
float findSmallest(float *floatArray, int length);
float findLargest(float *floatArray, int length);

int main(int argc, char *argv[])
{
    float (*pFunction)(float*, int);
    float nums[argc-2];

    // Convert argv into float array
    for (int i = 2; i < argc; i++)
    {
        nums[i-2] = atof(argv[i]);
    }
    
    if (!strcmp(argv[1], "largest"))
    {
        pFunction = findLargest;
    } else if (!strcmp(argv[1], "smallest"))
    {
        pFunction = findSmallest;
    } else
    {
        printf("ERROR -1\n");
        return -1;
    }
    
    printf("%.2f\n", pFunction(nums, argc-2));
    
    return 0;
}

float findSmallest(float *floatArray, int length)
{
    float smallest = floatArray[0];
    for (int i = 0; i < length; i++)
    {
        if (floatArray[i] < smallest)
        {
            smallest = floatArray[i];
        }
    }
    return smallest;   
}

float findLargest(float *floatArray, int length)
{
    float largest = floatArray[0];
    for (int i = 0; i < length; i++)
    {
        if (floatArray[i] > largest)
        {
            largest = floatArray[i];
        }
    }
    return largest;
}