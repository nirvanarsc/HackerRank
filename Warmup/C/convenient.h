#include <stdlib.h>

int gcd(int a, int b) {
  while (b != 0) {
    int t = b;
    b = a % b;
    a = t;
  }
  return a;
}

int lcm(int a, int b) { return abs(a * b) / gcd(a, b); }

int arrayApply(int* arr, int arr_length, int (*f)(int, int)) {
  if (arr_length < 2) {
    printf("Array must have at least 2 elements.\n");
    return 1;
  }
  int res = (*f)(arr[0], arr[1]);
  for (int i = 2; i < arr_length; i++) {
    res = (*f)(res, arr[i]);
  }
  return res;
}
