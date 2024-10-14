#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int asciiConvert(char curChar);

int main(int argc, char *argv[])
{
    // Variable declaration
    char curChar;
    int freq[26];
    int *pMax = freq;
    int ascii;
    //char *pString = argv[1];
    char tmp[20] = "dgefjdl";
    char *pString = tmp;
    // Find length of argv
    int strLen = strlen(pString);

    /*
    Create array the size of the alphabet
    Store each letter's frequency in this array by finding ASCII and subtracting
    Whenever a letter is checked, compare its frequency against highest
    Set highest if freq is more than highest (there is only one highest)
    */

    for(int i = 0; i < strLen;i++)
    {
        curChar = *pString;
        ascii = asciiConvert(curChar);
        freq[ascii]++;
        if (ascii != 0 && freq[ascii] > *pMax)
        {
            pMax = freq;
            pMax = pMax + ascii;
        }
        // At end of loop, pString is iterated up by 1
        pString++;
    }
    printf("%c\n", *pMax + 96);
    
    return 0;
}

// Converts letters into their order in the alphabet
// Any other character is returned as 0
int asciiConvert(char curChar)
{
    int asciiVal = (int)curChar;
    if (asciiVal >= 97 && asciiVal <= 122)
    {
        return asciiVal-96;
    } else if (asciiVal >= 65 && asciiVal <= 90)
    {
        return asciiVal-64;
    } else
    {
        return 0;
    }
}