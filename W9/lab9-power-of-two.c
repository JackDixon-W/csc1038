/*
Author: Jack Dixon
Description: Takes input as a single argument. Prints Yes if this value is a power of two.
Prints No otherwise.
Date: 12-11-2024
*/

// Included Libraries
#include <stdlib.h>
#include <stdio.h>

// Function Prototypes
int powTwoCheck(int val);

// Main program
int main(int argc, char *argv[])
{
    if (powTwoCheck(atoi(argv[1])))
    {
        printf("Yes\n");
    } else
    {
        printf("No\n");
    }
    
    return 0;
}

// Returns 1 if val is a power of two
int powTwoCheck(int val)
{
    // Only powers of two have a 1 in a single bit
    // Eg. 16 = (10000), 15 = (01111)
    // Performing this & operation will return a value of only 0s if the value is a power of two
    // This is because no two bits will match
    if (val & (val - 1))
    {
        return 0;
    } else
    {
        // If this operation returns all 0s, the if expression is false
        return 1;
    }
}
