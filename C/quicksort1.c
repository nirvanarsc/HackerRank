#include <stdio.h>
#include <stdlib.h>

int* quickSort(int arr_count, int* arr, int* result_count) {
  *result_count = arr_count;
  int* res = calloc(arr_count, sizeof(int));

  int pivot = arr[0];
  int idx = 0;
  for (int i = 0; i < arr_count; i++) {
    if (arr[i] < pivot) {
      res[idx++] = arr[i];
    }
  }
  for (int i = 0; i < arr_count; i++) {
    if (arr[i] == pivot) {
      res[idx++] = arr[i];
    }
  }
  for (int i = 0; i < arr_count; i++) {
    if (arr[i] > pivot) {
      res[idx++] = arr[i];
    }
  }

  return res;
}

int main() {
  int arr[] = {4, 5, 3, 7, 2};
  int arr_l = sizeof(arr) / sizeof(arr[0]);

  int res_l;
  int* res = quickSort(arr_l, arr, &res_l);
  for (int i = 0; i < res_l; i++) {
    printf("%d ", res[i]);
  }
  printf("\n");
}
