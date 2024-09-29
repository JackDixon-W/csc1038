#include <stdio.h>
#include <stdlib.h>
#include <string.h>

float multiply(float x, float y);
float divide(float x, float y);

int main(int argc, char *argv[])
{
    float result;
    char mult[] = "multiply";

    // Invalid check
    for(int i = 2; i < argc; i++)
    {
        if (atof(argv[i]) == 0)
        {
            printf("invalid\n");
            return 0;
        }
    }
    
    // Calculator
    if (strcmp(argv[1], mult) == 0)
    {
        result = multiply(atof(argv[2]), atof(argv[3]));
        printf("%f\n", result);
    } else
    {
        result = divide(atof(argv[2]), atof(argv[3]));
        printf("%f\n", result);
    }
}

float multiply(float x, float y)
{
    return x*y;
}

float divide(float x, float y)
{
    return x/y;
}