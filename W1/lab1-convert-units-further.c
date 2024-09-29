#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  for (int cm = 30;cm < 50;cm++)
  {
    float inch = cm / 2.54;
    printf("%.2f\n",inch);
  }
  return (0);
}
