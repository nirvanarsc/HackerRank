#include <stdio.h>

char* nimbleGame(int s_count, int* s) {
  int sum = 0;
  for (int i = 1; i < s_count; i++) {
    if (s[i] % 2 == 1) {
      sum ^= i;
    }
  }
  return sum == 0 ? "Second" : "First";
}

int main() {
  int arr1[] = {0, 1, 1};
  int arr2[] = {0, 2, 3, 0, 6};
  int arr3[] = {0, 0, 0, 0};

  printf("%s\n", nimbleGame(3, arr1));
  printf("%s\n", nimbleGame(5, arr2));
  printf("%s\n", nimbleGame(4, arr3));
}
