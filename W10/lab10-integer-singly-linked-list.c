/*
Author: Jack Dixon
Description: Takes input of array of integers (argv[1] should be length of array).
Organises them into a singly linked list before printing them.
Date: 15-11-24
*/

// Included Libraries
#include <stdlib.h>
#include <stdio.h>

// Type Declarations
typedef struct Node Node;

// Structure Declarations
struct Node
{
    int value;
    Node *next;
};

// Function Prototypes
int *grabInput(char *argv[], int length, int pos);
Node *createNodes(int *intArray, int length);
void printLinkedList(Node *linkedList);

// Main program
int main(int argc, char *argv[])
{
    int *intArray = grabInput(argv, atoi(argv[1]), 2);
    Node *linkedList = createNodes(intArray, argc-2);
    printLinkedList(linkedList);

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

Node *createNodes(int *intArray, int length)
{
    // Create Pointers
    Node *cur, *first;

    // Create first node (cur = first)
    first = (Node *)calloc(1, sizeof(Node));
    cur = first;
    cur->value = intArray[0];

    for (int i = 1; i < length; i++)
    {
        // Allocate next memory and assign to cur
        cur->next = (Node *)calloc(1, sizeof(Node));
        // Set current to next
        cur = cur->next;

        cur->value = intArray[i];

    }
    // Set next to NULL
    cur->next = NULL;

    // Return address of first node
    return first;
}

void printLinkedList(Node *linkedList)
{
    Node *cur = NULL;
    for (cur = linkedList; cur != NULL; cur = cur->next)
    {
        printf("%d\n", cur->value);
    }
    
}