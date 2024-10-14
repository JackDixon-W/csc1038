#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    // Build array of required length
    int sizeMatrix = atoi(argv[1]);
    int matrix[sizeMatrix][sizeMatrix];

    int indexArg = 2;
    for(int i = 0; i < sizeMatrix; i++)
    {
        for(int j = 0; j < sizeMatrix; j++, indexArg++)
        {
            matrix[i][j] = atoi(argv[indexArg]);
            // printf("At i=%d, j=%d, matrix=%d\n", i, j, matrix[i][j]);
        } 
    }

    int *pMatrix = matrix[0];
    int total = 0;
    // While pMatrix is inside the array
    while(pMatrix < matrix[0] + (sizeMatrix*sizeMatrix))
    {
        total = total + *pMatrix;

        pMatrix = pMatrix + (sizeMatrix+1);
    }
    printf("%d\n", total);

    return 0;
}
