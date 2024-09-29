#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
  int max_size = 10;
  int nums[max_size];
  int found = 0;

  for(int i = 0;i < argc;i++)
  {
    nums[i] = atoi(argv[i]);
  }

  for(int i = 0;i < argc;i++)
  {
    if (nums[i] % 2 == 0 && nums[i] != 0)
    {
      printf("%d - %d\n", i-1, nums[i]);
      found = 1;
    }
  }

  if (found == 0)
  {
    printf("Not found!\n");
  }
  
}
