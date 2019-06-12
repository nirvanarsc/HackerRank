#include <stdio.h>
#include "conveniences.h"

// Complete the migratoryBirds function below.
int migratoryBirds(int arr_count, int* arr) {
  int* map = calloc(5, sizeof(int));
  int max_index = 0;

  for (int i = 0; i < arr_count; i++) {
    map[arr[i] - 1]++;
  }

  for (int j = 0; j < 5; j++) {
    if (map[j] > map[max_index]) {
      max_index = j;
    }
  }

  return max_index + 1;
}

int main() {
  int birds[] = {1, 2, 3, 4, 5, 2, 1, 3, 4, 5, 5};
  int length = sizeof(birds) / sizeof(birds[0]);
  simplePrint(migratoryBirds(length, birds));
}
