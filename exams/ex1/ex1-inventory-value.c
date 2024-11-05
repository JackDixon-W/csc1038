/*
Author: Jack Dixon
Description: Takes input through command line of multiple products and their details.
These products are sorted into an array before having their total cost tallied up and printed.
Discount of 10% is applied if necessary.
Date: 31/10/2024
*/

// Included Libraries
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Type Declarations
typedef struct Product Product;

// Structure Declarations
struct Product {
    char name[20];
    unsigned int stock;
    float price;
    int discount;
};

// Function Prototypes
void grabProducts(Product *inventory, int length, char *argv[]);
float findInventoryValue(Product *inventory, int length);

int main(int argc, char *argv[])
{
    int lenInventory = (argc - 1) / 4;
    // Inventory array holds all product structures
    Product inventory[lenInventory];

    grabProducts(inventory, argc-1, argv);

    printf("%.2f\n", findInventoryValue(inventory, lenInventory));

    return 0;
}

// Function grabs product information from command line and stores in inventory array
// In this case, length refers to the length of argv
void grabProducts(Product *inventory, int length, char *argv[])
{
    // Initialise pointer to assign values to inventory
    Product *pProduct;

    /*
    i iterates (on +4) through argv, j iterates (on +1) through argv
    i will mark the beginning of each product in the command line
    j will mark the index of the current item in the inventory array
    */
    for (int i = 1, j = 0; i <= length; i += 4, j++)
    {
        pProduct = &inventory[j];
        strcpy(pProduct->name, argv[i]);
        pProduct->stock = atoi(argv[i+1]);
        pProduct->price = atof(argv[i+2]);
        pProduct->discount = atoi(argv[i+3]);
    }
    return;
}

// Function prints all products stored in inventory array
float findInventoryValue(Product *inventory, int length)
{
    // Initialise variables
    float curValue;
    float totalValue = 0;

    // Initialise pointer to grab values from inventory
    Product *pProduct;

    // Iterates through each product in the inventory, printing all details
    for (int i = 0; i < length; i++, curValue = 0) {
        pProduct = &inventory[i];
        curValue = pProduct->stock * pProduct->price;

        // Checks for discount, and applies if necessary
        if (pProduct->discount == 1) {
            curValue = curValue * 0.9;
        } 
        
        totalValue += curValue;
    }

    return totalValue;
}