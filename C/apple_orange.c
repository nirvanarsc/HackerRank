#include <stdio.h>

int compute(int s, int t, int treeLocation, int length, int* fruits) {
  int res = 0;
  for (int i = 0; i < length; i++) {
    if (s <= (fruits[i] + treeLocation) && (fruits[i] + treeLocation) <= t) {
      res++;
    }
  }
  return res;
}

void countApplesAndOranges(int s, int t, int a, int b, int apples_count,
                           int* apples, int oranges_count, int* oranges) {
  printf("%d\n", compute(s, t, a, apples_count, apples));
  printf("%d\n", compute(s, t, b, oranges_count, oranges));
}

int main() {
  int apples[] = {-2, 2, 1};
  int oranges[] = {5, -6};
  countApplesAndOranges(7, 11, 5, 15, 3, apples, 2, oranges);
}
