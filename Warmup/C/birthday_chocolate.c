#include <stdio.h>
#include "conveniences.h"

int birthday(int s_count, int* s, int d, int m) {
  if (m > s_count) {
    return 0;
  }

  if (m == s_count) {
    if (sum(s, s_count) == d) {
      return 1;
    }
    return 0;
  }

  int res = 0;

  for (int i = 0, sum = 0; i < s_count - m + 1; i++, sum = 0) {
    for (int j = i; j < m + i; j++) {
      sum += s[j];
    }
    if (sum == d) {
      res++;
    }
  }
  return res;
}

int main() {
  int arr[] = {1, 2, 1, 3, 2};
  int arr_length = sizeof(arr) / sizeof(arr[0]);
  int day = 3;
  int month = 2;
  printf("%d\n", birthday(arr_length, arr, day, month));
}
