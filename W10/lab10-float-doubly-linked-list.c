/*
Author: Jack Dixon
Description: Takes input of array of floats (argv[1] should be length of array).
Organises them into a doubly linked list before printing them in reverse.
Reverse print done by moving through list forwards (without printing)
and then backwards (while printing).
Date: 15-11-24
*/

// Included Libraries
#include <stdlib.h>
#include <stdio.h>
//#include <string.h>

// Type Declarations
typedef struct Node Node;

// Structure Declarations
struct Node
{
    float value;
    Node *prev, *next;
};

// Function Prototypes
float *grabInput(char *argv[], int length, int pos);
Node *createNodes(float *floatArray, int length);
void printDoublyLinkedList(Node *linkedList);

// Main program
int main(int argc, char *argv[])
{
    float *floatArray = grabInput(argv, atoi(argv[1]), 2);
    Node *linkedList = createNodes(floatArray, atoi(argv[1] ));
    printDoublyLinkedList(linkedList);

    return 0;
}

// Build floatArray from command line input
// Returns pointer to floatArray
float *grabInput(char *argv[], int length, int pos)
{
    float *floatArray = (float *)malloc(length * sizeof(float));
    for (int i = pos, j = 0; j < length; i++, j++)
    {
        floatArray[j] = atof(argv[i]);
    }
    return floatArray;
}

Node *createNodes(float *floatArray, int length)
{
    // Create Pointers
    Node *cur, *first, *tmp;

    // Create first node (cur = first)
    first = (Node *)calloc(1, sizeof(Node));
    cur = first;
    cur->prev = NULL;
    cur->value = floatArray[0];

    for (int i = 1; i < length; i++)
    {
        // Allocate next memory and assign to cur
        cur->next = (Node *)calloc(1, sizeof(Node));
        // Build remaining node details
        tmp = cur;
        cur = cur->next;
        cur->prev = tmp;
        cur->value = floatArray[i];

    }
    // Set next to NULL
    cur->next = NULL;

    // Return address of first node
    return first;
}

void printDoublyLinkedList(Node *linkedList)
{
    Node *cur = NULL; 
    Node *end;
    // Moves through list from start to end
    // Saving a pointer to the node at the end before NULL
    for (cur = linkedList; cur != NULL; cur = cur->next)
    {
        end = cur;
    }
    
    // From this end point, moves back through list until hitting NULL on other side
    for (cur = end; cur != NULL; cur = cur->prev)
    {
        printf("%.2f\n", cur->value);
    }
    
}