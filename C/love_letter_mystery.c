#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int theLoveLetterMystery(char* s) {
  int l = strlen(s);
  int res = 0;

  for (int i = 0, j = l - 1; i < l; i++, j--) {
    if (i >= j) {
      break;
    }
    res += abs(s[j] - s[i]);
  }
  return res;
}

int main() {
  printf("%d\n", theLoveLetterMystery("abcba"));
  printf("%d\n", theLoveLetterMystery("abcd"));
}
