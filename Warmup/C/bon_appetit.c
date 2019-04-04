#include <stdio.h>

void bonAppetit(int bill_count, int* bill, int k, int b) {
  int sum = 0;
  for (int i = 0; i < bill_count; i++) {
    if (i != k) {
      sum += bill[i];
    }
  }
  int diff = b - (sum / 2);

  diff != 0 ? printf("%d\n", diff) : printf("Bon Appetit\n");
}

int main() {
  int arr[] = {3, 10, 2, 9};
  int arr_length = sizeof(arr) / sizeof(arr[0]);
  bonAppetit(arr_length, arr, 1, 12);
  bonAppetit(arr_length, arr, 1, 7);
}
