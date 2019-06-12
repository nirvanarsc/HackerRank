#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* funnyString(char* s) {
  int l = strlen(s);
  int t = l % 2 == 0 ? l / 2 : l / 2 + 1;

  char* funny = "Funny";
  char* not_funny = "Not Funny";

  for (int i = 0; i < t; i++) {
    if (abs(s[i] - s[i + 1]) != abs(s[l - 1 - i] - s[l - 1 - (i + 1)])) {
      return not_funny;
    }
  }
  return funny;
}

int main() {
  printf("%s\n", funnyString("ivvkxq"));
  printf("%s\n", funnyString("acegikm"));
}
