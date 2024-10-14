#include <stdlib.h>
#include <stdio.h>

void swap(int *a, int *b);

int main(int argc, char const *argv[])
{
    int a[] = {1, 2, 3, 4, 5};
    int *pA = NULL;
    int *pB = 0;
    for(int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            pA = &a[i];
            pB = &a[j];
            swap(pA, pB);
        }
    }
    for (int i = 0; i < 5; i++)
    {
        printf("%d\n", a[i]);
    }
    
    return 0;
}

void swap(int *a, int *b){
    int temp;
    temp = *a;
    *a = *b;
    *b = temp;
}