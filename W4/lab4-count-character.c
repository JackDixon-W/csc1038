#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char search_char = argv[1][0];
    char *pString = argv[2];
    int count = 0;

    while (pString = strchr(pString, search_char))
    {
        count++;
        pString++; 
    }
    printf("%d\n", count);
    
    return 0;
}
