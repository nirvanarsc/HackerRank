#include <stdio.h>

// Same as regular Nim game.
char* pokerNim(int k, int s_count, int* s) {
  int sum = 0;
  for (int i = 0; i < s_count; i++) {
    sum ^= s[i];
  }
  return sum == 0 ? "Second" : "First";
}

int main() {
  int arr1[] = {1, 2};
  int arr2[] = {2, 1, 3};

  printf("%s\n", pokerNim(100, 2, arr1));
  printf("%s\n", pokerNim(100, 3, arr2));
}
