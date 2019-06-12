#include <stdio.h>
#include <string.h>

int camelcase(char* s) {
  int words = 1;
  int l = strlen(s);
  
  for (int i = 0; i < l; i++) {
    if (65 <= s[i] && s[i] <= 90) {
      words++;
    }
  }

  return words;
}

int main() {
  char* str = "saveChangesInTheEditor";

  printf("%d\n", camelcase(str));
}
