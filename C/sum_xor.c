#include <math.h>
#include <stdio.h>

long sumXor(long n) {
  long res = 0;
  while (n > 0) {
    if ((n & 1) == 0) {
      res++;
    }
    n >>= 1;
  }
  return pow(2, res);
}

int main() {
  printf("%ld\n", sumXor(4));
  printf("%ld\n", sumXor(5));
  printf("%ld\n", sumXor(7));
  printf("%ld\n", sumXor(10));
}
