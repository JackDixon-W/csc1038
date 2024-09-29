#include <stdio.h>
#include <stdlib.h>

int main(int argc, char*argv[])
{
    int size = atoi(argv[1]);

    for (int i = 0; i < size; i++)
    {
        printf("*");
    }
    printf("\n");
    
    for (int i = 0; i < (size - 2); i++)
    {
        printf("*");
        for (int j = 0; j < (size - 2); j++) {
            printf(" ");
        }
        printf("*\n");
    }

    for (int i = 0; i < size; i++)
    {
        printf("*");
    }
    printf("\n");
    

    return 0;
}

