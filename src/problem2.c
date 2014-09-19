#include "stdio.h"

unsigned long even_fib_sum(int max);

int main()
{
  unsigned long sum;
  sum = even_fib_sum(4000000);
  printf("Sum to 4,000,000: %lu\n", sum);
}

unsigned long even_fib_sum(int max)
{
  int f1 = 1;
  int f2 = 1;
  int temp;
  unsigned long sum = 0;
  while (f2 < max)
  {
    if ((f2 % 2) == 0)
    {
      sum += (long) f2;
    }
    temp = f1 + f2;
    f1 = f2;
    f2 = temp;
  }
  return sum;
}



