#include "merge_sort.h"
#include <math.h>
#include <stdio.h>

long marcsCakewalk(int calorie_count, int* calorie) {

  long res = 0;
  mergeSort(calorie, 0, calorie_count - 1);

  for (int i = calorie_count - 1, j = 0; i >= 0; i--, j++) {
    res += calorie[i] * pow(2, j);
  }

  return res;
}

int main() {
  int arr[] = {1, 3, 2};
  int l = sizeof(arr) / sizeof(arr[0]);

  printf("%ld\n", marcsCakewalk(l, arr));
}
