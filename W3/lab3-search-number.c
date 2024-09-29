#include <stdlib.h>
#include <stdio.h>

void searchIntArray(int searchNum, int intArray[], int lenArray);

int main(int argc, char const *argv[])
{
    int searchNum = atoi(argv[1]);
    int inputs[50];

    // Build argv values into an int Array
    for(int i = 2; i < argc; i++)
    {
        inputs[i-2] = atoi(argv[i]);
    }

    searchIntArray(searchNum, inputs, argc-2);

    return 0;
}

void searchIntArray(int searchNum, int intArray[], int lenArray)
{
    int found = 0;
    for(int i = 0;i < lenArray;i++)
    {
        if (searchNum == intArray[i])
        {
            printf("Found %d at %d\n", searchNum, i);
            found = 1;
        }
    }
    // Check if value was found
    if (found == 0)
    {
        printf("%d not found\n", searchNum);
    }
}