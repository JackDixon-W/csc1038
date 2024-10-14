#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Structure Declaration
struct Country
{
    // Leaving size of arrays as static values
    // This is entirely due to the workaround involving malloc()
    char name[25];
    char capital[25];
    float pop;
    int size;
};

// Function Declarations
void grab_countries(struct Country *countries, int length, char *argv[]);
void print_countries(struct Country *countries, int length);

int main(int argc, char *argv[])
{
    int lenCountry = (argc - 1) / 4;

    // Declare array to hold all struct instance pointers
    struct Country countries[50];

    // Function grabs and assigns variables to array
    grab_countries(countries, argc-1, argv);
    int i = 2;
    
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