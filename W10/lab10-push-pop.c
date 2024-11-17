/*
Author: Jack Dixon
Description: Takes input of array of floats (argv[1] should be length of array).
Organises them into a doubly linked list.
Pops end value twice, then adds two new values through push function.
Prints all values at end.
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
    float value;
    Node *prev, *next;
};

// Function Prototypes
float *grabInput(char *argv[], int length, int pos);
Node *createNodes(float *floatArray, int length);
void printDoublyLinkedList(Node *linkedList, int reverse);
void Pop(Node *startOfList);
void Push(Node *startOfList, float value);

// Main program
int main(int argc, char *argv[])
{
    float *floatArray = grabInput(argv, atoi(argv[1]), 2);
    Node *linkedList = createNodes(floatArray, atoi(argv[1]));
    Pop(linkedList);
    Pop(linkedList);
    Push(linkedList, atoi(argv[atoi(argv[1])+2]));
    Push(linkedList, atoi(argv[atoi(argv[1])+3]));
    printDoublyLinkedList(linkedList, 0);

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

// Prints a doubly linked list either backwards or forwards
// 0 = Forwards, 1 = Backwards
void printDoublyLinkedList(Node *linkedList, int reverse)
{
    Node *cur, *end;

    switch (reverse)
    {
    case 0:
        for (cur = linkedList; cur != NULL; cur = cur->next)
        {
            printf("%.0f\n", cur->value);
        }
        break;
    
    case 1:
        // Moves through list from start to end
        // Saving a pointer to the node at the end before NULL
        for (cur = linkedList; cur != NULL; cur = cur->next)
        {
            end = cur;
        }
        // From this end point, moves back through list until hitting NULL on other side
        for (cur = end; cur != NULL; cur = cur->prev)
        {
            printf("%.0f\n", cur->value);
        }
        break;
    
    default:
        printf("ERROR, INVALID ORDER VALUE\n");
        break;
    }
    
}

// Pops item at end of linked list
void Pop(Node *startOfList)
{
    Node *pPop, *tmp;
    // First find the end of the list
    for (Node *cur = startOfList; cur != NULL; cur = cur->next)
    {
        pPop = cur;
    }
    // pPop is currently the final item in the list
    tmp = pPop;
    pPop = pPop->prev;
    // Freeing prev doesn't just free the pointer, it frees the struct too
    //free(tmp->prev);
    free(tmp->next);
    free(tmp);
    pPop->next = NULL;
}

// Pushes new value to end of linked list
void Push(Node *startOfList, float val)
{
    Node *pPush, *tmp;
    // Find end of list
    for (Node *cur = startOfList; cur != NULL; cur = cur->next)
    {
        pPush = cur;
    }
    // Allocate memory and assign details for new item
    pPush->next = (Node *)calloc(1, sizeof(Node));
    tmp = pPush;
    pPush = pPush->next;
    pPush->prev = tmp;
    pPush->value = val;
    pPush->next = NULL;
}