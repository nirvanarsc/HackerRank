#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* gameOfThrones(char* s) {
  int* map = calloc(26, sizeof(int));
  int l = strlen(s);

  for (int i = 0; i < l; i++) {
    map[s[i] - 'a']++;
  }

  bool foundOdd = false;

  for (int i = 0; i < 26; i++) {
    if (foundOdd && map[i] % 2 == 1) {
      return "NO";
    }
    if (map[i] % 2 == 1) {
      foundOdd = true;
    }
  }
  return "YES";
}

int main() {
  printf("%s\n", gameOfThrones("aaabbbb"));
  printf("%s\n", gameOfThrones("cdefghmnopqrstuvw"));
  printf("%s\n", gameOfThrones("cdcdcdcdeeeef"));
}
