#include <limits.h>
#include <stdio.h>

long flippingBits(long n) { return UINT_MAX ^ n; }

int main() {
  printf("%ld\n", flippingBits(9));
  printf("%ld\n", flippingBits(4));
  printf("%ld\n", flippingBits(123456));
  printf("%ld\n", flippingBits(0));
  printf("%ld\n", flippingBits(802743475));
  printf("%ld\n", flippingBits(35601423));
}
