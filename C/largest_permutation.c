#include <stdio.h>
#include <stdlib.h>

int* largestPermutation(int k, int n, int* arr, int* result_count) {
  *result_count = n;
  int* index = malloc(1000000000 * sizeof(int));
  for (int i = 0; i < n; i++) {
    index[arr[i]] = i;
  }
  for (int i = 0; i < n && k > 0; i++) {
    if (arr[i] == n - i) {
      continue;
    }
    arr[index[n - i]] = arr[i];
    index[arr[i]] = index[n - i];
    arr[i] = n - i;
    index[n - i] = i;
    k--;
  }
  return arr;
}

int main() {
  int arr[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int l;
  int* res = largestPermutation(3, 10, arr, &l);
  for (int i = 0; i < l; i++) {
    printf("%d ", res[i]);
  }
  printf("\n");
}
