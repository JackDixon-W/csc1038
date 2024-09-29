#include <stdio.h>
#include <stdlib.h>

// I attempted to add a function, but believed it would add
// unnecessarily complexity to the code. To keep things neat and
// organised, I've opted to keep everything inside the main.

int main(int argc, char *argv[])
{
  int inp = 0;
  int total = 0;
  for(int i = 0;i < 4;i++)
  {
    inp = 0;
    scanf("%d", &inp);

    // This loop is used to force a constant scanf until
    // the user inputs a non-negative value
    while (inp < 0)
    {
      scanf("%d", &inp);
    }

    switch(i){
      case 0:
        total += inp*5;
        break;
      case 1:
        total += inp*2;
        break;
      case 2:
        total += inp*3;
        break;
      case 3:
        total += inp*3;
        break;
    }
  }

  printf("%d\n", total);

  return 0;
}
