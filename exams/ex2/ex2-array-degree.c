/*
Author: Jack Dixon
Description: Takes input of many integers from command line. Finds the frequency of these integers and outputs the
frequency of the most frequent integer.
Date: 28-11-24
*/

// Included Libraries
#include <stdlib.h>
#include <stdio.h>

// Type Declarations
typedef struct Node Node;

// Structure Declarations
struct Node {
    int value;
    Node *prev, *next;
};

// Function Prototypes
int *grabInput(char *argv[], int length, int pos);
Node *createList(int *intArray, int length);
int findMax(int *intArray, int length);
int *createFreqArray(Node *linkedList, int maxVal);

// Main program
int main(int argc, char *argv[])
{
    // Grab inputs and convert them into an integer array for easier processing
    int *intArray = grabInput(argv, argc-1, 1);

    // Create a linked list from this array
    Node *linkedList = createList(intArray, argc-1);

    // Find the largest value in the original array
    int maxVal = findMax(intArray, argc-1);

    // Use this value to create a frequency array of all values in the input
    int *freqArray = createFreqArray(linkedList, maxVal);

    // Find the max value of the frequency array and output it
    int output = findMax(freqArray, maxVal+1);
    printf("%d\n", output);

    return 0;
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

// Creates doubly linked list from intArray
Node *createList(int *intArray, int length)
{
    // Create Pointers
    Node *cur, *first, *tmp;

    // Create first node (cur = first)
    first = (Node *)calloc(1, sizeof(Node));
    cur = first;
    cur->prev = NULL;
    cur->value = intArray[0];

    for (int i = 1; i < length; i++)
    {
        // Allocate next memory and assign to cur
        cur->next = (Node *)calloc(1, sizeof(Node));
        // Build remaining node details
        tmp = cur;
        cur = cur->next;
        cur->prev = tmp;
        cur->value = intArray[i];

    }
    // Set next to NULL
    cur->next = NULL;

    // Return address of first node
    return first;
}

// An array of integers along with that array's length is passed in
// Function finds largest value in the integer array and returns that value
int findMax(int *intArray, int length)
{
    int max = intArray[0];
    // Iterates through the array, comparing 'max' to each
    for (int i = 0; i < length; i++) {
        // If max is smaller than the current value in the array
        // Set this value as the new max
       if (max < intArray[i]) {
           max = intArray[i];
       }
    }
    return max;
}

// Finds most frequently occuring value in linkedList
// Returns the frequency of that value as an int
int *createFreqArray(Node *linkedList, int maxVal)
{
    Node *cur = NULL; 
    
    // Create array to store the frequency of all values
    int *freqArray = (int *)calloc(maxVal+1, sizeof(int));

    // Moves through list from start to end
    // Increasing frequency of each value in the frequency array as it is encountered
    for (cur = linkedList; cur != NULL; cur = cur->next)
    {
        freqArray[cur->value]++;
    }
    return freqArray;
}