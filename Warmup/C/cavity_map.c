#include "conveniences.h"

char** cavityMap(int grid_count, char** grid, int* result_count) {
  *result_count = grid_count;
  for (int i = 1; i < grid_count - 1; i++) {
    for (int j = 1; j < grid_count - 1; j++) {
      if (grid[i][j] > grid[i][j - 1] && grid[i][j] > grid[i][j + 1] &&
          grid[i][j] > grid[i - 1][j] && grid[i][j] > grid[i + 1][j]) {
        grid[i][j] = 'X';
      }
    }
  }
  return grid;
}

int main() {
  int grid_rows = 4;
  int grid_columns = 4;
  int count = 0;
  char** grid = malloc(grid_rows * sizeof(int*));
  for (int i = 0; i < grid_rows; i++) {
    grid[i] = malloc(grid_columns * sizeof(int));
  }

  char arr[] = {'1', '1', '1', '2', '1', '9', '1', '2',
                '1', '8', '9', '2', '1', '2', '3', '4'};

  populate2dCharArray(grid, grid_rows, grid_columns, arr);
  simplePrint2dCharArray(grid, grid_rows);
  printf("\n");

  cavityMap(grid_rows, grid, &count);
  simplePrint2dCharArray(grid, count);
}
