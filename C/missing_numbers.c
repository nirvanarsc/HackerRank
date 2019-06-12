#include "conveniences.h"

int* missingNumbers(int arr_count, int* arr, int brr_count, int* brr,
                    int* result_count) {

  *result_count = brr_count - arr_count;
  int index = 0;
  int* map1 = calloc(10000, sizeof(int));
  int* map2 = calloc(10000, sizeof(int));
  int* res = malloc(*result_count * sizeof(int));

  for (int i = 0; i < arr_count; i++) {
    map1[arr[i]]++;
  }

  for (int i = 0; i < brr_count; i++) {
    map2[brr[i]]++;
  }

  for (int i = 0; i < 10000; i++) {
    if (map1[i] != map2[i]) {
      res[index++] = i;
    }
  }

  return res;
}

int main() {
  int l = 0;
  int arr[] = {203, 204, 205, 206, 207, 208, 203, 204, 205, 206};
  int arr_l = sizeof(arr) / sizeof(arr[0]);

  int brr[] = {203, 204, 204, 205, 206, 207, 205, 208, 203, 206, 205, 206, 204};
  int brr_l = sizeof(brr) / sizeof(brr[0]);

  int* res = missingNumbers(arr_l, arr, brr_l, brr, &l);

  simplePrintArray(res, l);
}
