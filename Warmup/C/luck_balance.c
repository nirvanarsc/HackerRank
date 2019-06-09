#include "conveniences.h"
#include "merge_sort.h"

int luckBalance(int k, int contests_rows, int contests_columns,
                int** contests) {
  int important = 0;
  int sum = 0;

  for (int i = 0; i < contests_rows; i++) {
    important += contests[i][1];
    sum += contests[i][0];
  }

  int mustWin = important - k;

  if (mustWin <= 0) {
    return sum;
  }

  int* map = malloc(important * sizeof(int));
  int index = 0;

  for (int i = 0; i < contests_rows; i++) {
    if (contests[i][1] == 1) {
      map[index++] = contests[i][0];
    }
  }

  mergeSort(map, 0, important - 1);

  for (int i = 0; i < mustWin; i++) {
    sum -= 2 * map[i];
  }

  return sum;
}

int main() {
  int rows = 8;
  int cols = 2;
  int** contests = malloc(rows * sizeof(int*));
  for (int i = 0; i < rows; i++) {
    contests[i] = malloc(cols * sizeof(int));
  }
  int arr[] = {13, 1, 10, 1, 9, 1, 8, 1, 13, 1, 12, 1, 18, 1, 13, 1};
  populate2dArray(contests, rows, cols, arr);

  printf("%d\n", luckBalance(5, rows, cols, contests));
}
