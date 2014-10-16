#include <stdio.h>

int main(int argc, char *argv[]) {
 
  int n, i;
  unsigned long result;

  if (argc == 1) {
    return 1;
  }
  else {
    n = atoi(argv[1]);
  }

  result = 2;
  for (i=3; i<n+1; i++) {
    printf("LCM of %d and %d: ", result, i);
    result = (result*i)/gcd(result, i);
    printf("%d\n", result);
  }

  printf("The GCF is: %d\n", result);
}

int gcd(int a, int b) {
  if (b > a) {
    // do some swapping
    int tmp = b;
    b = a;
    a = tmp;
  }
  if (b == 1) {
    return b;
  }
  else if (a % b == 0) {
    return b;
  }
  else {
    return gcd(b, a % b);
  }
}

int max(int s, int t) {
  if (s > t) {
    return s;
  }
  else {
    return t;
  }
}
