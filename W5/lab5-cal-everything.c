#include <stdlib.h>
#include <stdio.h>
#include <math.h>

float sum(int a, int b);
float diff(int a, int b);
float prod(int a, int b);
float divide(int a, int b);
float power(int a, int b);
float natLog(int a, int b);

int main(int argc, char const *argv[])
{
    float (*pFunction)(int, int);
    float (*func_array[6])(int, int) = {sum, diff, prod, divide, power, natLog};
    int a = atoi(argv[1]);
    int b = atoi(argv[2]);
    float result;

    for (int i = 0; i < 6; i++)
    {
        pFunction = *func_array[i];
        result = pFunction(a, b);
        printf("%.2f\n", result);
    }
    
    return 0;
}

float sum(int a, int b)
{
    return a+b;
}

float diff(int a, int b)
{
    return a-b;
}

float prod(int a, int b)
{
    return a*b;
}

float divide(int a, int b)
{
    return (float) a/b;
}

float power(int a, int b)
{
    return pow(a, b);
}

float natLog(int a, int b)
{
    return log(a) + log(b);
}
