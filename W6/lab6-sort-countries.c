#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Type Declaration
typedef struct Country Country;

// Structure Declaration
struct Country
{
    char name[25];
    char capital[25];
    float pop;
    int size;
};

// Function Declarations
void grab_countries(struct Country *countries, int length, char *argv[]);
void print_countries(struct Country *countries, int length);
void sort_countries(Country *countries, int length);

int main(int argc, char *argv[])
{
    int lenCountry = (argc - 1) / 4;

    // Declare array to hold all struct instance pointers
    struct Country countries[50];

    // Function grabs and assigns variables to array
    grab_countries(countries, argc-1, argv);
    
    sort_countries(countries, lenCountry);
    
    // They are given to the print function for proper formatting
    print_countries(countries, lenCountry);

    return 0;
}

// Function for assigning all variables to struct array from argv
void grab_countries(struct Country *countries, int length, char *argv[])
{
    // Initialise pointer to assign values
    struct Country *pCountry;

    // i iterates (on +4) through argv
    // j iterates through countries
    for (int i = 1, j = 0; i <= length; i += 4, j++)
    {
        pCountry = &countries[j];
        strcpy(pCountry->name, argv[i]);
        strcpy(pCountry->capital, argv[i+1]);
        pCountry->pop = atof(argv[i+2]);
        pCountry->size = atoi(argv[i+3]);
    }
    return;
}

// Function for printing all countries
void print_countries(struct Country *countries, int length)
{
    // Initialise pointer to grab values
    struct Country *pCountry;

    printf("Country\t\t\tCapital\t\t\tSize\t\t\tPopulation\n");
    for (int i = 0; i < length; i++)
    {
        pCountry = &countries[i];
        printf("%s\t\t\t", pCountry->name);
        printf("%s\t\t\t", pCountry->capital);
        printf("%d\t\t\t", pCountry->size);
        printf("%.2f\n", pCountry->pop);
    }
    return;
}

void sort_countries(Country *countries, int length)
{
    // Variable initialisation
    Country *pOther;
    Country *pCurrent;
    Country tempCountry;
    int sorted = 0;

    // While the array is unsorted
    while(sorted == 0)
    {
        // At beginning, set sorted to 1.
        // This ensures only the most recent sort is being checked
        sorted = 1;
        // For loop, iterating on i and j at the same time
        for(int i = length-1; i > 0; i--)
        {
            pOther = &countries[i+1];
            pCurrent = &countries[i];
            // Check if the element behind the current is lower than the current
            // If yes, swap and set sorted to 0. If no, do nothing.
            if(pCurrent->pop < pOther->pop)
            {
                tempCountry = *pCurrent;
                *pCurrent = *pOther;
                *pOther = tempCountry;
                sorted = 0;
            }
        }
    }
    

}
