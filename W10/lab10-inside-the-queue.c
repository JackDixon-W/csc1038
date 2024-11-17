/*
Author: Jack Dixon
Description: 
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
float *grabInput(char *argv[], int length, int pos);
Node *createNodes(float *floatArray, int length);
void printDoublyLinkedList(Node *linkedList, int reverse);
void pushAfterPos(Node *startOfList, int pos, float val);
int findFloat(Node *startOfList, float val);

// Main program
int main(int argc, char *argv[])
{
    // This part is just done because all the rest of my code works in pointers
    float floatArray[11] = {8, 7, 3, 4, 5, 6, 9, 2, 1, 4, 12};
    float *pFloatArray = floatArray;
    Node *linkedList = createNodes(pFloatArray, 11);

    int pos = findFloat(linkedList, atof(argv[1]));
    if (pos == -1)
    {
        printf("ERROR in FindFloat\nExitting Program\n");
        exit(-1);
    }

    pushAfterPos(linkedList, pos, atof(argv[2]));
    
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

// Pushes new value to pos in linked list
void pushAfterPos(Node *startOfList, int pos, float val)
{
    Node *targetPos, *prevPos, *nextPos;
    int curPos = 1;
    /* Find target position in list using AND
    Only runs if both of the following conditions is true:
    1. Not at end of list
    2. We have not reached the target position in the list yet
    Stops if we reach the end of list or target pos, whichever happens first
    */
    for (targetPos = startOfList; targetPos != NULL && pos != curPos; targetPos = targetPos->next, curPos++)
    {
        prevPos = targetPos;
    }

    // Save the node that comes after this one
    nextPos = targetPos->next;

    // Create new node
    targetPos->next = (Node *)calloc(1, sizeof(Node));
    targetPos = targetPos->next;
    // Assign values to new Node
    targetPos->value = val;
    targetPos->prev = prevPos;

    // Link prior part of list to it
    prevPos->next = targetPos;

    // If there is a latter part of list
    if (nextPos != NULL)
    {
        // Link latter part of list to it
        nextPos->prev = targetPos;
    } 
    

}

// Finds a float value's position in the list and returns it if found
// If not found, returns 0
int findFloat(Node *startOfList, float val)
{
    Node *targetPos;
    int found = 0, pos = 1;
    for (Node *cur = startOfList; cur != NULL; cur = cur->next)
    {
        if (cur->value == val)
        {
            found = 1;
            break;
        }
        pos++;
    }

    if (found == 1)
    {
        return pos;
    } else
    {
        return 0;
    }
    
}