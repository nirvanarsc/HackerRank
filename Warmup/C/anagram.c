#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int anagram(char* s) {
  int l = strlen(s);

  if (l % 2 == 1) {
    return -1;
  }

  int* lmap = calloc(26, sizeof(int));
  int* rmap = calloc(26, sizeof(int));
  int res = 0;

  for (int i = 0, j = l / 2; i < l / 2; i++, j++) {
    lmap[s[i] - 'a']++;
    rmap[s[j] - 'a']++;
  }

  for (int i = 0; i < 26; i++) {
    res += abs(lmap[i] - rmap[i]);
  }

  return res / 2;
}

int main() {
  printf("%d\n", anagram("aaabbb"));
  printf("%d\n", anagram("ab"));
  printf("%d\n", anagram("abc"));
  printf("%d\n", anagram("mnop"));
  printf("%d\n", anagram("xyyx"));
  printf("%d\n", anagram("xaxbbbxx"));
}
