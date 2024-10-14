#include <stdio.h>
#include <stdlib.h>

/*Function prototypes*/
void get_matrix(int *pStart, int *m, int *n, char *argv[], int *pMatrix_a);
void multiply_matrices(int *pm1, int *pn1, int *pm2, int *pn2, int *matrix_a, int *matrix_b, int *matrix_ab);
void print_matrix(int *pm1, int *pn2, int *matrix_ab);

/*Main driver function*/
int main(int argc, char *argv[])
{
    int m1 = atoi(argv[1]);
    int *pm1 = &m1;
    int n1 = atoi(argv[2]);
    int *pn1 = &n1;

    int m2 = atoi(argv[3 + m1 * n1]);
    int *pm2 = &m2;
    int n2 = atoi(argv[4 + m1 * n1]);
    int *pn2 = &n2;

    int matrix_a[m1 * n1];
    int *pMatrix_a = matrix_a;

    int matrix_b[m2 * n2];
    int *pMatrix_b = matrix_b;

    int matrix_ab[n1 * m2];
    int *pMatrix_ab = matrix_ab;

    int start = 3;
    int *pStart = &start;

    get_matrix(pStart, pm1, pn1, argv, pMatrix_a);

    start = start + ((*pm1) * (*pn1)) + 2;

    get_matrix(pStart, pm2, pn2, argv, pMatrix_b);

    multiply_matrices(pm1, pn1, pm2, pn2, pMatrix_a, pMatrix_b, pMatrix_ab);

    print_matrix(pm1, pn2, matrix_ab);

    return 0;
}

/*Function grabs matrix from command line*/
void get_matrix(int *pStart, int *m, int *n, char *argv[], int *pMatrix_a)
{
    for (int i = 0; i < (*m) * (*n); ++i)
    {
        *(pMatrix_a + i) = atoi(argv[*pStart + i]);
    }
}

/*Function multiplies two matrices together*/
void multiply_matrices(int *pm1, int *pn1, int *pm2, int *pn2, int *matrix_a, int *matrix_b, int *matrix_ab)
{
    int sum = 0;
    int index = 0;
    for (int i = 0; i < *pm1; ++i)
    {
        for (int j = 0; j < *pn2; ++j)
        {
            sum = 0;

            for (int k = 0; k < *pn1; ++k)
            {
                sum += matrix_a[k + (i * *pm1)] * matrix_b[(k * *pn2) + j];
            }
            *(matrix_ab + index) = sum;
            ++index;
        }
    }
}

/*Function prints the new matrix*/
void print_matrix(int *pm1, int *pn2, int *matrix_ab)
{
    for (int i = 0; i < *pm1 * *pn2; ++i)
    {
        if ((i + 1) % *pn2 == 0)
        {
            printf("%d\n", *(matrix_ab + i));
        }
        else
        {
            printf("%d ", *(matrix_ab + i));
        }
    }
}