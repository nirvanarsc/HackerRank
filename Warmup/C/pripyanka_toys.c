#include "merge_sort.h"
#include <stdio.h>

int toys(int w_count, int* w) {
  mergeSort(w, 0, w_count - 1);
  int curr = w[0];
  int res = 1;
  for (int i = 1; i < w_count; i++) {
    if (w[i] > curr + 4) {
      curr = w[i];
      res++;
    }
  }
  return res;
}

int main() {
  int arr[] = {1, 2, 3, 21, 7, 12, 14, 21};
  int l = sizeof(arr) / sizeof(arr[0]);

  printf("%d\n", toys(l, arr));
}
