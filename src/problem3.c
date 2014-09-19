#include "./problem3.h"

int main()
{
  ll *factor_list = factors(60087);
  printf("Done factorizing\n");
  ll *node = factor_list;
  while((*node).val != 0)
  {
    printf("Factor: %lu\n", (*node).val);
    node = (*node).next;
  }
  //printf("Largest prime: %lu", lp);
}

ll * factors(unsigned long n)
{
  int a = 1;
  // things get multiplied into this
  unsigned long product = 1;
  unsigned long x;
  unsigned long y;
  unsigned long d;
  ll *primes = malloc(sizeof(ll));
  (*primes).val = 0;
  (*primes).next = 0;
  while (product != n)
  {
    x = 2;
    y = 2;
    d = 1;
    while (d == 1)
    {
      x = f(x, a) % n;
      y = f((f(x, a) % n), a) % n;
      d = gcd(abs_val(x, y), n);
      if (d == n)
      {
        break;
      }
    }
    if (d != n) {
      if (n % (product*d) == 0)
      {
        printf("found prime: %lu\n", d);
        product = product * d;
        // prepend to primes list
        ll *item = (ll *) malloc(sizeof(ll));
        (*item).val = d;
        (*item).next = primes;
        primes = item;
      }
    }
    a++;
    printf("New a: %d\n", a);
  }
  return primes;
}

unsigned long f(unsigned long x, int a)
{
  return ((x*x) + a);
}

unsigned long gcd (unsigned long a, unsigned long b)
{
  unsigned long c;
  while ( a != 0 ) 
  {
    c = a;
    a = b%a;
    b = c;
  }
  return b;
}

// return the abs value of the difference of the 2 numbers
unsigned long abs_val(unsigned long a, unsigned long b)
{
  if (a > b)
  {
    return (a - b);
  }
  else
  {
    return (b - a);
  }
}


