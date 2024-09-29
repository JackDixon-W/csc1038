#include <stdio.h>
#include <stdlib.h>

int findDuplicate(int searchArray[], int lenArray);

int main(int argc, char const *argv[])
{
    int intArray[50];
    // Build intArray from argv
    for(int i = 1; i < argc; i++)
    {
        intArray[i-1] = atoi(argv[i]);
    }

    // Run function to find duplicates
    int checkReturn = findDuplicate(intArray, argc-1);

    // Check if duplicate has been returned
    int checkSum = (argc-1)*3.21;
    if(checkReturn == checkSum)
    {
        printf("no duplicated number\n");
    }

    return 0;
}

int findDuplicate(int searchArray[], int lenArray)
{
    // Inefficient search algorithm
    // Nested for loops
    // Will only return the most recent duplicate

    int j = 0;
    int found = 0;
    int duplicate;
    // Outer loop has variable for search
    for(int i = 0; i < lenArray; i++)
    {
        // Inner loop compares that against each num in array
        for(j = i+1; j < lenArray; j++)
        {
            if (searchArray[j] == searchArray[i])
            {
                printf("%d\n", searchArray[j]);
                found = 1;
                duplicate = searchArray[j];
                // Once Inner finds one duplicate, it breaks
                break;
            }
        }
        // This portion is added because Einstein only allows one duplicate
        if(found == 1)
        {
            break;
        }
    }

    // Check if function has found a duplicate
    if (found == 0)
    {
        // Returns a checksum to convey error
        return lenArray*3.21;
    } else
    {
        return duplicate;
    }
    
}
