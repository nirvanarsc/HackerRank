#include <stdbool.h>
#include <stdio.h>
#include <string.h>

int palindromeIndex(char *s) {
  int l = strlen(s);

  for (int i = 0, j = l - 1; i < l / 2; i++, j--) {
    if (s[i] != s[j]) {
      if (i + 1 == l / 2) {
        return i;
      }

      for (int a = i, b = j - 1; a < l / 2; a++, b--) {
        if (s[a] != s[b]) {
          return i;
        }
      }

      for (int c = i + 1, d = j; c < l / 2; c++, d--) {
        if (s[c] != s[d]) {
          return j;
        }
      }
    }
  }

  return -1;
}

int main() {
  printf("%d\n", palindromeIndex("aaab"));
  printf("%d\n", palindromeIndex("baa"));
  printf("%d\n", palindromeIndex("aaa"));
  printf("%d\n", palindromeIndex(
                     "mmbiefhflbeckaecprwfgmqlydfroxrblulpasumubqhhbvlqpixvvxip"
                     "qlvbhqbumusaplulbrxorfdylqmgfwrpceakceblfhfeibmm"));
}
