#include <stdlib.h>
#include <stdio.h>
#include <string.h>

// Type Declaration
typedef struct Country Country;
typedef struct City City;

// Structure Declaration
struct City
{
    char name[25];
    int size;
}; 

struct Country
{
    char name[25];
    City cities[3];
};

// Function Declarations
void grab_countries(Country *countries, int length, char *argv[]);
void print_countries(Country *countries, int length);
City findBiggestCity(Country *country);

int main(int argc, char *argv[])
{
    int lenCountry = (argc - 1) / 7;

    // Declare array to hold all struct instance pointers
    Country countries[50];

    // Function grabs and assigns variables to array
    grab_countries(countries, argc-1, argv);
    
    // They are given to the print function for proper formatting
    print_countries(countries, lenCountry);

    return 0;
}

// Function for assigning all variables to struct array from argv
void grab_countries(Country *countries, int length, char *argv[])
{
    // Initialise pointer to assign values
    Country *pCountry;
    City *pCity;

    // i iterates (on +4) through argv
    // j iterates through countries
    for (int i = 1, j = 0; i <= length; i += 7, j++)
    {
        pCountry = &countries[j];
        pCity = &countries[j].cities[0];
        strcpy(pCountry->name, argv[i]);
        // City 1
        strcpy(pCity->name, argv[i+1]);
        pCity->size = atoi(argv[i+2]);
        // City 2
        pCity++;
        strcpy(pCity->name, argv[i+3]);
        pCity->size = atoi(argv[i+4]);
        // City 3
        pCity++;
        strcpy(pCity->name, argv[i+5]);
        strcpy(pCity->name, argv[i+6]);
    }
    return;
}

// Function for printing all countries
void print_countries(Country *countries, int length)
{
    // Initialise pointer to grab values
    Country *pCountry;
    City pBiggestCity;

    for (int i = 0; i < length; i++)
    {
        pCountry = &countries[i];
        printf("%s: ", pCountry->name);
        pBiggestCity = findBiggestCity(pCountry);
        printf("%s\n", pBiggestCity.name);
    }
    return;
}

City findBiggestCity(Country *country)
{
    Country *pCountry;
    City *pBiggestCity = &country->cities[0];
    City *pCurCity;

    for (int i = 0; i < 3; i++)
    {
        pCurCity = &country->cities[i];
        if(pCurCity->size > pBiggestCity->size)
        {
            pBiggestCity = pCurCity;
        }
    }
    return *pBiggestCity;
}