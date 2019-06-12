#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char* caesarCipher(char* s, int k) {
  int l = strlen(s);
  char* res = malloc(l * sizeof(char));

  for (int i = 0; i < l; i++) {
    if (65 <= s[i] && s[i] <= 90) {
      res[i] = (s[i] - 'A' + k) % 26 + 'A';
      continue;
    }
    if (97 <= s[i] && s[i] <= 122) {
      res[i] = (s[i] - 'a' + k) % 26 + 'a';
      continue;
    } else
      res[i] = s[i];
  }

  return res;
}

int main() {
  printf("%s\n", caesarCipher("middle-Outz", 2));
  printf("%s\n", caesarCipher("Always-Look-on-the-Bright-Side-of-Life", 5));
}
