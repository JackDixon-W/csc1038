#include <stdio.h>
#include <stdlib.h>

int buildMatrix(int *matrix, int size, int argvCur, char *argv[]);

//int main(int argc, char *argv[])
int main()
{
    char *argv[] = {
    "./lab4-multiple-matrix", "3", "3", "1", "2", "3", "6", "5", "4", "8", "7", "9", 
    "3", "2", "1", "2", "9", "8", "6", "7", NULL
    };
    int m1Rows = atoi(argv[1]);
    int m1Columns = atoi(argv[2]);
    int m1Size = m1Rows*m1Columns;
    int m1Array[m1Rows][m1Columns];

    // Builds m1Array
    // Saves index for m2 start
    int m2Start = buildMatrix(m1Array, m1Size, 3, argv);

    int m2Rows = atoi(argv[m2Start]);
    int m2Columns = atoi(argv[m2Start + 1]);
    int m2Size = m2Rows*m2Columns;
    int m2Array[m2Rows][m2Columns];
    buildMatrix(m2Array, m2Size, m2Start+2, argv);

    return 0;
}

// Builds matrix onto pointer *matrix using information provided
// Returns the index of the argument after the last one used
int buildMatrix(int *matrix, int size, int argvCur, char *argv[])
{
    /*
    Note: If you want to access an array like it's multidimensional,
    It has to be declared as multidimensional
    Once it's been declared in this way, tomfoolery is free to occur
    But an array can't pretend to have more dimensions than it does
    */


    int max = size + argvCur;
    for(int i = 0;argvCur < max; argvCur++, i++)
    {
        matrix[i] = atoi(argv[argvCur]);
    }
    return argvCur;
}


