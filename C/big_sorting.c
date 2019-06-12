#include "conveniences.h"

char** temp;

void sort(char** ar, int n) {
  if (n <= 1) return;
  int nl, nh, i, j, k;
  nl = n / 2;
  nh = n - nl;
  sort(ar, nl);
  sort(&(ar[nl]), nh);

  for (k = i = 0, j = nl; i < nl && j < n; k++) {
    int l1 = strlen(ar[i]);
    int l2 = strlen(ar[j]);
    if (l1 < l2 || (l1 == l2 && strcmp(ar[i], ar[j]) < 0))
      temp[k] = ar[i++];
    else
      temp[k] = ar[j++];
  }

  while (i < nl) temp[k++] = ar[i++];

  while (j < n) temp[k++] = ar[j++];

  for (i = 0; i < n; i++) ar[i] = temp[i];
}

char** bigSorting(int unsorted_count, char** unsorted, int* result_count) {
  *result_count = unsorted_count;
  temp = (char**)malloc(unsorted_count * sizeof(char*));
  sort(unsorted, unsorted_count);
  return unsorted;
}

int main() {
  char** grid = malloc(9 * sizeof(char*));
  for (int i = 0; i < 9; i++) {
    grid[i] = malloc(30 * sizeof(char));
  }

  grid[0] = "8";
  grid[1] = "1";
  grid[2] = "2";
  grid[3] = "100";
  grid[4] = "12303479849857341718340192371";
  grid[5] = "3084193741082937";
  grid[6] = "3084193741082938";
  grid[7] = "111";
  grid[8] = "200";

  int res;

  grid = bigSorting(9, grid, &res);

  simplePrint2dCharArray(grid, 9);
}
