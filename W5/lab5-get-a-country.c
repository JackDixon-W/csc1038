#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Country
{
    // Leaving size of arrays as static values
    // This is entirely due to the workaround involving malloc()
    char name[25];
    char capital[25];
    float pop;
    int size;
};

int main(int argc, char *argv[])
{
    struct Country country1;
    strcpy(country1.name, argv[1]);
    strcpy(country1.capital, argv[2]);
    country1.pop = atof(argv[3]);
    country1.size = atoi(argv[4]);

    printf("%s\n", country1.name);
    printf("%s\n", country1.capital);
    printf("%.2f million people\n", country1.pop);
    printf("%d km2\n", country1.size);

    return 0;
}
