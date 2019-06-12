#include "merge_sort.h"
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

int sizeOf(int* arr) { return sizeof(arr) / sizeof(arr[0]); }

bool checkValid(int* sticks, int index) {
  return (sticks[index] + sticks[index + 1] > sticks[index + 2]);
}

int* maximumPerimeterTriangle(int sticks_count, int* sticks,
                              int* result_count) {

  int curr = -1;
  mergeSort(sticks, 0, sticks_count - 1);

  for (int i = 0; i < sticks_count - 2; i++) {
    if (checkValid(sticks, i)) {
      curr = i;
    }
  }

  if (curr == -1) {
    *result_count = 1;
    int* res = malloc(*result_count * sizeof(int));
    res[0] = curr;
    return res;
  }

  *result_count = 3;
  int* res = malloc(*result_count * sizeof(int));
  res[0] = sticks[curr];
  res[1] = sticks[curr + 1];
  res[2] = sticks[curr + 2];

  return res;
}

int main() {
  int arr1[] = {1, 1, 1, 3, 3};
  int l1 = sizeof(arr1) / sizeof(arr1[0]);
  int arr2[] = {1, 2, 3};
  int l2 = sizeof(arr2) / sizeof(arr2[0]);
  int arr3[] = {1, 1, 1, 2, 3, 5};
  int l3 = sizeof(arr3) / sizeof(arr3[0]);

  int res1L = 0;
  int res2L = 0;
  int res3L = 0;
  int* res1 = maximumPerimeterTriangle(l1, arr1, &res1L);
  int* res2 = maximumPerimeterTriangle(l2, arr2, &res2L);
  int* res3 = maximumPerimeterTriangle(l3, arr3, &res3L);

  for (int i = 0; i < res1L; i++) {
    printf("%d ", res1[i]);
  }
  printf("\n");
  for (int i = 0; i < res2L; i++) {
    printf("%d ", res2[i]);
  }
  printf("\n");
  for (int i = 0; i < res3L; i++) {
    printf("%d ", res3[i]);
  }
  printf("\n");
}
