#include "conveniences.h"

int* stones(int n, int a, int b, int* result_count) {
  *result_count = n;
  if (a == b) {
    *result_count = 1;
  }

  int* res = malloc(*result_count * sizeof(int));

  for (int i = 0; i < *result_count; i++) {
    res[i] = (n - 1 - i) * (a < b ? a : b) + i * (a < b ? b : a);
  }

  return res;
}

int main() {
  int length = 0;
  simplePrintArray(stones(4, 10, 100, &length), length);
}
