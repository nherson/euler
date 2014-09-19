#include "omp.h"
#include "stdio.h"
#include "sys/time.h"

int main()
{
  int start, finish;
  unsigned long ans;
  int time_taken;

  printf("BEGIN SLOW TESTS\n=================\n");

  start = clock();
  ans = sum_muls_3_5(1000);
  finish = clock();
  time_taken = (finish - start);
  printf((char*) "1,000 Answer: %lu \n", ans);
  printf((char*) "1,000 Time: %lu \n\n", time_taken);

  start = clock();
  ans = sum_muls_3_5(10000);
  finish = clock();
  time_taken = (finish - start);
  printf((char*) "10,000 Answer: %lu \n", ans);
  printf((char*) "10,000 Time: %lu \n\n", time_taken);

  start = clock();
  ans = sum_muls_3_5(100000);
  finish = clock();
  time_taken = (finish - start);
  printf((char*) "100,000 Answer: %lu \n", ans);
  printf((char*) "100,000 Time: %lu \n\n", time_taken);

  start = clock();
  ans = sum_muls_3_5(1000000);
  finish = clock();
  time_taken = (finish - start);
  printf((char*) "1,000,000 Answer: %lu \n", ans);
  printf((char*) "1,000,000 Time: %lu \n\n", time_taken);


  printf("BEGIN FAST TESTS\n==============\n");
  start = clock();
  ans = sum_muls_3_5_optimized(1000);
  finish = clock();
  time_taken = (finish - start);
  printf((char*) "1,000 Answer: %lu \n", ans);
  printf((char*) "1,000 Time: %lu \n\n", time_taken);

  start = clock();
  ans = sum_muls_3_5_optimized(10000);
  finish = clock();
  time_taken = (finish - start);
  printf((char*) "10,000 Answer: %lu \n", ans);
  printf((char*) "10,000 Time: %lu \n\n", time_taken);

  start = clock();
  ans = sum_muls_3_5_optimized(100000);
  finish = clock();
  time_taken = (finish - start);
  printf((char*) "100,000 Answer: %lu \n", ans);
  printf((char*) "100,000 Time: %lu \n\n", time_taken);

  start = clock();
  ans = sum_muls_3_5_optimized(1000000);
  finish = clock();
  time_taken = (finish - start);
  printf((char*) "1,000,000 Answer: %lu \n", ans);
  printf((char*) "1,000,000 Time: %lu \n\n", time_taken);

}

int sum_muls_3_5_optimized(int n)
{
  // for each chunk of 15 values, add baseval+(each val in MODULO_MULS) to sum
  int chunk_size = 15;
  int modulo_muls[7] = {0,3,5,6,9,10,12};
  int modulo_muls_size = 7;
  int i=0;
  unsigned long sum=0;
  #pragma omp parallel for reduction(+:sum)
  for (i=0; i<n; i+=chunk_size)
  {
    int j = 0;
    for (j=0; j<modulo_muls_size; j++)
    {
      // ensure we are still in range
      if (i+modulo_muls[j] < n) {
        sum += (unsigned long) i + (unsigned long) modulo_muls[j];
      }
    }
  }
  return sum;
}

int sum_muls_3_5(int n)
{
  // for each chunk of 15 values, add baseval+(each val in MODULO_MULS) to sum
  int chunk_size = 15;
  int modulo_muls[7] = {0,3,5,6,9,10,12};
  int modulo_muls_size = 7;
  int i=0;
  unsigned long sum=0;
  for (i=0; i<n; i+=chunk_size)
  {
    int j = 0;
    for (j=0; j<modulo_muls_size; j++)
    {
      // ensure we are still in range
      if (i+modulo_muls[j] < n) {
        sum += (unsigned long) i + (unsigned long) modulo_muls[j];
      }
    }
  }
  return sum;
}

