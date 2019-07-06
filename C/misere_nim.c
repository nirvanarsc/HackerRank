#include <stdio.h>

char* misereNim(int s_count, int* s) {
  int sum = 0;
  int n = 0;
  for (int i = 0; i < s_count; i++) {
    if (s[i] == 1) {
      n++;
    }
    sum ^= s[i];
  }

  if ((sum != 0 && n == s_count) || (sum == 0 && n != s_count)) {
    return "Second";
  }
  return "First";

  // same as return (sum == (n == s_count))? "Second": "First";
}

int main() {
  int pile1[] = {1, 1};
  int pile2[] = {2, 1, 3};
  int pile3[] = {9, 8, 4, 4, 4, 7};

  printf("%s\n", misereNim(2, pile1));
  printf("%s\n", misereNim(3, pile2));
  printf("%s\n", misereNim(6, pile3));
}
