#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* pangrams(char* s) {
  int l = strlen(s);
  int* map = calloc(26, sizeof(int));
  for (int i = 0; i < l; i++) {
    if (65 <= s[i] && s[i] <= 90) {
      map[s[i] + ' ' - 'a']++;
      continue;
    }
    map[s[i] - 'a']++;
  }

  for (int i = 0; i < 26; i++) {
    if (map[i] == 0) {
      return "not pangram";
    }
  }

  return "pangram";
}

int main() {
  printf("%s\n", pangrams("The quick brown fox jumps over the lazy dog"));
}
