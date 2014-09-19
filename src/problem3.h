#include<stdio.h>
#include<stdlib.h>

typedef struct linked_list {
  struct linked_list *next;
  unsigned long val;
} ll;

unsigned long f(unsigned long x, int a);

unsigned long gcd (unsigned long a, unsigned long b);

unsigned long abs_val(unsigned long a, unsigned long b);

unsigned long largest_prime(unsigned long);

ll* factors(unsigned long n);



