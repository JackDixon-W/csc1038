#include <stdlib.h>
#include <stdio.h>

int leapRecorder(int start, int end, int *leapArray);
int leapChecker(int year);

int main(int argc, char const *argv[])
{
    // 110 is the max amount of leap years we could have to print
    int leapArray[110];
    int leapCount = leapRecorder(atoi(argv[1]), atoi(argv[2]), leapArray);

    // For loop prints years after function finishes
    for(int i = 0; i < leapCount; i ++)
    {
        printf("%d\n", leapArray[i]);
    }

    return 0;
}

// Returns value of leapCount
int leapRecorder(int start, int end, int *leapArray)
{
    // Initialises returning variable
    int leapCount = 0;

    for(int i = start; i <= end; i++)
    {
        // If this year is a leap year
        if(leapChecker(i) == 1)
        {
            leapArray[leapCount] = i;
            leapCount++;
        } 
    }

    return leapCount;
}

int leapChecker(int year)
{
    // Return 1 if year is leap year
    if(year % 4 == 0)
    {
        // This negates "century years" that are not divisible by 400
        if(year % 100 == 0 && year % 400 != 0)
        {
            return 0;
        } else
        {
            return 1;
        }
    }
    return 0;
}