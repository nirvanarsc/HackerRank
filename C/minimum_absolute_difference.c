#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include "merge_sort.h"

int minimumAbsoluteDifference(int arr_count, int* arr) {
  mergeSort(arr, 0, arr_count - 1);

  int res = INT_MAX;

  for (int i = 1; i < arr_count; i++) {
    int c = abs(arr[i] - arr[i - 1]);
    if (res > c) {
      res = c;
    }
  }
  return res;
}

int main() {
  int arr[] = {-59, -36, -13, 1, -53, -92, -2, -96, -54, 75};
  int length = sizeof(arr) / sizeof(arr[0]);

  printf("%d\n", minimumAbsoluteDifference(length, arr));
}
