#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int try = atoi(argv[1]);
  int conversion = atoi(argv[2]);
  int penalty = atoi(argv[3]);
  int dropgoal = atoi(argv[4]);
  int total = (try*5) + (conversion*2) + (penalty*3) + (dropgoal*3);
  printf("%d\n",total);
  return 0;
}
