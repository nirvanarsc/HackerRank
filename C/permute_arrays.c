#include "merge_sort.h"
#include <stdio.h>

char* twoArrays(int k, int A_count, int* A, int B_count, int* B) {
  mergeSort(A, 0, A_count - 1);
  mergeSort(B, 0, B_count - 1);

  for (int i = 0, j = A_count - 1; i < A_count; i++, j--) {
    if (A[i] + B[j] < k) {
      return "NO";
    }
  }
  return "YES";
}

int main() {
  int A1[] = {2, 1, 3};
  int A2[] = {1, 2, 2, 1};
  int B1[] = {7, 8, 9};
  int B2[] = {3, 3, 3, 4};
  int l1 = sizeof(A1) / sizeof(A1[0]);
  int l2 = sizeof(A2) / sizeof(A2[0]);
  int k1 = 10;
  int k2 = 5;
  printf("%s\n", twoArrays(k1, l1, A1, l1, B1));
  printf("%s\n", twoArrays(k2, l2, A2, l2, B2));
}
