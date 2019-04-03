#include <stdio.h>
#include "conveniences.h"

// Complete the migratoryBirds function below.
int migratoryBirds(int arr_count, int* arr) {
  int* map = calloc(5, sizeof(int));

  for (int i = 0; i < arr_count; i++) {
    simplePrint(arr[i]);
    map[arr[i]]++;
  }

  printf("%d %d %d %d %d\n", arr[0], arr[1], arr[2], arr[3], arr[4]);

  return 0;
}

int main() {
  int zzz[] = {1, 2, 3, 4, 5, 4, 3, 2, 1, 3, 4};
  int length = sizeof(zzz) / sizeof(zzz[0]);
  simplePrint(migratoryBirds(length, zzz));
}
