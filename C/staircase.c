#include <stdio.h>

void staircase(int n) {
  for (int x = 0; x < n; x++) {
    int spaces = n - (x + 1);
    int stars = x + 1;
    while (spaces) {
      printf(" ");
      spaces--;
    }
    while (stars) {
      printf("#");
      stars--;
    }
    printf("\n");
  }
}

int main() {
  int i = 6;
  staircase(i);
}
