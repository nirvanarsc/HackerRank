#include <stdio.h>
#include <string.h>

int alternatingCharacters(char* s) {
  int l = strlen(s);
  int res = 0;
  int prev = s[0];
  for (int i = 1; i < l; i++) {
    if (s[i] == prev) {
      res++;
    }

    prev = s[i];
  }
  return res;
}

int main() {
  printf("%d\n", alternatingCharacters("AAABBB"));
  printf("%d\n", alternatingCharacters("AAAA"));
}
