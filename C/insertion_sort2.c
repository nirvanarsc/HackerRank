#include <stdio.h>

void printArr(int l, int* arr) {
  for (int i = 0; i < l; i++) {
    printf("%d ", arr[i]);
  }
  printf("\n");
}

void insertionSort2(int n, int arr_count, int* arr) {
  for (int i = 1; i < n; i++) {
    int j = i;
    int value = arr[i];
    while (j >= 1 && arr[j - 1] > value) {
      arr[j] = arr[j - 1];
      j--;
    }
    arr[j] = value;
    printArr(n, arr);
  }
}

int main() {
  int arr[] = {8, 7, 6, 5, 4, 3, 2, 1};
  insertionSort2(8, 8, arr);
}
