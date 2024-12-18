/*
Author: Jack Dixon
Description: Accepts input through command line arguments. 
Argv[1] = Number of Rows, Argv[2] = Number of Columns, Argv[3] = Number of values to insert
Argv[4] and onwards are triplets of <value> <row> <column>.
Builds blank matrix in the form of a linked list, then inserts values into corresponding positions.
Prints matrix with characters inserted.
Then finds sum of the diagonal of the matrix, and prints this with formatting.
Date: 28-11-24
*/

// NOTE: THIS CODE PASSED ALL BUT THE LAST TEST CASE
// LAST TEST CASE CAUSES SEGMENTATION FAULT

// Included Libraries
#include <stdlib.h>
#include <stdio.h>

// Type Declarations
typedef struct Node Node;

// Structure Declarations
struct Node {
    int val;
    int rowIndex, columnIndex;
    Node *prev, *next;
};

// Function Prototypes
Node *buildMatrix(int rows, int columns);
int *grabInput(char *argv[], int length, int pos);
void prepValues(Node *matrix, int *intArray, int length);
void insertValue(Node *matrix, int x, int xRow, int xColumn);
void printMatrix(Node *matrix);
int sumOfDiagonal(Node *matrix);

// Main program
int main(int argc, char *argv[])
{
    // Build blank matrix
    Node *matrix = buildMatrix(atoi(argv[1]), atoi(argv[2]));

    // Check if any values are present to be inserted
    if(atoi(argv[3]) != 0)
    {
        // Build array of values to be inserted
        int lenArray = atoi(argv[3])*3;
        int *intArray = grabInput(argv, lenArray, 4);
        prepValues(matrix, intArray, lenArray);
    }

    // Print matrix
    printMatrix(matrix);

    int sum = 0;
    // Check if values were inserted and if matrix is square
    if(atoi(argv[3]) != 0 && atoi(argv[1]) == atoi(argv[2]))
    {
        // If it is, find the sum of the diagonal
        // If not, leave sum as 0
        sum = sumOfDiagonal(matrix);
    } 
    printf("Sum of main diagonal: %d\n", sum);

    return 0;
}

// Builds an empty matrix (in the form of a doubly linked list) of the specified number of rows and columns
// Returns pointer to start of linked list
Node *buildMatrix(int rows, int columns)
{
    // Create Pointers
    Node *cur, *first, *tmp;

    // Create first node
    first = (Node *)calloc(1, sizeof(Node));
    cur = first;
    cur->prev = NULL;
    cur->val = 0;
    cur->rowIndex = 0;
    cur->columnIndex = 0;

    // i is used to represent the current row
    // j is used to represent the current column
    // Loop post-processing is node inside the loop, removing the need for the final argument of the loop
    for (int i = 0, j = 1; i < rows; )
    {
        // Allocate next memory and assign to cur
        cur->next = (Node *)calloc(1, sizeof(Node));
        // Build remaining node details
        tmp = cur;
        cur = cur->next;
        cur->prev = tmp;
        cur->val = 0;
        cur->rowIndex = i;
        cur->columnIndex = j;
        j++;

        // If we have exceeded the column limit, loop back to column 1 and begin new row
        if(j == columns)
        {
            i++;
            j = 0;
        }
    }
    // Set next to NULL
    cur->next = NULL;

    // Return address of first node
    return first;
}

// Build intArray from command line input
// Returns pointer to intArray
int *grabInput(char *argv[], int length, int pos)
{
    int *intArray = (int *)malloc(length * sizeof(int));
    for (int i = pos, j = 0; j < length; i++, j++)
    {
        intArray[j] = atoi(argv[i]);
    }
    return intArray;
}

// Preps values for use by insertValues
// intArray is formatted that values come in triplets of value, row, column
// Eg. intArray[0] = value, intArray[1], intArray[2] = column, intArray[3] = value....
void prepValues(Node *matrix, int *intArray, int length)
{
    for (int i = 0; i < length; i += 3) {
        insertValue(matrix, intArray[i], intArray[i+1], intArray[i+2]);
    }
}

// Inserts value (x) at position (xRow, xColumn) in matrix (stored as linked list)
void insertValue(Node *matrix, int x, int xRow, int xColumn)
{
    Node *cur = NULL;
    
    // Moves through list from start to end
    for (cur = matrix; cur != NULL; cur = cur->next)
    {
        // When correct position is found, insert value and exit function
        if (cur->rowIndex == xRow && cur->columnIndex == xColumn) {
            cur->val = x;
            return;
        } 
    }
}

// Prints matrix stored in linked list
void printMatrix(Node *matrix)
{
    Node *cur = NULL, *tmp = NULL;

    for (cur = matrix; cur != NULL; cur = cur->next) 
    {
        // Check for first iteration to avoid errors
        if(tmp != NULL)
        {
            // When we're on a new row, add a newline character before starting to print
            if(tmp->rowIndex != cur->rowIndex)
            {
                printf("\n");
            }
        }
        printf("%d ", cur->val);

        // Tmp is used to store the previous value encountered
        tmp = cur;
    }
    // Add newline character to end of matrix
    printf("\n");
}

// Finds sum of the diagonal of a matrix (which is stored as a linked list)
// Returns sum as int
int sumOfDiagonal(Node *matrix)
{
    Node *cur = NULL;
    int sum = 0;

    for (cur = matrix; cur != NULL; cur = cur->next)
    {
        // Whenever at a diagonal point, add this value to the sum
        if(cur->rowIndex == cur->columnIndex)
        {
            sum += cur->val;
        }
    }

    return sum;
}

