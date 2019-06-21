#include <math.h>
#include <stdio.h>

int maximizingXor(int l, int r) {
  int left = log2(l);
  int right = log2(r);
  if (left != right) {
    return pow(2, right + 1) - 1;
  }
  return maximizingXor(l - pow(2, left), r - pow(2, right));
}

int main() {
  printf("%d\n", maximizingXor(11, 100));
  printf("%d\n", maximizingXor(10, 15));
  printf("%d\n", maximizingXor(304, 313));
}
