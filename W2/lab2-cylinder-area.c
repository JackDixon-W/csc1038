#include <stdio.h>
#include <stdlib.h>

#define PI 3.1415

//PI(r^2)h
int main(int argc, char *argv[])
{
  int radius = atoi(argv[1]);
  int height = atoi(argv[2]);
  float ans = (2 * PI * radius * height) + (2 * PI * (radius*radius));
  printf("%.2f\n", ans);
}
