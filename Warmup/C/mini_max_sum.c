#include <stdint.h>
#include <stdio.h>

void miniMaxSum(int arr_count, int *arr) {
  int64_t max = arr[0];
  int64_t min = arr[0];
  int64_t sum = 0;
  for (int i = 0; i < arr_count; i++) {
    if (max < arr[i]) {
      max = arr[i];
    }
    if (min > arr[i]) {
      min = arr[i];
    }
    sum += arr[i];
  }
  int64_t maxSum = sum - min;
  int64_t minSum = sum - max;
  printf("%ld %ld\n", minSum, maxSum);
}

int main() {
  int arr[] = {1, 2, 3, 4, 5};
  miniMaxSum(5, arr);
}
