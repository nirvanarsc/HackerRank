#include <stdio.h>

void printArr(int l, int* arr) {
  for (int i = 0; i < l; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void insertionSort1(int n, int arr_count, int* arr) {
  int val = arr[arr_count - 1];
  for (int i = arr_count - 2; i >= 0; i--) {
    if (arr[i] > val) {
      arr[i + 1] = arr[i];
    } else {
      arr[i + 1] = val;
      printArr(arr_count, arr);
      break;
    }
    if (arr[0] == arr[1]) {
      printArr(arr_count, arr);
      arr[0] = val;
    }
    printArr(arr_count, arr);
  }
}

int main() {
  int arr[] = {2, 3, 4, 5, 6, 7, 8, 9, 10, 1};
  insertionSort1(10, 10, arr);
}
