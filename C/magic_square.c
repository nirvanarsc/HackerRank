#include "conveniences.h"

int formingMagicSquare(int s_rows, int s_columns, int** s) {
  int magic_squares[][9] = {
      {8, 1, 6, 3, 5, 7, 4, 9, 2}, {6, 1, 8, 7, 5, 3, 2, 9, 4},
      {8, 3, 4, 1, 5, 9, 6, 7, 2}, {6, 7, 2, 1, 5, 9, 8, 3, 4},
      {4, 3, 8, 9, 5, 1, 2, 7, 6}, {2, 7, 6, 9, 5, 1, 4, 3, 8},
      {4, 9, 2, 3, 5, 7, 8, 1, 6}, {2, 9, 4, 7, 5, 3, 6, 1, 8},
  };

  int* arr = flatten(s_rows, s_columns, s);
  int* costs = calloc(8, sizeof(int));
  int currCost = 0;
  int currIndex = 0;
  int res = 100;

  for (int i = 0; i < 8; i++) {
    for (int j = 0; j < 9; j++) {
      currCost += abs(arr[j] - magic_squares[i][j]);
    }
    costs[currIndex++] = currCost;
    currCost = 0;
  }

  for (int i = 0; i < 8; i++) {
    if (costs[i] < res) {
      res = costs[i];
    }
  }
  return res;
}

int main() {
  int a0[3] = {4, 8, 2};
  int a1[3] = {4, 5, 7};
  int a2[3] = {6, 1, 6};
  int* matrix[3] = {a0, a1, a2};

  simplePrint(formingMagicSquare(3, 3, matrix));
}
