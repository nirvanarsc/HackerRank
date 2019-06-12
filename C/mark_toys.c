#include "merge_sort.h"
#include <stdio.h>

int maximumToys(int prices_count, int* prices, int k) {
  mergeSort(prices, 0, prices_count - 1);

  int curr = 0;
  int i = 0;
  while (curr < k) {
    curr += prices[i++];
  }
  return i - 1;
}

int main() {
  int arr[] = {1, 12, 5, 111, 200, 1000, 10};
  int l = sizeof(arr) / sizeof(arr[0]);
  int k = 50;

  printf("%d\n", maximumToys(l, arr, k));
}
