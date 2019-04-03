#include <stdio.h>
#include "convenient.h"

int main() {
  int a[] = {65, 10, 5};
  int a_length = sizeof(a) / sizeof(a[0]);

  printf("%d\n", arrayApply(a, a_length, gcd));
  printf("%d\n", arrayApply(a, a_length, lcm));
}
