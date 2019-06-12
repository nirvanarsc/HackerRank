#include <stdio.h>
#include "conveniences.h"

int countMultiples(int a, int b) {
  int res = 0;
  for (int i = a, j = 2; i <= b; i = a * j, j++) {
    if (b % i == 0) {
      res++;
    }
  }
  return res;
}

int getTotalX(int a_count, int* a, int b_count, int* b) {
  return countMultiples(arrayApply(a, a_count, lcm),
                        arrayApply(b, b_count, gcd));
}

int main() {
  int a[] = {2, 4};
  int a_length = sizeof(a) / sizeof(a[0]);
  int b[] = {16, 32, 96};
  int b_length = sizeof(b) / sizeof(b[0]);

  printf("%d\n", getTotalX(a_length, a, b_length, b));
}
