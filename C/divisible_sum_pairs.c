#include <stdio.h>

int divisibleSumPairs(int k, int ar_count, int* ar) {
  int res = 0;
  for (int i = 0; i < ar_count - 1; i++) {
    for (int j = i + 1; j < ar_count; j++) {
      if ((ar[i] + ar[j]) % k == 0) res++;
    }
  }

  return res;
}

int main() {
  int arr[] = {1, 2, 3, 4, 5, 6};
  int arr_length = sizeof(arr) / sizeof(arr[0]);
  int k = 5;

  int arr2[] = {1, 3, 2, 6, 1, 2};
  int arr2_length = sizeof(arr2) / sizeof(arr2[0]);
  int k2 = 3;

  printf("%d\n", divisibleSumPairs(k, arr_length, arr));
  printf("%d\n", divisibleSumPairs(k2, arr2_length, arr2));
}
