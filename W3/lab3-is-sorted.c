#include <stdlib.h>
#include <stdio.h>

int BubbleSort(int *intArray, int lenArray);

int main(int argc, char const *argv[])
{
    int intArray[50];
    // Build intArray from argv
    for(int i = 1; i < argc; i++)
    {
        intArray[i-1] = atoi(argv[i]);
    }

    // Run Function to sort
    int returnVal = BubbleSort(intArray, argc-1);

    // Print new intArray
    for(int i = 0; i < argc-1; i++)
    {
        printf("%d\n", intArray[i]);
    }
    return 0;
}

int BubbleSort(int *intArray, int lenArray)
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
