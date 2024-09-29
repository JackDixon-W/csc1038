#include <stdlib.h>
#include <stdio.h>

int findMax(int intArray[], int len);

int main(int argc, char const *argv[])
{
    int inpArray[argc - 1];
    for(int i = 1; i < argc; i++)
    {
        inpArray[i] = atoi(argv[i]);
    }
    int out = findMax(inpArray, argc-1);
    printf("%d\n", out);
    return 0;
}

int findMax(int intArray[], int len)
{
    int final = intArray[0];
    for(int i = 0; i <= len ; i++)
    {
        if (intArray[i] > final)
        {
            final = intArray[i];
        }
    }
    return final;
}