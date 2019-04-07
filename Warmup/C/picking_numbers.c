#include "conveniences.h"

int check(int curr, int a_count, int* a) {
  int plusOne = 0;
  int minusOne = 0;
  for (int i = 0; i < a_count; i++) {
    if (a[i] == curr || a[i] == curr - 1) {
      minusOne++;
    }
    if (a[i] == curr || a[i] == curr + 1) {
      plusOne++;
    }
  }
  return plusOne > minusOne ? plusOne : minusOne;
}

int pickingNumbers(int a_count, int* a) {
  int res = 0;
  for (int i = 0; i < a_count; i++) {
    int k = check(a[i], a_count, a);
    res = k > res ? k : res;
  }

  return res;
}

int main() {
  int a[] = {1, 1, 2, 2, 4, 4, 5, 5, 5};
  int a_count = sizeof(a) / sizeof(a[0]);

  simplePrint(pickingNumbers(a_count, a));
}
