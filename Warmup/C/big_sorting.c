#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "conveniences.h"

void swap(char** matrix, int i, int j) {
  char* temp = matrix[i];
  matrix[i] = matrix[j];
  matrix[j] = temp;
}

char** bigSorting(int unsorted_count, char** unsorted, int* result_count) {
  *result_count = unsorted_count;

  for (int i = 0; i < unsorted_count; i++) {
    for (int j = 0; j < unsorted_count; j++) {
      int iL = strlen(unsorted[i]);
      int jL = strlen(unsorted[j]);
      if (iL > jL) {
        swap(unsorted, i, j);
        continue;
      }
      if (iL == jL) {
        int k = 0;
        while (k < iL) {
          if (unsorted[i][k] > unsorted[j][k]) {
            swap(unsorted, i, j);
            break;
          }
          k++;
        }
      }
    }
  }

  for (int c = 0; c < unsorted_count / 2; c++) {
    swap(unsorted, c, unsorted_count - 1 - c);
  }

  return unsorted;
}

int main() {
  char** grid = malloc(5 * sizeof(char*));
  for (int i = 0; i < 5; i++) {
    grid[i] = malloc(5 * sizeof(char));
  }

  grid[0] = "123";
  grid[1] = "222";
  grid[2] = "100";
  grid[3] = "200";
  grid[4] = "22";

  int res;

  grid = bigSorting(5, grid, &res);

  simplePrint2dCharArray(grid, 5, 5);
}
