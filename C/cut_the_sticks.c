#include <limits.h>
#include <stdbool.h>
#include <string.h>
#include "conveniences.h"

bool isZero(int* arr, int arr_length) {
  for (int i = 0; i < arr_length; i++) {
    if (arr[i] != 0) {
      return false;
    }
  }
  return true;
}

int min_nonzero(int* arr, int arr_length) {
  int min = INT_MAX;
  for (int i = 0; i < arr_length; i++) {
    if (min > arr[i] && arr[i] != 0) {
      min = arr[i];
    }
  }
  return min;
}

int cut(int* arr, int arr_length) {
  int res = 0;
  int c = min_nonzero(arr, arr_length);

  for (int i = 0; i < arr_length; i++) {
    if (arr[i] != 0) {
      arr[i] = arr[i] - c;
      res++;
    }
  }
  return res;
}

int* cutTheSticks(int arr_count, int* arr, int* result_count) {
  int t_length = max(arr, arr_count);
  int* temp = calloc(t_length, sizeof(int));
  for (int i = 0; i <= t_length; i++) {
    if (isZero(arr, arr_count)) {
      *result_count = i;
      break;
    }
    temp[i] = cut(arr, arr_count);
  }
  int* res = malloc(*result_count * sizeof(int));
  memcpy(res, temp, *result_count * sizeof(int));
  free(temp);
  return res;
}

int main() {
  int arr[] = {1, 2, 3, 4, 3, 3, 2, 1};
  int arr_length = sizeof(arr) / sizeof(arr[0]);
  int res_length = 0;
  int* res = cutTheSticks(arr_length, arr, &res_length);
  simplePrintArray(res, res_length);
}
