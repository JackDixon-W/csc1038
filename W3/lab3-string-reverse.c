#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void reverse(char* oWord);

int main(int argc, char const *argv[])
{
    char oWord[50];
    char cur = 'd';
    int i = 0;
    
    // Builds oWord array from argv input
    while(cur != '\0')
    {
        cur = argv[1][i];
        oWord[i] = argv[1][i];
        i++;
    }

    reverse(oWord);
    printf("%s\n", oWord);
    
    return 0;
}

void reverse(char* oWord)
{
    int first = 0;
    int second = strlen(oWord) - 1;
    char temp;

    while (first < second)
    {
        temp = oWord[first];
        oWord[first] = oWord[second];
        oWord[second] = temp;
        first++;
        second--;
    }
}
