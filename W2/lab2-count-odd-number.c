#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int odd_count = 0;
  int nums[10];
  for(int i = 0;i < argc;i++)
  {
    nums[i] = atoi(argv[i]);
  }

  for(int i = 0;i < argc;i++)
  {
    if (nums[i] % 2 == 1)
    {
      odd_count++;
    }
  }
  printf("%d\n", odd_count);
  return 0;
}
