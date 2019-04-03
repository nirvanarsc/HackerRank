#include <stdio.h>
#include <stdlib.h>

int* breakingRecords(int scores_count, int* scores, int* result_count) {
  int best = scores[0];
  int worst = scores[0];
  int plus = 0;
  int minus = 0;

  for (int i = 0; i < scores_count; i++) {
    if (scores[i] > best) {
      best = scores[i];
      plus++;
    }
    if (scores[i] < worst) {
      worst = scores[i];
      minus++;
    }
  }
  result_count[0] = plus;
  result_count[1] = minus;
  return result_count;
}

int main() {
  int* result = (int*)malloc(2 * sizeof(int));
  int scores[] = {10, 5, 20, 20, 4, 5, 2, 25, 1};
  int scores_count = sizeof(scores) / sizeof(scores[0]);

  breakingRecords(scores_count, scores, result);

  printf("%d\n", result[0]);
  printf("%d\n", result[1]);
}
