#include <stdio.h>
#include <stdlib.h>

int beautifulPairs(int A_count, int* A, int B_count, int* B) {
  int common = 0;

  int* map = calloc(1000, sizeof(int));
  for (int i = 0; i < A_count; i++) {
    map[A[i]]++;
  }

  for (int i = 0; i < B_count; i++) {
    if (map[B[i]] > 0) {
      map[B[i]]--;
      common++;
    }
  }

  if (common == A_count) {
    return common - 1;
  }
  return common + 1;
}

int main() {
  int A[] = {3, 5, 7, 11, 5, 8};
  int B[] = {5, 7, 11, 10, 5, 8};

  printf("%d\n", beautifulPairs(6, A, 6, B));
}
