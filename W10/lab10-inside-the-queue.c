/*
Author: Jack Dixon
Description: Creates doubly linked list from hardcoded float array.
Argv[1] gives a position in list. Argv[2] gives a value to insert after this position.
Finds the pointer to the correct node to insert after. 
Then this pointer is used to build the new node and link the rest of the list into it.
Date: 17-11-24
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
Node *createNodes(float *floatArray, int length);
void printDoublyLinkedList(Node *linkedList, int reverse);
void pushAfterPos(Node *posInLoop, float val);
Node *findFloat(Node *startOfList, float val);

// Main program
int main(int argc, char *argv[])
{
    // This part is just done because all the rest of my code works in pointers
    float floatArray[10] = {8, 7, 3, 4, 5, 6, 9, 2, 14, 12};
    float *pFloatArray = floatArray;
    Node *linkedList = createNodes(pFloatArray, 10);

    // Grab pointer to pos from function
    Node *insertPos = findFloat(linkedList, atof(argv[1]));
    pushAfterPos(insertPos, atof(argv[2]));
    
    printDoublyLinkedList(linkedList, 0);

    return 0;
}

// Creates doubly linked list from floatArray
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

// Pushes new value to pos in linked list
void pushAfterPos(Node *posInLoop, float val)
{
    Node *nextPos;

    // Save the node that comes after this one
    nextPos = posInLoop->next;

    // Create new node
    posInLoop->next = (Node *)calloc(1, sizeof(Node));
    posInLoop = posInLoop->next;
    // Assign values to new Node
    posInLoop->value = val;

    // If this is not end of list
    if (nextPos != NULL)
    {
        // Link latter part of list to it
        nextPos->prev = posInLoop;
    }  else
    {
        nextPos = NULL;
    }
    
    // Assigns final attribute to the new node
    posInLoop->next = nextPos;
}

// Finds a float value in the list and returns a pointer to it if found
// If not found, returns 0
Node *findFloat(Node *startOfList, float val)
{
    for (Node *cur = startOfList; cur != NULL; cur = cur->next)
    {
        if (cur->value == val)
        {
            return cur;
        }
    }

    return 0;
}