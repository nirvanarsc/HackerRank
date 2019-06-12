#include <stdbool.h>
#include "conveniences.h"

bool check(char* s, int* k) {
  int length = strlen(s);
  char prev = -1;

  for (int i = 0; i < length; i++) {
    if (s[i] == prev) {
      *k = i;
      return true;
    }
    prev = s[i];
  }

  return false;
}

char* removeIndex(char* s, int i) {
  int length = strlen(s);
  char* new1 = malloc(length * sizeof(char));
  char* new2 = malloc(length * sizeof(char));
  memcpy(new1, s, (i - 1) * sizeof(char));
  memcpy(new2, s + i + 1, (length - i) * sizeof(char));
  strcat(new1, new2);

  return new1;
}

char* superReducedString(char* s) {
  int k;

  while (check(s, &k)) {
    s = removeIndex(s, k);
  }

  return strlen(s) == 0 ? "Empty String" : s;
}

int main() {
  char* string1 = "aabb";
  char* string2 =
      "zztqooauhujtmxnsbzpykwlvpfyqijvdhuhiroodmuxiobyvwwxupqwydkpeebxmfvxhgicu"
      "zdealkgxlfmjiucasokrdznmtlwh";

  printf("%s\n", superReducedString(string1));
  printf("%s\n", superReducedString(string2));
}
