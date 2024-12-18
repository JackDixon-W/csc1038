/*
Author: Jack Dixon
Description: Takes command line arguments and converts them into a linked list 
First argument should be length, but isn't used in this code. Last argument should be a year.
Prints all components of the linked list in reverse.
Then takes last command line argument (which should be a year) and prints all books printed after that year.
Date: 28-11-24
*/

// Included Libraries
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Type Declarations
typedef struct Book Book;

// Structure Declarations
struct Book {
    char title[100];
    char author[100];
    int year;
    Book *prev, *next;
};

// Function Prototypes
Book *grabInput(char *argv[], int length);
void printCatalog(Book *library);
void printBooksAfterDate(Book *library, int searchYear);

// Main program
int main(int argc, char *argv[])
{
    // Initialise doubly linked list from inputs
    Book *library = grabInput(argv, argc-2);
    
    printCatalog(library);
    printBooksAfterDate(library, atoi(argv[argc-1]));

    return 0;
}

// Takes input from command line and converts into a doubly linked list
// Returns pointer to start of list
Book *grabInput(char *argv[], int length)
{
    // Create Pointers
    Book *cur, *first, *tmp;

    // Create first node
    first = (Book *)calloc(1, sizeof(Book));
    cur = first;
    cur->prev = NULL;
    strcpy(cur->title, argv[2]);
    strcpy(cur->author, argv[3]);
    cur->year = atoi(argv[4]);

    for (int i = 5; i < length; i += 3)
    {
        // Allocate next memory and assign to cur
        cur->next = (Book *)calloc(1, sizeof(Book));
        // Build remaining node details
        tmp = cur;
        cur = cur->next;
        cur->prev = tmp;
        strcpy(cur->title, argv[i]);
        strcpy(cur->author, argv[i+1]);
        cur->year = atoi(argv[i+2]);

    }
    // Set next to NULL
    cur->next = NULL;

    // Return address of first node
    return first;
}

// Prints the entire library catalog with formatting in reverse
void printCatalog(Book *library)
{
    Book *cur = NULL, *end;

    // Moves through list from start to end
    // Saving a pointer to the node at the end before NULL
    for (cur = library; cur != NULL; cur = cur->next)
    {
        end = cur;
    }

    printf("Library Catalog:\n");
    // Moves through list from end to start
    for (cur = end; cur != NULL; cur = cur->prev)
    {
        printf("Title: %s, ", cur->title);
        printf("Author: %s, ", cur->author);
        printf("Year: %d\n", cur->year);
    }
}

// Prints all books published after searchYear (in reverse of stored order)
void printBooksAfterDate(Book *library, int searchYear)
{
    Book *cur = NULL, *end;

    // Moves through list from start to end
    // Saving a pointer to the node at the end before NULL
    for (cur = library; cur != NULL; cur = cur->next)
    {
        end = cur;
    }

    int found = 0;
    printf("\nBooks published after %d:\n", searchYear);
    // Moves through list from end to start
    for (cur = end; cur != NULL; cur = cur->prev)
    {
        if (cur->year >= searchYear) {
            found = 1;
            printf("Title: %s, ", cur->title);
            printf("Author: %s, ", cur->author);
            printf("Year: %d\n", cur->year);
        } 
    }

    // Print in case no books were found after the searchYear
    if (found == 0) {
        printf("No books found published after %d.\n", searchYear);
    } 
}
