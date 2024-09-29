#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void findLongest(char* strArray, char lenArray, char* longestWord);

int main(int argc, char const *argv[])
{
    // Variable initialisation
    char longestWord[50];
    char strArray[50];
    char cur = 'd';
    int i = 0;
    
    // Builds strArray array from argv input
    while(cur != '\0')
    {
        cur = argv[1][i];
        strArray[i] = argv[1][i];
        i++;
    }

    // Pass string into function
    findLongest(strArray, i+1, longestWord);
    
    // Print longestWord as string
    printf("%s\n", longestWord);

    return 0;
}

// Doesn't need to return anything
void findLongest(char* strArray, char lenArray, char* longestWord)
{
    int i = 0, j = 0;
    char tmp[lenArray];
    // Run until lenArray is reached
    while(i < lenArray)
    {
        // Pass through each character checking for grammar/whitespace
        if(strArray[i] >= 'A' && strArray[i] <= 'Z' || strArray[i] >= 'a' && strArray[i] <= 'z')
        {
            // Between each character, store the current word in a temp array and count length
            tmp[j] = strArray[i];
            // This prevents past iterations from affecting this iteration
            tmp[j+1] = '\0';

            j++;
            
        } else
        {
            // When whitespace/grammar is reached, compare this word
            // Against the current longest word (only in length)
            // If longer, store this in the longestWord array
            if(strlen(longestWord) < j+1)
            {
                strcpy(longestWord, tmp);
            }
            j = 0;
        }
        
        i++;
    }
}
