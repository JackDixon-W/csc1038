#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    // Variable declaration
    char *pHay = argv[1];
    char *pNeedle = argv[2];
    char *pStart;
    char *pEnd;

    // Sets pointer to start of word
    pStart = strstr(pHay, pNeedle);
    // Adds length of word
    pEnd = pStart + strlen(pNeedle) - 1;

    // Subtract start of word to find relative positions as int
    int iStart = pStart - pHay;
    int iEnd = pEnd - pHay;

    printf("%d %d\n", iStart, iEnd);
    return 0;
}
