#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* twoStrings(char* s1, char* s2) {
  int l1 = strlen(s1);
  int l2 = strlen(s2);

  int* map = calloc(26, sizeof(int));

  for (int i = 0; i < l1; i++) {
    int idx = s1[i] - 'a';
    if (map[idx] != 1) {
      map[idx] = 1;
    }
  }

  for (int i = 0; i < l2; i++) {
    int idx = s2[i] - 'a';
    if (map[idx] == 1) {
      return "YES";
    }
  }

  return "NO";
}

int main() {
  printf("%s\n", twoStrings("hello", "world"));
  printf("%s\n", twoStrings("hi", "world"));
}
