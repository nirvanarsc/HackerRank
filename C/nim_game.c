#include <stdio.h>

char* nimGame(int pile_count, int* pile) {
  int sum = 0;
  for (int i = 0; i < pile_count; i++) {
    sum ^= pile[i];
  }
  return sum == 0 ? "Second" : "First";
}

int main() {
  int pile1[] = {1, 1};
  int pile2[] = {2, 1, 4};

  printf("%s\n", nimGame(2, pile1));
  printf("%s\n", nimGame(3, pile2));
}
