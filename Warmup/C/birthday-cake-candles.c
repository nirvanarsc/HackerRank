#include <stdio.h>

void birthdayCakeCandles(int arr_count, int *arr) {
  int max = arr[0];
  int counter = 0;
  for (int i = 0; i < arr_count; i++) {
    if (max < arr[i]) {
      max = arr[i];
    }
  }
  for (int i = 0; i < arr_count; i++) {
    if (arr[i] == max) {
      counter++;
    }
  }

  printf("%d\n", counter);
}

int main() {
  int arr[] = {1, 2, 3, 4, 4, 3, 2};
  int length = sizeof(arr) / sizeof(arr[0]);
  birthdayCakeCandles(length, arr);
}
