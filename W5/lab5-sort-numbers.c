#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Function Declarations */
void ascSort(int *intArray, int lenArray);
void descSort(int *intArray, int lenArray);

int main(int argc, char *argv[])
{
    int length = atoi(argv[1]);
    char *sortOrder = argv[argc-1];
    int nums[length];
    void (*pFunction)(int *, int);
    
    // Build array of nums to be sorted
    for(int i = 2;i < argc;i++)
    {
        nums[i-2] = atoi(argv[i]);
    }

    // For some reason, after the above loop, the first parameter is appended to
    // the end of nums[].

    if(!strcmp(sortOrder, "desc"))
    {
        pFunction = descSort;
    } else if(!strcmp(sortOrder, "asc"))
    {
        pFunction = ascSort;
    } else
    {
        printf("INVALID ORDER INPUT\n");
        return -1;
    }

    // Sort Numbers
    pFunction(nums, length);

    // Loop to print sorted numbers
    printf("Sorted numbers:");
    for (int i = 0; i < length; i++)
    {
        printf(" %d", nums[i]);
    }
    printf("\n");
    
    return 0;
}

// This uses bubble sort to sort ascending
void ascSort(int *intArray, int lenArray)
{
    int sorted = 0;
    int tmp;
    // While the array is unsorted
    while(sorted == 0)
    {
        // At beginning, set sorted to 1.
        // This ensures only the most recent sort is being checked
        sorted = 1;
        // For loop, iterating on i and j at the same time
        for(int i = 1; i < lenArray; i++)
        {
            // Check if the element behind the current is lower than the current
            // If yes, swap and set sorted to 0. If no, do nothing.
            if(intArray[i] < intArray[i-1])
            {
                tmp = intArray[i];
                intArray[i] = intArray[i-1];
                intArray[i-1] = tmp;
                sorted = 0;
            }
        }
    }
}

// This uses Bubble sort to sort descending
void descSort(int *intArray, int lenArray)
{
    int sorted = 0;
    int tmp;
    // While the array is unsorted
    while(sorted == 0)
    {
        // At beginning, set sorted to 1.
        // This ensures only the most recent sort is being checked
        sorted = 1;
        // For loop, iterating on i and j at the same time
        for(int i = lenArray-1; i > 0; i--)
        {
            // Check if the element behind the current is lower than the current
            // If yes, swap and set sorted to 0. If no, do nothing.
            if(intArray[i] < intArray[i+1])
            {
                tmp = intArray[i];
                intArray[i] = intArray[i+1];
                intArray[i+1] = tmp;
                sorted = 0;
            }
        }
    }
}
