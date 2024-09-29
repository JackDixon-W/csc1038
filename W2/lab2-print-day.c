#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  char week[7][9] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
  int day = atoi(argv[1]);

  printf("%s\n", week[day-1]);
  
}
